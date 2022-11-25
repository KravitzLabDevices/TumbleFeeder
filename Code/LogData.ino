void logData() {
  Blink(8, 25, 2);  //blink while logging
  WriteToSD();
  logfile.flush();
  delay (100);
}

// Write data to SD
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
  }// Trick to add leading zero for formatting
  logfile.print(now.minute());
  logfile.print(":");
  if (now.second() < 10) {
    logfile.print('0');
  }// Trick to add leading zero for formatting
  logfile.print(now.second());
  logfile.print(",");

  logfile.print(rtc.getTemperature());
  logfile.print(",");

  logfile.print(millis() / 1000.0000); // print elapsed time
  logfile.print(",");
  logfile.print(measuredvbat); // Print battery voltage
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
  logfile.println(leftFeederDur);


}


// Create new file on uSD incrementing file name as required
void CreateFile() {
  // see if the card is present and can be initialized:
  if (!SD.begin(cardSelect, SPI_HALF_SPEED)) {
    error(2);
  }





  // Name filename in format F###_MMDDYYNN, where MM is month, DD is day, YY is year, and NN is an incrementing number for the number of files initialized each day
  strcpy(filename, "CASTLE_______________.CSV");  // placeholder filename len(16) // refer to force library, make to right length __ CSL007
  getFilename(filename);
  logfile = SD.open(filename, FILE_WRITE);

  if ( ! logfile ) {
    error(3);
  }

  //write header
  logfile.println("Timestamp,Temperature,ElapsedSecs,BatteryVoltage,LeftCount,LeftDur,RightCount,RightDur,LeftFeedCount,LeftFeedDur");
  logfile.flush();
  delay (100);






}



void CreatePos() {
  if (!SD.begin(cardSelect, SPI_HALF_SPEED)) {
    error(2);
  }

  ///////////////////////////////////////////////////////////
  configfile = SD.open("CENTER.csv", FILE_WRITE); // CREATE
  configfile = SD.open("CENTER.csv", FILE_READ); //READ
  String all = configfile.readString();


  int index = all.indexOf(","); // how to parse by space here using substring method?
  int index2 = all.indexOf(" ");
  int index3 = all.lastIndexOf(" ");
  CSL = all.substring(0, index).toInt();
  
  leftpos = all.substring(index+1,index2).toInt();
  middlepos = all.substring(index2, index3).toInt();
  rightpos = all.substring(index3).toInt();
  configfile.close();
  delay (50);


}

void error(uint8_t errno) {
  while (1) {
    uint8_t i;
    for (i = 0; i < errno; i++) {
      DisplaySDError();
    }
  }
}

void getFilename(char *filename) {
//  filename[6] = '_';
//  filename[9] = '.';
//  filename[10] = 'C';
//  filename[11] = 'S';
//  filename[12] = 'V';
//  for (uint8_t i = 0; i < 100; i++) {
//    filename[7] = '0' + i / 10;
//    filename[8] = '0' + i % 10;
//    // create if does not exist, do not open existing, write, sync after write
//    if (! SD.exists(filename)) {
//      break;
//    }
//  }
//  return;


 DateTime now = rtc.now();

  filename[7] = CSL / 100 + '0'; // SHOULD allow user to set the device number CSL
  filename[8] = CSL / 10 + '0';
  filename[9] = CSL % 10 + '0';
  filename[11] = now.month() / 10 + '0';
  filename[12] = now.month() % 10 + '0';
  filename[13] = now.day() / 10 + '0';
  filename[14] = now.day() % 10 + '0';
  filename[15] = (now.year() - 2000) / 10 + '0';
  filename[16] = (now.year() - 2000) % 10 + '0';
  //filename[20] = '.';
  for (uint8_t i = 0; i < 100; i++) {
    filename[18] = '0' + i / 10;
    filename[19] = '0' + i % 10;

    if (! SD.exists(filename)) {
      break;
    }
  }
  return;
}





void writeConfigFile() {
  configfile = SD.open("CENTER.csv", FILE_WRITE);
  configfile.rewind();
  configfile.print(CSL); // YY changed
  configfile.print(",");
  configfile.print(leftpos); // YY changed
  configfile.print(" ");
  configfile.print(middlepos);
  configfile.print(" ");
  configfile.println(rightpos);
  configfile.flush();
  configfile.close();
} // also write the left and right pos so we don't need to calculate the angle everytime
