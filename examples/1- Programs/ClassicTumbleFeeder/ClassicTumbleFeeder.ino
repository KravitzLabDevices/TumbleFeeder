/*
  ClassicTumbleFeeder

  At startup, use the buttons to select a program:
    Red  = cycle between programs
    Blue = confirm selection

  Program 1 - Free Feeding
    The feeder stays open and shakes periodically.

  Program 2 - Fixed Ratio (FR)
    The feeder opens after a set number of left pokes.

  Program 3 - FR Extend
    Like FR, but each feeder touch extends the open timer by 10s.

  Program 4 - Free Terminate
    The feeder stays open, but touching the feeder closes it
    for 60 seconds before it reopens.

  After selecting a program, the settings menu lets you configure:
  - FR value (1-10)
  - Device number (0-19)
  - Open duration (10-120 seconds)
  - Servo open and closed positions

  All settings are saved to SD card CONFIG.csv
  Data is automatically logged to TUMBLER_XXX_MMDDYY_NN.CSV
*/

#include <TumbleFeeder.h>

TumbleFeeder feeder;

void setup() {
  feeder.begin();
}

void loop() {
  feeder.run();
}
