/*****************************************************************
 * INPUT CHECKING AND FEEDING LOGIC
 * 
 * This file contains functions that check various inputs (touch sensors,
 * proximity detection) and execute the appropriate feeding behaviors
 * based on the current operating mode.
 * 
 * Key input sensors:
 * - Pin A1: Capacitive touch sensor on feeding rod
 * - Pin A2: Mouse presence detection (used in free mode)
 * - VL6180X proximity sensor (handled in checkProx.ino)
 *****************************************************************/

/*****************************************************************
 * READ BUTTON STATES
 * 
 * Reads the current state of all three capacitive touch buttons.
 * These buttons are used for menu navigation and configuration.
 * 
 * Button states: LOW = pressed, HIGH = not pressed
 *****************************************************************/
void read_buttons() {
  red_touch = digitalRead(A3);    // Red button (start/reset)
  green_touch = digitalRead(1);   // Green button (back/cancel)
  blue_touch = digitalRead(A5);   // Blue button (next/edit)
}

/*****************************************************************
 * FREE FEEDING MODE INPUT HANDLER
 * 
 * Processes inputs when in free feeding mode (mode=1).
 * In this mode, food is continuously available and the device
 * just logs when the mouse approaches or touches the feeder.
 * 
 * PARAMETERS:
 * - closedpos: Servo angle when closed (not used in this function)
 * - openpos: Servo angle when open (not used in this function)
 * 
 * BEHAVIOR:
 * - Continuously checks for feeder rod touches
 * - When mouse is detected by proximity sensor:
 *   - Waits for mouse to leave (A2 goes HIGH)
 *   - Increments counter and logs the event
 *****************************************************************/
void free_inputs(int closedpos, int openpos) {
  checkFeeder();  // Check if mouse touched feeder rod

  // Process proximity detection in free feeding mode
  if (mouse_detected == 1) {
    unsigned long startTime = millis();  // Start time for event timing
    
    // Wait for mouse to leave the feeder area (A2 returns HIGH)
    while (digitalRead(A2) == LOW) {
      delay(1);  // Small delay to prevent tight loop
    }
    
    FeederCount++;      // Increment feeding event counter
    update_display();   // Update display with new count
    logData();          // Log event to SD card
    mouse_detected = 0; // Clear detection flag
  }
}

/*****************************************************************
 * PROXIMITY MODE INPUT HANDLER
 * 
 * Main input checking function for proximity mode (mode=0).
 * Coordinates checking both proximity detection and feeder touches.
 * 
 * PARAMETERS:
 * - closedpos: Servo angle when feeder is closed
 * - openpos: Servo angle when feeder is open
 * - open_duration: How long to keep feeder open (seconds)
 *****************************************************************/
void check_inputs(int closedpos, int openpos, unsigned long open_duration) {
  checkMousePresent(closedpos, openpos, open_duration);  // Handle proximity detection
  checkFeeder();                                         // Handle feeder rod touches
}

/*****************************************************************
 * HANDLE MOUSE PROXIMITY DETECTION
 * 
 * Called when the proximity sensor detects a mouse that has stayed
 * near the feeder for the required duration. This function opens
 * the feeder for a timed period, monitors for touches during that
 * period, then closes the feeder.
 * 
 * PARAMETERS:
 * - closedpos: Servo angle when feeder is closed
 * - openpos: Servo angle when feeder is open
 * - open_duration: How long to keep feeder open (seconds)
 * 
 * SEQUENCE:
 * 1. Increment counter and log the approach
 * 2. Open the servo-controlled feeder
 * 3. Keep open for open_duration seconds while:
 *    - Checking for feeder rod touches
 *    - Displaying countdown timer on screen
 * 4. 5-second timeout period to ensure mouse has left
 * 5. Close the feeder
 * 6. Clear mouse_detected flag
 *****************************************************************/
void checkMousePresent(int closedpos, int openpos, unsigned long open_duration) {
  if (mouse_detected == 1) {
    // Log the feeding opportunity
    FeederCount++;
    update_display();
    logData();
    
    // Open the feeder door
    feeder_open(openpos);
    
    // Start timer for feeder open period
    unsigned long feederStart = millis();
    
    // Keep feeder open for specified duration
    while (millis() - feederStart < (open_duration * 1000)) {
      checkFeeder();  // Continue checking for feeder rod touches during open period
      
      // Display "Feeding" status and countdown timer
      display.fillRect(122, 36, 28, 24, WHITE);  // Clear display area
      display.setCursor(122, 48);
      display.println("Feeding");
      display.setCursor(122, 60);
      // Show remaining seconds
      display.print(((open_duration * 1000) - (millis() - feederStart)) / 1000);
      display.refresh();
      
      update_display();  // Update other display elements (counters, time, battery)
    }
    
    // 5-second timeout to ensure mouse has left before closing
    timeout(5);
    
    // Clear the "Feeding" message
    display.fillRect(122, 36, 28, 24, WHITE);
    
    // Close the feeder door
    feeder_close(closedpos);
    
    // Clear mouse detection flag to allow next detection
    mouse_detected = 0;
  }
}

/*****************************************************************
 * CHECK FEEDER ROD TOUCH SENSOR
 * 
 * Monitors the capacitive touch sensor on the feeding rod (pin A1).
 * When the mouse touches the feeder rod, this function measures
 * the touch duration and logs the event.
 * 
 * The sensor uses a capacitive touch detection circuit connected
 * to pin A1 with internal pull-up. When touched, the pin goes LOW.
 * 
 * BEHAVIOR:
 * - Checks if feed_touch flag is set (by interrupt handler)
 * - Waits for touch to end (A1 returns HIGH)
 * - Calculates touch duration
 * - Increments counter and logs event
 * 
 * GLOBALS MODIFIED:
 * - FeederCount: Incremented for each touch
 * - FeederDur: Set to touch duration in milliseconds
 * - feed_touch: Reset to 0 after processing
 *****************************************************************/
void checkFeeder() {
  if (feed_touch == 1) {
    unsigned long startTime = millis();  // Record when touch started
    
    // Wait for touch to end (pin returns HIGH)
    while (digitalRead(A1) == LOW) {
      delay(1);  // Small delay to prevent tight loop
    }
    
    FeederCount++;                      // Increment touch counter
    FeederDur = millis() - startTime;   // Calculate touch duration in milliseconds
    update_display();                   // Update display with new count

    // Log the touch event with timestamp and duration
    logData();
    
    // Reset touch flag and duration for next event
    feed_touch = 0;
    FeederDur = 0;
  }
}