/*
  ClassicTumbleFeeder
  
  The simplest way to use TumbleFeeder - just two lines!
  
  This is all you need! The library handles everything:
  - Pin initialization
  - RTC setup
  - Display management
  - SD card logging
  - Startup menu
  - Input checking
  - Sleep management
  
  Hardware:
  - Servo on pin 10
  - LED on pin 13
  - Left touch on A2
  - Right touch on A0
  - Feeder touch on A1
  - Sharp display on pins 5, A4, 6
  - SD card on pin 4
  - Red/Green/Blue buttons on A3, 1, A5
*/

#include <TumbleFeeder.h>

TumbleFeeder feeder;

void setup() {
  feeder.begin();
}

void loop() {
  feeder.run();
}

/*
  The startup menu lets you configure:
  - Mode (FR or Free feeding)
  - FR value (1-10)
  - Device number (0-19)
  - Open duration (10-120 seconds)
  - Servo open position
  - Servo closed position
  
  All settings are saved to SD card CONFIG.csv
  Data is automatically logged to TUMBLER_XXX_MMDDYY_NN.CSV
*/
