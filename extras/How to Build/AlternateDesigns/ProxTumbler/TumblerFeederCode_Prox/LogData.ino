/*****************************************************************
 * DATA LOGGING TO SD CARD
 * 
 * This file contains functions for logging experimental data to
 * CSV files on the SD card. Data includes timestamps, sensor
 * readings, event counts, and configuration parameters.
 * 
 * FILE STRUCTURE:
 * - Data files: CASTLE_###_MMDDYY_##.CSV (timestamped)
 * - Config file: CONFIG.csv (stores servo positions and settings)
 * 
 * CSV COLUMNS:
 * Timestamp, Temperature, ElapsedSecs, BatteryVoltage, DeviceNumber,
 * Approaches, OpenCount, FeedParadigm
 *****************************************************************/

/*****************************************************************
 * LOG DATA TO SD CARD
 * 
 * Main logging function called whenever an event occurs (approach,
 * touch, feeding, etc.). Writes current state to SD card and
 * ensures data is physically written.
 * 
 * BEHAVIOR:
 * 1. Calls WriteToSD() to format and write data
 * 2. Flushes buffer to ensure data is written to card
 * 3. Short delay to allow SD card to complete write
 * 
 * TIMING: ~100ms delay per log entry
 * 
 * NOTE: The commented-out Blink() was originally used to provide
 * visual feedback during logging but is disabled to reduce delays.
 *****************************************************************/
void logData() {
  // Blink(8, 25, 2);  // Optional: Visual feedback while logging (disabled)
  WriteToSD();          // Write formatted data to SD card
  logfile.flush();      // Force physical write to SD card
  delay(100);           // Allow SD card write to complete
}

/*****************************************************************
 * WRITE FORMATTED DATA TO SD CARD
 * 
 * Formats and writes a complete data row to the CSV log file.
 * Called by logData() for each event that needs to be recorded.
 * 
 * DATA COLUMNS WRITTEN:
 * 1. Timestamp: MM/DD/YYYY HH:MM:SS from RTC
 * 2. Temperature: From DS3231 RTC's built-in sensor (°C)
 * 3. ElapsedSecs: Time since device powered on (from millis())
 * 4. BatteryVoltage: Current LiPo voltage (V)
 * 5. DeviceNumber: Device ID (CSL variable, 0-19)
 * 6. Approaches: Cumulative proximity detection count
 * 7. OpenCount: Cumulative feeding event count
 * 8. FeedParadigm: Either "FR#" (proximity mode) or "Free" (free feeding)
 * 
 * TIMESTAMP FORMAT:
 * - Date: MM/DD/YYYY (with leading zeros)
 * - Time: HH:MM:SS (with leading zeros)
 * - Example: "03/15/2024 14:05:03"
 *****************************************************************/
void WriteToSD() {
  DateTime now = rtc.now();  // Get current time from RTC
  
  // Write timestamp (MM/DD/YYYY HH:MM:SS)
  logfile.print(now.month());
  logfile.print("/");
  logfile.print(now.day());
  logfile.print("/");
  logfile.print(now.year());
  logfile.print(" ");
  logfile.print(now.hour());
  logfile.print(":");
  if (now.minute() < 10) {
    logfile.print('0');  // Add leading zero for single-digit minutes
  }
  logfile.print(now.minute());
  logfile.print(":");
  if (now.second() < 10) {
    logfile.print('0');  // Add leading zero for single-digit seconds
  }
  logfile.print(now.second());
  logfile.print(",");

  // Write temperature from RTC's built-in sensor
  logfile.print(rtc.getTemperature());
  logfile.print(",");

  // Write elapsed time since power-on (convert milliseconds to seconds)
  logfile.print(millis() / 1000.0000);
  logfile.print(",");
  
  // Write current battery voltage
  logfile.print(measuredvbat);
  logfile.print(",");
  
  // Write device ID number
  logfile.print(CSL);
  logfile.print(",");

  // Write cumulative event counters
  logfile.print(ApproachCount);
  logfile.print(",");
  logfile.print(OpenCount);
  logfile.print(",");
  
  // Write current feeding paradigm/mode
  if (mode == 0) {
    // Proximity mode: include the FR (Fixed Ratio) requirement
    logfile.print("FR");
    logfile.println(ProxRequirement);  // e.g., "FR1", "FR5", etc.
  } else {
    // Free feeding mode
    logfile.println("Free");
  }
}

