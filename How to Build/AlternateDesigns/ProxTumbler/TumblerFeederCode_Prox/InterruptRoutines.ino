/*****************************************************************
 * INTERRUPT SERVICE ROUTINES
 * 
 * This file contains interrupt handler functions that are called
 * automatically by hardware when specific pins change state.
 * These are used for:
 * - Low-power wake-up from sleep mode
 * - Fast response to touch sensor events
 * 
 * Interrupt-enabled pins:
 * - Pin A1: Feeder rod touch sensor (FALLING edge)
 * - Pin A3: Red button (CHANGE - any transition)
 *****************************************************************/

/*****************************************************************
 * FEEDER TOUCH INTERRUPT HANDLER
 * 
 * Called automatically when the feeder rod touch sensor (pin A1)
 * detects a falling edge (HIGH to LOW transition), indicating
 * the mouse has touched the feeding rod.
 * 
 * This is configured in Startup.ino with:
 *   LowPower.attachInterruptWakeup(A1, feed_interrupt, FALLING);
 * 
 * BEHAVIOR:
 * - Sets the feed_touch flag to 1
 * - Wakes the device from sleep mode (if sleeping)
 * - The main loop's checkFeeder() function handles the rest
 * 
 * NOTE: Interrupt handlers should be kept very short and fast.
 * They should only set flags and let main code do the work.
 *****************************************************************/
void feed_interrupt() {
  feed_touch = 1;  // Set flag indicating feeder was touched
}

/*****************************************************************
 * BUTTON INTERRUPT HANDLER
 * 
 * Called automatically when the red button (pin A3) changes state
 * (either pressed or released).
 * 
 * This is configured in Startup.ino with:
 *   LowPower.attachInterruptWakeup(A3, interrupt, CHANGE);
 * 
 * BEHAVIOR:
 * - Currently does nothing (empty function)
 * - Main purpose is to wake device from sleep when button pressed
 * - The main loop handles the actual button logic
 * 
 * NOTE: This interrupt is primarily used for waking from low-power
 * sleep mode. The actual button state is read by read_buttons()
 * in the main loop.
 *****************************************************************/
void interrupt() {
  // Empty - just wake from sleep
  // Button state is handled by read_buttons() in main loop
}