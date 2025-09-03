void StartUpCommands() {
  /********************************************************
    Start serial connection (this will disconnect after the first sleep)
  ********************************************************/
  Serial.begin(115200);
  Serial.println("Starting up...  Welcome to Mini Tumbler World");

  /********************************************************
    Start servo
  ********************************************************/
  myservo.attach(A0);            // attaches the servo on pin 10 to the servo object
  pinMode(8, OUTPUT);            // GREEN LED
  pinMode(11, OUTPUT);           // SERVO POWER
  pinMode(LED_BUILTIN, OUTPUT);  // RED LED

  /********************************************************
    Start RTC
  ********************************************************/
  rtc.begin();

  /********************************************************
    Start SD card, create Data File for current session
  ********************************************************/
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect, SD_SCK_MHZ(4))) {
    Serial.println("Card failed, or not present");
  }

  Serial.println("card initialized.");

  /********************************************************
    Generate a unique filename
    // (code below from: https://forum.arduino.cc/index.php?topic=372248.0)
  ********************************************************/
  int n = 0;
  DateTime now = rtc.now();
  snprintf(filename, sizeof(filename), "FEED%03d_%02d%02d%02d_%02d.csv", CAS, now.month(), now.day(), now.year() - 2000, n);
  while (SD.exists(filename)) {
    n++;
    snprintf(filename, sizeof(filename), "FEED%03d_%02d%02d%02d_%02d.csv", CAS, now.month(), now.day(), now.year() - 2000, n);
  }

  SdFile::dateTimeCallback(dateTime);  //added this line so the files on the SD card have the correct date and time
  Serial.print("New file created: ");
  Serial.println(filename);
  writeHeader();
  Serial.println("Logfile initialized");

  open_door();
  close_door();
}

//  dateTime function to help put correct dates/time for windows
void dateTime(uint16_t* date, uint16_t* time) {
  DateTime now = rtc.now();
  // return date using FAT_DATE macro to format fields
  *date = FAT_DATE(now.year(), now.month(), now.day());

  // return time using FAT_TIME macro to format fields
  *time = FAT_TIME(now.hour(), now.minute(), now.second());
}