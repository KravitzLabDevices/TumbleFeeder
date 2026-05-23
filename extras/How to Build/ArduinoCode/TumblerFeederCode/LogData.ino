/********************************************************
  Initialize SD card — called at startup and internally
  by reopenSD(). Sets sdAvailable.
********************************************************/
bool initSD() {
  if (!SD.begin(cardSelect, SD_SCK_MHZ(4))) {
    sdAvailable = false;
    return false;
  }
  sdAvailable = true;
  return true;
}

/********************************************************
  Reconnect to SD mid-session and reopen log file.
  Tries to append to the existing file; if the file is
  gone (different or reformatted card), creates a new one.
********************************************************/
bool reopenSD() {
  if (logfile) logfile.close();

  if (!SD.begin(cardSelect, SD_SCK_MHZ(4))) {
    sdAvailable = false;
    return false;
  }

  if (fileCreated && filename[0] != '\0' && SD.exists(filename)) {
    logfile = SD.open(filename, FILE_WRITE);  // FILE_WRITE = append in SdFat
  } else {
    strcpy(filename, "CASTLE_______________.CSV");
    getFilename(filename);
    logfile = SD.open(filename, FILE_WRITE);
    if (logfile) {
      logfile.println("Timestamp,Temperature,ElapsedSecs,BatteryVoltage,DeviceNumber,LeftCount,LeftDur,RightCount,RightDur,LeftFeedCount,LeftFeedDur,FeedParadigm");
      logfile.flush();
      fileCreated = true;
    }
  }

  sdAvailable = (bool)logfile;
  return sdAvailable;
}

/********************************************************
  log data to csv file in sd card
********************************************************/
void logData() {
  if (!sdAvailable) {
    if (!reopenSD()) {
      delay(100);
      return;
    }
  }
  WriteToSD();
  logfile.flush();
  if (logfile.getWriteError()) {
    logfile.close();
    sdAvailable = false;
  }
  delay(100);
}

/********************************************************
  write datetime, current battery level, leftpoke count, left
  poke duration, right poke count, right poke duration,
  feed count, feed duration, feeding paradigm to sd
********************************************************/
void WriteToSD() {
  DateTime now = rtc.now();
  logfile.print(now.month());
  logfile.print("/");
  logfile.print(now.day());
  logfile.print("/");
  logfile.print(now.year());
  logfile.print(" ");
  logfile.print(now.hour());
  logfile.print(":");
  if (now.minute() < 10) {
    logfile.print('0');
  }
  logfile.print(now.minute());
  logfile.print(":");
  if (now.second() < 10) {
    logfile.print('0');
  }
  logfile.print(now.second());
  logfile.print(",");

  logfile.print(rtc.getTemperature());
  logfile.print(",");

  logfile.print(millis() / 1000.0000);
  logfile.print(",");
  logfile.print(measuredvbat);
  logfile.print(",");
  logfile.print(CSL);
  logfile.print(",");

  logfile.print(leftPokeCount);
  logfile.print(",");
  logfile.print(leftPokeDur);
  logfile.print(",");
  logfile.print(rightPokeCount);
  logfile.print(",");
  logfile.print(rightPokeDur);
  logfile.print(",");

  logfile.print(FeederCount);
  logfile.print(",");
  logfile.print(leftFeederDur);
  logfile.print(",");
  if (mode == 0) {
    logfile.print("FR");
    logfile.println(FR);
  } else {
    logfile.println("Free");
  }
}

/********************************************************
  create new sd file when session is started
********************************************************/
bool fileCreated = false;

void CreateFile() {
  if (fileCreated) return;

  if (!sdAvailable && !initSD()) return;

  strcpy(filename, "CASTLE_______________.CSV");
  getFilename(filename);

  logfile = SD.open(filename, FILE_WRITE);
  if (!logfile) {
    sdAvailable = false;
    return;
  }

  logfile.println("Timestamp,Temperature,ElapsedSecs,BatteryVoltage,DeviceNumber,LeftCount,LeftDur,RightCount,RightDur,LeftFeedCount,LeftFeedDur,FeedParadigm");
  logfile.flush();
  fileCreated = true;
}

/********************************************************
  Read saved settings from CONFIG.csv
********************************************************/
void CreatePos() {
  if (!sdAvailable) return;  // use header defaults if no SD

  configfile = SD.open("CONFIG.csv", FILE_WRITE);
  configfile = SD.open("CONFIG.csv", FILE_READ);

  String all = configfile.readString();
  int index  = all.indexOf(" ");
  int index2 = all.indexOf(" ", index + 1);
  int index3 = all.indexOf(" ", index2 + 1);
  int index4 = all.indexOf(" ", index3 + 1);
  int index5 = all.indexOf(" ", index4 + 1);
  int index6 = all.indexOf(" ", index5 + 1);
  int index7 = all.indexOf(" ", index6 + 1);
  mode         = all.substring(0, index).toInt();
  open_duration = all.substring(index + 1, index2).toInt();
  CSL          = all.substring(index2, index3).toInt();
  on_hour      = all.substring(index3, index4).toInt();
  off_hour     = all.substring(index4, index5).toInt();
  openpos      = all.substring(index5, index6).toInt();
  closedpos    = all.substring(index6).toInt();
  FR           = all.substring(index7).toInt();
  configfile.close();
  delay(50);
}

/********************************************************
  Generate filename based on current date and device number
********************************************************/
void getFilename(char *filename) {
  DateTime now = rtc.now();
  filename[7]  = CSL / 100 + '0';
  filename[8]  = CSL / 10  + '0';
  filename[9]  = CSL % 10  + '0';
  filename[11] = now.month() / 10 + '0';
  filename[12] = now.month() % 10 + '0';
  filename[13] = now.day()   / 10 + '0';
  filename[14] = now.day()   % 10 + '0';
  filename[15] = (now.year() - 2000) / 10 + '0';
  filename[16] = (now.year() - 2000) % 10 + '0';
  for (uint8_t i = 0; i < 100; i++) {
    filename[18] = '0' + i / 10;
    filename[19] = '0' + i % 10;
    if (!SD.exists(filename)) break;
  }
}

/********************************************************
  Store settings to CONFIG.csv
********************************************************/
void writeConfigFile() {
  if (!sdAvailable) return;

  configfile = SD.open("CONFIG.csv", FILE_WRITE);
  configfile.rewind();
  configfile.print(mode);         configfile.print(" ");
  configfile.print(open_duration); configfile.print(" ");
  configfile.print(CSL);          configfile.print(" ");
  configfile.print(on_hour);      configfile.print(" ");
  configfile.print(off_hour);     configfile.print(" ");
  configfile.print(openpos);      configfile.print(" ");
  configfile.print(closedpos);    configfile.print(" ");
  configfile.print(FR);
  configfile.flush();
  configfile.close();
}

/********************************************************
  Error handler — kept for compatibility
********************************************************/
void error(uint8_t errno) {
  DisplaySDError();
}
