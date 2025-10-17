/*****************************************************************
 * DEVICE INITIALIZATION
 * 
 * This file contains the startup() function which is called once
 * during setup() to initialize all hardware components, sensors,
 * and communication interfaces.
 * 
 * Initialization sequence:
 * 1. Serial communication
 * 2. GPIO pins (inputs/outputs)
 * 3. Interrupt handlers
 * 4. Real-Time Clock (RTC)
 * 5. Proximity sensor (VL6180X)
 * 6. Sharp Memory Display
 * 7. SD card and data logging
 *****************************************************************/

/*****************************************************************
 * STARTUP AND HARDWARE INITIALIZATION
 * 
 * Initializes all hardware components and prepares the device
 * for operation. This function is called once at power-on from
 * the main setup() function.
 * 
 * INITIALIZATION STEPS:
 * 
 * 1. SERIAL COMMUNICATION (9600 baud)
 *    - Used for debugging and status messages
 * 
 * 2. GPIO PIN CONFIGURATION
 *    Outputs:
 *    - Pin 8:  General purpose output
 *    - Pin 10: Servo motor PWM signal
 *    - Pin 11: Pulse output (initialized LOW)
 *    - Pin 12: Mouse/rat control signal
 *    - Pin 13: MOSFET control (servo power, LED, piezo)
 *    
 *    Inputs (with pull-up resistors):
 *    - Pin A0: Spare sensor input
 *    - Pin A1: Feeder rod touch sensor (interrupt-enabled)
 *    - Pin A2: Mouse presence detection
 *    - Pin 1:  Green capacitive touch button
 *    - Pin A3: Red capacitive touch button (interrupt-enabled)
 *    - Pin A5: Blue capacitive touch button
 * 
 * 3. INTERRUPT CONFIGURATION
 *    - A1 (FALLING): Triggers on feeder rod touch
 *    - A3 (CHANGE):  Triggers on red button press/release
 *    Both can wake device from low-power sleep mode
 * 
 * 4. REAL-TIME CLOCK (DS3231)
 *    - Initializes I2C communication with RTC
 *    - RTC maintains accurate time with backup battery
 * 
 * 5. PROXIMITY SENSOR (VL6180X)
 *    - Initializes Time-of-Flight distance sensor
 *    - Halts with error message if sensor not found
 * 
 * 6. SHARP MEMORY DISPLAY
 *    - Initializes 144x168 pixel display
 *    - Sets text size, color, and rotation
 *    - Clears screen to white
 * 
 * 7. SD CARD AND DATA LOGGING
 *    - Registers RTC timestamp callback for file timestamps
 *    - Creates new data log file with timestamped name
 *    - Reads previous configuration from CONFIG.csv
 *****************************************************************/
void startup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  /********************************************************
    CONFIGURE GPIO PINS
  ********************************************************/
  // Output pins
  pinMode(8, OUTPUT);           // General purpose output
  pinMode(10, OUTPUT);          // Servo motor control (PWM)
  pinMode(11, OUTPUT);          // Pulse output
  pinMode(13, OUTPUT);          // MOSFET control (servo power/LED/piezo)
  pinMode(12, OUTPUT);          // Mouse/rat control output
  digitalWrite(11, LOW);        // Initialize pulse output to LOW

  // Input pins with internal pull-up resistors
  // Pull-ups ensure pins read HIGH when not connected/touched
  pinMode(A0, INPUT_PULLUP);    // Spare sensor input
  pinMode(A1, INPUT_PULLUP);    // Feeder rod touch sensor
  pinMode(A2, INPUT_PULLUP);    // Mouse presence detection

  pinMode(1, INPUT_PULLUP);     // Green capacitive button
  pinMode(A3, INPUT_PULLUP);    // Red capacitive button
  pinMode(A5, INPUT_PULLUP);    // Blue capacitive button

  /********************************************************
    ATTACH INTERRUPT HANDLERS FOR LOW-POWER WAKE-UP
  ********************************************************/
  // Interrupt on feeder touch (pin goes HIGH→LOW when touched)
  LowPower.attachInterruptWakeup(A1, feed_interrupt, FALLING);
  
  // Interrupt on red button (any state change)
  LowPower.attachInterruptWakeup(A3, interrupt, CHANGE);

  /********************************************************
    INITIALIZE REAL-TIME CLOCK
  ********************************************************/
  rtc.begin();  // Start I2C communication with DS3231 RTC
  
  /********************************************************
    INITIALIZE VL6180X PROXIMITY SENSOR
  ********************************************************/
  if (!vl.begin()) {
    // Sensor not found - print error and halt
    Serial.println("Failed to find sensor");
    while (1);  // Infinite loop - device cannot operate without sensor
  }
  Serial.println("VL6180 Sensor found!");

  /********************************************************
    INITIALIZE SHARP MEMORY DISPLAY
  ********************************************************/
  display.begin();                              // Initialize display hardware
  display.setTextSize(1);                       // Use smallest text size
  display.setTextColor(BLACK);                  // Black text on white background
  display.setRotation(1);                       // Landscape orientation
  display.fillRect(0, 0, 168, 144, WHITE);      // Clear screen
  Serial.println("Prox tumbler starting up...");

  /********************************************************
    INITIALIZE SD CARD AND DATA LOGGING
  ********************************************************/
  // Register callback so SD card files get accurate timestamps from RTC
  SdFile::dateTimeCallback(dateTime);
  
  // Create new data log file with timestamped filename
  CreateFile();
  
  // Read previous configuration (servo positions, device ID, etc.)
  CreatePos();
}
