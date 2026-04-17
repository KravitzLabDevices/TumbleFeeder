/*
  ProximityFeeding

  Standalone proximity-based feeding task using a VL6180X Time-of-Flight sensor.

  The feeder stays closed until the mouse approaches and holds within range
  of the proximity sensor for a configurable duration (ProxDur). Once the
  hold requirement is met, the feeder opens for the configured open duration,
  then closes and waits for the mouse to leave before re-arming.

  Startup menu lets you configure:
  - Prox duration (1-10 seconds the mouse must hold near the sensor)
  - Device number (0-19)
  - Open duration (10-120 seconds)
  - Servo open and closed positions

  Events logged to SD card (Event column):
  - "Detected"  : mouse entered sensor range
  - "Opening"   : hold requirement met, feeder opening
  - "Closing"   : open duration expired, feeder closing

  All settings are saved to SD card CONFIG.csv
  Data is automatically logged to TUMBLER_XXX_MMDDYY_NN.CSV

  Requires: Adafruit_VL6180X library (install via Arduino Library Manager)
*/

#include <TumbleFeeder.h>

TumbleFeeder feeder;

void setup() {
  feeder.mode = 4;  // Proximity mode
  feeder.begin();
}

void loop() {
  feeder.run();
}
