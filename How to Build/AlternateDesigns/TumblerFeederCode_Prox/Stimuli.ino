/*****************************************************************
 * FEEDBACK STIMULI - VISUAL AND AUDITORY
 * 
 * This file contains functions for providing feedback to the user
 * or animal through visual (LED) and auditory (piezo beeper) cues.
 * 
 * HARDWARE:
 * - Pin 13 is connected to both:
 *   1. An LED for visual feedback
 *   2. A piezo buzzer/speaker for auditory feedback
 *   3. A MOSFET for servo power control
 * 
 * USAGE:
 * - Blink(): Visual feedback (LED patterns)
 * - Beep(): Auditory feedback (high-pitched tone)
 *****************************************************************/

/*****************************************************************
 * BLINK LED PATTERN
 * 
 * Creates a blinking pattern on any digital output pin. Typically
 * used for visual feedback to indicate errors or status.
 * 
 * PARAMETERS:
 * - PIN: Digital pin number to blink
 * - DELAY_MS: Milliseconds for ON time and OFF time (total period = 2x this)
 * - loops: Number of times to repeat the blink pattern
 * 
 * TIMING:
 * - Each loop: ON for DELAY_MS, then OFF for DELAY_MS
 * - Total duration: loops * DELAY_MS * 2 milliseconds
 * 
 * EXAMPLES:
 * - Blink(13, 50, 3): Fast triple-blink (300ms total)
 * - Blink(8, 100, 5): Medium 5-blink (1000ms total)
 * 
 * TYPICAL USAGE:
 * - Error indication (rapid blinking)
 * - Status confirmation (slow blinking)
 * - SD card activity indicator
 *****************************************************************/
void Blink(byte PIN, byte DELAY_MS, byte loops) {
  for (byte i = 0; i < loops; i++) {
    digitalWrite(PIN, HIGH);   // LED ON
    delay(DELAY_MS);
    digitalWrite(PIN, LOW);    // LED OFF
    delay(DELAY_MS);
  }
}

/*****************************************************************
 * AUDITORY BEEP
 * 
 * Generates a short, high-pitched beep tone using a piezo buzzer.
 * Used for auditory feedback during:
 * - Button presses (confirms user input)
 * - Mouse proximity detection
 * - Menu navigation
 * 
 * TONE GENERATION:
 * Creates a square wave at approximately 1.43 kHz:
 * - HIGH for 250 microseconds
 * - LOW for 450 microseconds
 * - Period = 700 microseconds ≈ 1429 Hz
 * - Repeated 10 times for ~7ms total duration
 * 
 * HARDWARE NOTE:
 * Pin 13 drives a piezo buzzer. The rapid toggling creates an
 * audible tone. The frequency is in the human hearing range
 * (and mice can also hear it).
 * 
 * TIMING: Very short beep (~7ms) for quick, non-intrusive feedback
 *****************************************************************/
void Beep() {
  // Generate 10 cycles of ~1.43 kHz square wave
  for (int i = 0; i < 10; i++) {
    digitalWrite(13, HIGH);      // High half of square wave
    delayMicroseconds(250);
    digitalWrite(13, LOW);       // Low half of square wave
    delayMicroseconds(450);
  }
}
