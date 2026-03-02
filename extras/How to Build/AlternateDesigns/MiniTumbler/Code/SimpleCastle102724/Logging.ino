/********************************************************
  Write header
********************************************************/
void writeHeader() {
  logfile = SD.open(filename, FILE_WRITE);
  logfile.println("Datetime,Device_Number,Battery_Voltage,Light,DoorOpen");
  logfile.close();
}

/********************************************************
  Log data
********************************************************/
void LogData() {
  if (!SD.begin(chipSelect, SD_SCK_MHZ(4))) {
    Serial.println("Card failed, or not present");
    error();
  }
  digitalWrite(8, HIGH);
  DateTime now = rtc.now();
  // getFilename(filename);
  logfile = SD.open(filename, FILE_WRITE);
  logfile.print(now.month());
  logfile.print('/');
  logfile.print(now.day());
  logfile.print('/');
  logfile.print(now.year());
  logfile.print(" ");
  logfile.print(now.hour());
  logfile.print(':');
  logfile.print(now.minute());
  logfile.print(':');
  logfile.print(now.second());
  logfile.print(",");
  logfile.print(CAS);  // Print device name
  logfile.print(",");
  logfile.print(measuredvbat);
  logfile.print(",");
  logfile.print(lux);  //print lose events
  logfile.print(",");
  logfile.println(doorOpen);  //print door situation
  if (!logfile) {
    error();
  }
  logfile.close();
  digitalWrite(8, LOW);
}

/********************************************************
  If any errors are detected with the SD card, turn on both LEDs
********************************************************/
void error() {
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
}