/*****************************************************************
 * CREATE NEW DATA LOG FILE
 * 
 * Creates a new CSV file on the SD card with a unique timestamped
 * filename. Called once during startup() to initialize logging.
 * 
 * FILENAME FORMAT: CASTLE_###_MMDDYY_##.CSV
 * - CASTLE: Fixed prefix
 * - ###: 3-digit device number (from CSL variable)
 * - MMDDYY: Date (month, day, 2-digit year)
 * - ##: Auto-incrementing session number (00-99)
 * - Example: "CASTLE_003_031524_00.CSV"
 * 
 * FILE STRUCTURE:
 * - Line 1: CSV header row with column names
 * - Line 2+: Data rows (one per logged event)
 * 
 * SAFETY:
 * - fileCreated flag prevents accidental re-creation
 * - If file can't be created, prints error and returns
 * 
 * CSV HEADER:
 * Timestamp,Temperature,ElapsedSecs,BatteryVoltage,DeviceNumber,
 * Approaches,OpenCount,FeedParadigm
 *****************************************************************/
bool fileCreated = false;  // Flag to prevent multiple file creation

void CreateFile() {
  // Safety check: only create file once
  if (fileCreated) {
    Serial.println("File already created, skipping.");
    return;
  }
  
  // Start with template filename (underscores will be replaced with actual values)
  strcpy(filename, "CASTLE______________.CSV");
  getFilename(filename);  // Fill in device#, date, and session# in the filename
  
  Serial.print("Creating file: ");
  Serial.println(filename);

  // Attempt to create/open file for writing
  logfile = SD.open(filename, FILE_WRITE);
  if (!logfile) {
    Serial.println("Failed to open file for writing!");
    return;  // Exit if file creation failed
  }

  // Write CSV header row
  logfile.println("Timestamp,Temperature,ElapsedSecs,BatteryVoltage,DeviceNumber,Approaches,OpenCount,FeedParadigm");
  logfile.flush();  // Ensure header is written immediately
  Serial.println("File created and header written.");

  fileCreated = true;  // Prevent duplicate file creation
}
/*****************************************************************
 * READ CONFIGURATION FROM SD CARD
 * 
 * Reads previously saved configuration from CONFIG.csv file on
 * SD card and restores device settings. This allows the device
 * to remember servo positions, device ID, and other settings
 * across power cycles.
 * 
 * CONFIG FILE FORMAT (space-separated values):
 * mode open_duration CSL on_hour off_hour openpos closedpos ProxRequirement
 * 
 * Example: "0 60 3 0 0 0 150 1"
 * 
 * Called during startup() to restore previous configuration.
 *****************************************************************/
void CreatePos() {
  // Initialize SD card with 4 MHz SPI clock
  if (!SD.begin(cardSelect, SD_SCK_MHZ(4))) {
    error(2);  // Display SD card error
    Serial.println("in create pos 2");
  }

  // Open or create CONFIG.csv file
  configfile = SD.open("CONFIG.csv", FILE_WRITE);  // Create if doesn't exist
  configfile = SD.open("CONFIG.csv", FILE_READ);   // Reopen for reading

  // Read entire file as a string
  String all = configfile.readString();
  
  // Parse space-separated values using substring method
  // Find positions of spaces to separate values
  int index = all.indexOf(" ");              // After mode
  int index2 = all.indexOf(" ", index + 1);  // After open_duration
  int index3 = all.indexOf(" ", index2 + 1); // After CSL
  int index4 = all.indexOf(" ", index3 + 1); // After on_hour
  int index5 = all.indexOf(" ", index4 + 1); // After off_hour
  int index6 = all.indexOf(" ", index5 + 1); // After openpos
  int index7 = all.indexOf(" ", index6 + 1); // After closedpos
  
  // Extract and convert each value from string to integer
  mode = all.substring(0, index).toInt();                    // Operating mode (0=Prox, 1=Free)
  open_duration = all.substring(index + 1, index2).toInt();  // Seconds feeder stays open
  CSL = all.substring(index2, index3).toInt();               // Device ID number (0-19)
  on_hour = all.substring(index3, index4).toInt();           // Active start hour (unused)
  off_hour = all.substring(index4, index5).toInt();          // Active end hour (unused)
  openpos = all.substring(index5, index6).toInt();           // Servo open position (degrees)
  closedpos = all.substring(index6).toInt();                 // Servo closed position (degrees)
  ProxRequirement = all.substring(index7).toInt();           // Proximity duration (seconds)
  
  configfile.close();  // Close file
  delay(50);           // Short delay after file operations
}

