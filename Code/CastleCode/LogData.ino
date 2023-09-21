/********************************************************
  log data to csv file in sd card
********************************************************/
void logData() {
  //Blink(8, 25, 2);  //blink while logging
  WriteToSD();
  logfile.flush();
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
  }  // Trick to add leading zero for formatting
  logfile.print(now.minute());
  logfile.print(":");
  if (now.second() < 10) {
    logfile.print('0');
  }  // Trick to add leading zero for formatting
  logfile.print(now.second());
  logfile.print(",");

  logfile.print(rtc.getTemperature());
  logfile.print(",");

  logfile.print(millis() / 1000.0000);  // print elapsed time
  logfile.print(",");
  logfile.print(measuredvbat);  // Print battery voltage
  logfile.print(",");

  logfile.print(leftPokeCount);
  logfile.print(",");
  logfile.print(leftPokeDur);
  logfile.print(",");
  logfile.print(rightPokeCount);
  logfile.print(",");
  logfile.print(rightPokeDur);
  logfile.print(",");

  logfile.print(leftFeederCount);
  logfile.print(",");
  logfile.print(leftFeederDur);
  logfile.print(",");
  if (freefeed == true) {
    logfile.println(0);  // freefeed
  } else {
    logfile.println(1);  // fr1
  }
}

/********************************************************
  create new sd file everytime when castle fed is started
  the filename include the current datetime
********************************************************/
void CreateFile() {
  // see if the card is present and can be initialized:
  if (!SD.begin(cardSelect, SD_SCK_MHZ(4))) {
    error(2);
    Serial.println("error 2");
  }

  // Name filename in format F###_MMDDYYNN, where MM is month, DD is day, YY is year, and NN is an incrementing number for the number of files initialized each day
  strcpy(filename, "CASTLE_______________.CSV");  // placeholder filename len(16) // refer to force library, make to right length __ CSL007
  getFilename(filename);
  Serial.print(filename);
  logfile = SD.open(filename, FILE_WRITE);

  if (!logfile) {
    error(3);
  }
  //write header
  logfile.println("Timestamp,Temperature,ElapsedSecs,BatteryVoltage,LeftCount,LeftDur,RightCount,RightDur,LeftFeedCount,LeftFeedDur,FeedParadigm");
  logfile.flush();
  delay(100);
}

/********************************************************
  Read servo position from the csv file stored in the sd
********************************************************/
void CreatePos() {
  if (!SD.begin(cardSelect, SD_SCK_MHZ(4))) {
    error(2);
    Serial.println("in create pos 2");
  }

  ///////////////////////////////////////////////////////////
  configfile = SD.open("CENTER.csv", FILE_WRITE);  // CREATE
  configfile = SD.open("CENTER.csv", FILE_READ);   //READ

  String all = configfile.readString();
  //Serial.println(all);
  int index = all.indexOf(" ");  // how to parse by space here using substring method?
  int index2 = all.indexOf(" ", index + 1);
  int index3 = all.indexOf(" ", index2 + 1);
  int index4 = all.indexOf(" ", index3 + 1);
  int index5 = all.indexOf(" ", index4 + 1);
  int index6 = all.indexOf(" ", index5 + 1);
  mode = all.substring(0, index).toInt();
  open_duration = all.substring(index + 1, index2).toInt();
  CSL = all.substring(index2, index3).toInt();
  on_hour = all.substring(index3, index4).toInt();
  off_hour = all.substring(index4, index5).toInt();
  openpos = all.substring(index5, index6).toInt();
  closedpos = all.substring(index6).toInt();
  configfile.close();
  delay(50);
}

/********************************************************
  print out error message if fail to detect sd card
********************************************************/
void error(uint8_t errno) {
  DisplaySDError();
}

/********************************************************
  Generate filename base on current date and device number
********************************************************/
void getFilename(char *filename) {
  DateTime now = rtc.now();
  filename[7] = CSL / 100 + '0';  // SHOULD allow user to set the device number CSL
  filename[8] = CSL / 10 + '0';
  filename[9] = CSL % 10 + '0';
  filename[11] = now.month() / 10 + '0';
  filename[12] = now.month() % 10 + '0';
  filename[13] = now.day() / 10 + '0';
  filename[14] = now.day() % 10 + '0';
  filename[15] = (now.year() - 2000) / 10 + '0';
  filename[16] = (now.year() - 2000) % 10 + '0';
  for (uint8_t i = 0; i < 100; i++) {
    filename[18] = '0' + i / 10;
    filename[19] = '0' + i % 10;
    if (!SD.exists(filename)) {
      break;
    }
  }
  return;
}

/********************************************************
  Store the posiiton
********************************************************/
void writeConfigFile() {
  configfile = SD.open("CENTER.csv", FILE_WRITE);
  configfile.rewind();
  configfile.print(freefeed);
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
  configfile.println(closedpos);
  configfile.flush();
  configfile.close();
}
