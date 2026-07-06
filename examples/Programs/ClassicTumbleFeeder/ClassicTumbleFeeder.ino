/*
  ClassicTumbleFeeder

  ── BNC Output (optional) ───────────────────────────────────────────────────
  To use BNC output, solder a BNC connector between Pin 11 (signal) and GND.

  Set BNC_ENABLED to true and choose a BNC_MODE:
    1 = Left touch only   — pin stays HIGH for the duration of the touch
    2 = Right touch only  — pin stays HIGH for the duration of the touch
    3 = Feed touch only   — pin stays HIGH for the duration of the touch
    4 = All three         — fixed-duration pulse per touch type:
                              Left  = 500 ms
                              Right = 800 ms
                              Feed  = 300 ms
  ────────────────────────────────────────────────────────────────────────────

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

  Program 5 - Proximity Feeding
    The feeder opens only when the mouse approaches and holds
    near the proximity sensor for a configurable duration.
    Requires a VL6180X sensor connected via I2C.

  After selecting a program, the settings menu lets you configure:
  - FR value (1-10, FR modes only)
  - Prox duration (1-10 seconds, Proximity mode only)
  - Device number (0-19)
  - Open duration (10-300 seconds)
  - Servo open and closed positions

  All settings are saved to SD card CONFIG.csv
  Data is automatically logged to TUMBLER_XXX_MMDDYY_NN.CSV
*/

#include <TumbleFeeder.h>

// ── BNC Output settings ──────────────────────────────────────────────────────
bool BNC_ENABLED = false;
int  BNC_MODE    = 4;     // 1=left, 2=right, 3=feed, 4=all three
// ─────────────────────────────────────────────────────────────────────────────

TumbleFeeder feeder;

void setup() {
  feeder.bncEnabled = BNC_ENABLED;
  feeder.bncMode    = BNC_MODE;
  feeder.begin();
}

void loop() {
  feeder.run();
}