/*****************************************************************
 * SD CARD ERROR HANDLER
 * 
 * Called when SD card initialization or access fails.
 * Displays error message on screen and halts operation.
 * 
 * PARAMETERS:
 * - errno: Error code (currently unused, always calls same error display)
 * 
 * The device cannot operate without a working SD card for data
 * logging, so this function halts execution indefinitely.
 *****************************************************************/
void error(uint8_t errno) {
  DisplaySDError();  // Show SD card error on display (halts program)
}

/*****************************************************************
 * GENERATE UNIQUE FILENAME
 * 
 * Fills in the filename template with device number, current date,
 * and auto-incremented session number. Ensures unique filename by
 * checking existing files and incrementing session number.
 * 
 * FILENAME FORMAT: CASTLE_###_MMDDYY_##.CSV
 * - Positions 7-9:   Device number (3 digits, from CSL)
 * - Positions 11-16: Date (MMDDYY)
 * - Positions 18-19: Session number (00-99, auto-incremented)
 * 
 * PARAMETERS:
 * - filename: Pointer to char array to fill (must be pre-allocated)
 * 
 * INPUT TEMPLATE: "CASTLE______________.CSV"
 * OUTPUT EXAMPLE:  "CASTLE_003_031524_00.CSV"
 * 
 * AUTO-INCREMENT:
 * If file already exists, increments session number (00→01→02...)
 * until an unused filename is found (max 100 files per day/device).
 *****************************************************************/
void getFilename(char *filename) {
  DateTime now = rtc.now();  // Get current date/time from RTC
  
  // Fill in device number (3 digits: hundreds, tens, ones)
  filename[7] = CSL / 100 + '0';      // Hundreds digit
  filename[8] = CSL / 10 + '0';       // Tens digit
  filename[9] = CSL % 10 + '0';       // Ones digit
  
  // Fill in date (MMDDYY format)
  filename[11] = now.month() / 10 + '0';           // Month tens
  filename[12] = now.month() % 10 + '0';           // Month ones
  filename[13] = now.day() / 10 + '0';             // Day tens
  filename[14] = now.day() % 10 + '0';             // Day ones
  filename[15] = (now.year() - 2000) / 10 + '0';   // Year tens (2000s)
  filename[16] = (now.year() - 2000) % 10 + '0';   // Year ones
  
  // Auto-increment session number to find unused filename
  for (uint8_t i = 0; i < 100; i++) {
    filename[18] = '0' + i / 10;  // Session number tens digit
    filename[19] = '0' + i % 10;  // Session number ones digit
    
    // Check if this filename already exists
    if (!SD.exists(filename)) {
      break;  // Found unused filename, stop incrementing
    }
  }
  return;
}

/*****************************************************************
 * SAVE CONFIGURATION TO SD CARD
 * 
 * Writes current device settings to CONFIG.csv file on SD card.
 * This preserves settings across power cycles.
 * 
 * Called when user finalizes settings in the configuration menu
 * (after pressing red button to start session).
 * 
 * CONFIG FILE FORMAT (space-separated values):
 * mode open_duration CSL on_hour off_hour openpos closedpos ProxRequirement
 * 
 * SETTINGS SAVED:
 * - mode: Operating mode (0=Proximity, 1=Free)
 * - open_duration: Seconds feeder stays open
 * - CSL: Device ID number
 * - on_hour: Active start hour (for future use)
 * - off_hour: Active end hour (for future use)
 * - openpos: Servo open position (degrees)
 * - closedpos: Servo closed position (degrees)
 * - ProxRequirement: Required proximity duration (seconds)
 *****************************************************************/
void writeConfigFile() {
  configfile = SD.open("CONFIG.csv", FILE_WRITE);  // Open config file
  configfile.rewind();                             // Move to start of file
  
  // Write all settings as space-separated values
  configfile.print(mode);
  configfile.print(" ");
  configfile.print(open_duration);
  configfile.print(" ");
  configfile.print(CSL);
  configfile.print(" ");
  configfile.print(on_hour);
  configfile.print(" ");
  configfile.print(off_hour);
  configfile.print(" ");
  configfile.print(openpos);
  configfile.print(" ");
  configfile.print(closedpos);
  configfile.print(" ");
  configfile.print(ProxRequirement);
  
  configfile.flush();  // Ensure data is written to card
  configfile.close();  // Close file
}