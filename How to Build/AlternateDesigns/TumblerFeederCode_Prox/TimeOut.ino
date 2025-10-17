/*****************************************************************
 * TIMEOUT FUNCTION
 * 
 * This file contains the timeout function that creates a delay
 * period with visual feedback on the display. Used after feeding
 * events to ensure the mouse has left the feeder area before
 * the door closes.
 *****************************************************************/

/*****************************************************************
 * TIMEOUT WITH VISUAL FEEDBACK
 * 
 * Creates a blocking delay of specified duration while displaying
 * a blinking "Timeout" message on the screen. This provides visual
 * feedback that the system is waiting for the mouse to leave.
 * 
 * Called after feeding periods to ensure the mouse has moved away
 * from the feeder before closing the servo-controlled door.
 * 
 * PARAMETERS:
 * - seconds: Duration of timeout period in seconds
 * 
 * DISPLAY BEHAVIOR:
 * - Message blinks at 1 Hz (on 500ms, off 500ms)
 * - Displayed in area (122, 36) with size (48, 24)
 * - Message is cleared when timeout completes
 * 
 * NOTE: This is a blocking function - the device will not respond
 * to other inputs during the timeout period.
 *****************************************************************/
void timeout(int seconds) {
  unsigned long start = millis();              // Record start time
  unsigned long duration = seconds * 1000UL;   // Convert seconds to milliseconds
  bool on = false;                             // Track blink state
  unsigned long lastToggle = millis();         // Track last blink toggle time
  
  // Loop until timeout duration has elapsed
  while ((millis() - start) < duration) {
    // Toggle display every 500ms (1 Hz blink rate)
    if ((millis() - lastToggle) >= 500) {
      on = !on;                   // Toggle blink state
      lastToggle = millis();      // Reset toggle timer
      
      // Clear the display area
      display.fillRect(122, 36, 48, 24, WHITE);
      
      // Show "Timeout" text during ON phase of blink
      if (on) {
        display.setCursor(122, 48);
        display.println("Timeout");
      }
      display.refresh();
    }
    delay(10);  // Small delay to prevent excessive CPU usage
  }
  
  // Clear "Timeout" message when timeout completes
  display.fillRect(122, 36, 48, 24, WHITE);
  display.refresh();
}