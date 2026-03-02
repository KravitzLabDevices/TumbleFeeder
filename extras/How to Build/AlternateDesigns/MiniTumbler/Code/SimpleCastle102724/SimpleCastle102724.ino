/********************************************************
  Simple Castle
  Written by Lex Kravitz
  Oct 2024

  This is a modification of the Tumble Feeder (https://www.biorxiv.org/content/10.1101/2024.10.01.615599v1) 
  that controls the door based on light level or RTC clock.
  Data is logged to SD card.
  
  This project is released under the terms of the Creative Commons - Attribution - ShareAlike 3.0 license:
  human readable: https://creativecommons.org/licenses/by-sa/3.0/
  legal wording: https://creativecommons.org/licenses/by-sa/3.0/legalcode
  Copyright (c) 2024 Lex Kravitz
  ********************************************************/

#include "a_Header.h"  //See "a_Header.h" for #defines and other constants

void setup() {
  StartUpCommands();
}

void loop() {
  ReadSensors();
  TimedDoor();
  LogData();
  GoToSleep();
}