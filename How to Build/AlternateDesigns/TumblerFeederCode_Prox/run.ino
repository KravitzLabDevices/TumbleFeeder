/*****************************************************************
 * MAIN RUN FUNCTION
 * 
 * This file contains the main operational logic that routes
 * execution to the appropriate mode-specific functions based on
 * the current operating mode (Proximity or Free feeding).
 * 
 * Called continuously from loop() in the main .ino file.
 *****************************************************************/

/*****************************************************************
 * RUN DEVICE BASED ON MODE
 * 
 * Routes execution to the appropriate input checking functions
 * based on the current operating mode. Also handles periodic
 * display updates and food shaking (in free mode).
 * 
 * OPERATING MODES:
 * - Mode 0 (Proximity): Food only available when mouse approaches
 *   and stays near the feeder for ProxRequirement seconds
 * - Mode 1 (Free): Food continuously available, device logs
 *   approaches and touches
 * 
 * DISPLAY UPDATE TIMING:
 * Uses next_interval to manage display refresh rate without
 * blocking operations. Display updates occur every display_interval
 * milliseconds (default 100ms).
 * 
 * FOOD SHAKING (Free Mode Only):
 * Every 180 wake cycles, the device shakes the food hopper to
 * prevent food from clumping. This happens automatically in
 * free feeding mode.
 *****************************************************************/
void run() {
  unsigned long current = millis();  // Get current time for display timing

  if (mode == 0) {
    // PROXIMITY MODE
    // Check for mouse proximity and feeder touches
    // Food is only dispensed when mouse stays near feeder
    check_inputs(closedpos, openpos, open_duration);
    
    // Update display at regular intervals
    if (current >= next_interval) {
      next_interval = current + display_interval;
    }
  }
  else if (mode == 1) {
    // FREE FEEDING MODE
    // Food is continuously available, just log events
    free_inputs(closedpos, openpos);
    
    // Update display and handle periodic food shaking
    if (current >= next_interval) {
      next_interval = current + display_interval;
      
      // Shake food every 180 wake cycles to prevent clumping
      if (wake_counter % 180 == 0) {
        shake_food();
      }
    }
  }
}
