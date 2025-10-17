/*****************************************************************
 * TUMBLER FEEDER WITH PROXIMITY DETECTION
 * 
 * Main Arduino sketch file
 * 
 * Authors: Lex Kravitz & Yiyan Pan
 * Last Modified: December 3rd, 2024
 * 
 * DESCRIPTION:
 * This is an automated feeding system for behavioral neuroscience
 * experiments with rodents. The system uses a proximity sensor to
 * detect when an animal approaches the feeder, and dispenses food
 * by opening a servo-controlled hopper.
 * 
 * OPERATING MODES:
 * 1. Proximity Mode (mode=0): Food is only available when the animal
 *    stays near the feeder for a configurable duration
 * 2. Free Feeding Mode (mode=1): Food is continuously available
 * 
 * KEY FEATURES:
 * - VL6180X Time-of-Flight proximity sensing
 * - Configurable proximity duration requirement
 * - Data logging to SD card with timestamps
 * - Sharp Memory Display for real-time status
 * - Capacitive touch buttons for configuration
 * - Battery voltage monitoring
 * - Real-time clock for accurate timestamps
 *****************************************************************/

#include "a_header.h"  // All library includes, pin definitions, and global variables

/*****************************************************************
 * SETUP FUNCTION
 * 
 * Runs once at power-on or reset. Initializes all hardware
 * components and displays the configuration menu.
 * 
 * The device stays in the configuration menu until the user
 * presses the red button to start the session.
 *****************************************************************/
void setup() {
  // Initialize all hardware (pins, display, RTC, sensors, SD card)
  startup();
  
  // Display configuration menu and wait for user to start session
  while (!SessionStarted) {
    display_current_params();  // Show current settings and handle button presses
  }
}

/*****************************************************************
 * MAIN LOOP FUNCTION
 * 
 * Runs continuously after setup() completes. This is the main
 * operational loop that:
 * 1. Checks the proximity sensor for animal approach
 * 2. Executes the appropriate feeding logic based on mode
 * 3. Updates the display with current statistics
 *****************************************************************/
void loop() {
  checkProx();        // Read proximity sensor and detect mouse approach
  run();              // Execute feeding logic based on current mode
  update_display();   // Refresh display with counts, time, battery status
}