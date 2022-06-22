void logData() {
  Blink(8, 25, 2);  //blink while logging
  WriteToSD();
  logfile.flush();
  delay (100);
}

// Write data to SD
void WriteToSD() {
  logfile.print(millis() / 1000); // Print device name
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
  logfile.print(leftFeederDur);
  logfile.print(",");
  logfile.print(rightFeederCount);
  logfile.print(",");
  logfile.println(rightFeederDur);
}


// Create new file on uSD incrementing file name as required
void CreateFile() {
  // see if the card is present and can be initialized:
  if (!SD.begin(cardSelect, SPI_HALF_SPEED)) {
    error(2);
  }


  


  // Name filename in format F###_MMDDYYNN, where MM is month, DD is day, YY is year, and NN is an incrementing number for the number of files initialized each day
  strcpy(filename, "CASTLE___.CSV");  // placeholder filename
  getFilename(filename);
  logfile = SD.open(filename, FILE_WRITE);

  if ( ! logfile ) {
    error(3);
  }

  //write header
  logfile.println("ElapsedSecs, BatteryVoltage, LeftCount, LeftDur, RightCount, RightDur, LeftFeedCount, LeftFeedDur, RightFeedCount, RightFeedDur");
  logfile.flush();
  delay (100);

 ///////////////////////////////////////////////////////////
  configfile = SD.open("CENTER.csv", FILE_WRITE); // CREATE
  configfile = SD.open("CENTER.csv", FILE_READ); //READ
  middlepos = configfile.parseInt();
  Serial.print("middlepos:");
  Serial.println(middlepos);
  configfile.close();



  
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
  filename[6] = '_';
  filename[9] = '.';
  filename[10] = 'C';
  filename[11] = 'S';
  filename[12] = 'V';
  for (uint8_t i = 0; i < 100; i++) {
    filename[7] = '0' + i / 10;
    filename[8] = '0' + i % 10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(filename)) {
      break;
    }
  }
  return;
}





void writeConfigFile() {
  configfile = SD.open("CENTER.csv", FILE_WRITE);
  configfile.rewind();
  configfile.println(middlepos);
  configfile.flush();
  configfile.close();
} // also write the left and right pos so we don't need to calculate the angle everytime
