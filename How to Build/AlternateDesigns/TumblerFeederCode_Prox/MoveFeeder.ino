/*****************************************************************
 * FEEDER MOVEMENT CONTROL
 * 
 * This file contains functions for controlling the servo motor
 * that opens and closes the food hopper, as well as functions
 * for shaking the hopper to prevent food from clumping.
 * 
 * SERVO CONTROL:
 * - Connected to pin 10
 * - MOSFET on pin 13 controls servo power
 * - Servo is detached when not moving to save power and prevent jitter
 * 
 * MOVEMENT STRATEGY:
 * - Slow, gradual movement (1 degree at a time with 50ms delay)
 * - Prevents sudden jolts that could scare the animal
 * - Reduces mechanical stress on the servo
 *****************************************************************/

/*****************************************************************
 * OPEN FEEDER DOOR
 * 
 * Gradually opens the servo-controlled feeder door from the closed
 * position to the open position. Movement is slow and smooth to
 * avoid startling the animal.
 * 
 * PARAMETERS:
 * - openpos: Target servo angle for fully open position (degrees)
 * 
 * PROCESS:
 * 1. Enable servo power via MOSFET (pin 13)
 * 2. Attach servo to control pin
 * 3. Move 1 degree at a time from closedpos down to openpos
 * 4. Detach servo to prevent jitter and save power
 * 5. Disable servo power
 * 
 * TIMING: ~50ms per degree of movement
 * For typical range (150° to 0°), takes ~7.5 seconds
 *****************************************************************/
void feeder_open(int openpos) {
  display.setCursor(0, 0);
  display.refresh();
  
  digitalWrite(13, HIGH);   // Enable servo power via MOSFET
  myservo.attach(10);       // Attach servo to control pin
  
  // Gradually move servo from closed to open position
  for (int pos = closedpos; pos >= openpos; pos -= 1) {
    myservo.write(pos);     // Set servo angle
    delay(50);              // Wait for servo to reach position
  }
  
  myservo.detach();         // Detach to prevent jitter and save power
  digitalWrite(13, LOW);    // Disable servo power
}

/*****************************************************************
 * CLOSE FEEDER DOOR
 * 
 * Gradually closes the servo-controlled feeder door from the open
 * position to the closed position. Movement is slow and smooth.
 * 
 * PARAMETERS:
 * - closedpos: Target servo angle for fully closed position (degrees)
 * 
 * PROCESS:
 * 1. Enable servo power via MOSFET (pin 13)
 * 2. Attach servo to control pin
 * 3. Move 1 degree at a time from openpos up to closedpos
 * 4. Detach servo to prevent jitter and save power
 * 5. Disable servo power
 * 
 * TIMING: ~50ms per degree of movement
 * For typical range (0° to 150°), takes ~7.5 seconds
 *****************************************************************/
void feeder_close(int closedpos) {
  display.setCursor(0, 0);
  display.refresh();
  
  digitalWrite(13, HIGH);   // Enable servo power via MOSFET
  myservo.attach(10);       // Attach servo to control pin
  
  // Gradually move servo from open to closed position
  for (int pos = openpos; pos <= closedpos; pos += 1) {
    myservo.write(pos);     // Set servo angle
    delay(50);              // Wait for servo to reach position
  }
  
  myservo.detach();         // Detach to prevent jitter and save power
  digitalWrite(13, LOW);    // Disable servo power
}

/*****************************************************************
 * SHAKE/VIBRATION PATTERN
 * 
 * Creates a rapid on/off pulse pattern on pin 13. This can be
 * used to create vibration/shaking or audible feedback.
 * 
 * BEHAVIOR:
 * - 10 pulses at 10 Hz (100ms period)
 * - Each pulse is 50ms ON, 50ms OFF
 * - Total duration: 1 second
 * 
 * This function is called by shake_food() to help prevent food
 * from sticking or clumping in the hopper.
 *****************************************************************/
void shake() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(13, HIGH);   // Pulse ON
    delay(50);
    digitalWrite(13, LOW);    // Pulse OFF
    delay(50);
  }
}

/*****************************************************************
 * SHAKE FOOD HOPPER
 * 
 * Performs a shaking sequence to prevent food from clumping or
 * sticking in the hopper. Used in free feeding mode as periodic
 * maintenance (every 180 wake cycles).
 * 
 * SEQUENCE:
 * 1. Perform shake vibration pattern
 * 2. Close feeder door (if open)
 * 3. Open feeder door
 * 4. Log the event to SD card
 * 
 * The close/open movement helps dislodge any stuck food pellets.
 *****************************************************************/
void shake_food() {
  shake();                      // Create vibration/pulse pattern
  feeder_close(closedpos);      // Close door
  feeder_open(openpos);         // Open door
  logData();                    // Log the maintenance event
}
