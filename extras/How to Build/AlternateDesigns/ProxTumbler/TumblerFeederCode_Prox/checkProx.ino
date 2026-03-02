/*****************************************************************
 * PROXIMITY SENSOR CHECKING
 * 
 * This file contains the function that reads the VL6180X Time-of-Flight
 * proximity sensor to detect when a mouse approaches the feeder.
 * 
 * The sensor measures distance in millimeters. When an object (mouse)
 * is detected within 30mm and stays there for the required duration,
 * the mouse_detected flag is set, triggering a feeding event.
 *****************************************************************/

/*****************************************************************
 * CHECK PROXIMITY SENSOR
 * 
 * Reads the VL6180X proximity sensor and determines if a mouse
 * is approaching the feeder. If a mouse is detected within range
 * (< 30mm), it must stay there for ProxRequirement seconds to
 * trigger a feeding event.
 * 
 * LOGIC:
 * 1. Skip if already processing a detection
 * 2. Read distance from sensor
 * 3. If within 30mm threshold:
 *    - Play confirmation beep
 *    - Increment approach counter
 *    - Start timer and continuously check if mouse stays
 *    - Set mouse_detected flag if duration requirement is met
 *    - Clear flag if mouse leaves before duration is met
 * 
 * GLOBALS MODIFIED:
 * - mouse_detected: Set to 1 when mouse stays near feeder
 * - ApproachCount: Incremented each time mouse approaches
 *****************************************************************/
void checkProx() {
  // Don't check proximity if we're already processing a mouse detection
  // This prevents re-triggering while handling a feeding event
  if (mouse_detected == 1) {
    return;
  }
  
  // Read distance from VL6180X sensor (in millimeters)
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();
  
  // Only process valid readings (no sensor errors)
  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Range: ");
    Serial.println(range);
  }
  delay(100);  // Short delay between readings

  // Check if mouse is within detection range (< 30mm from sensor)
  if (range < 30) {
    Beep();  // Audible feedback that mouse was detected
    Serial.println("Mouse detected.");
    mouse_detected = 1;        // Set detection flag
    ApproachCount++;           // Increment approach counter

    // Start proximity duration timer
    // Mouse must stay near feeder for ProxRequirement seconds
    unsigned long startProx = millis();
    
    // Continuously check if mouse stays within range for required duration
    while ((millis() - startProx) < (ProxRequirement * 1000)) {
      uint8_t range = vl.readRange();  // Re-read distance
      uint8_t status = vl.readRangeStatus();
      
      Serial.print("Range: ");
      Serial.print(range);
      Serial.print(", mouse_detected: ");
      Serial.println(mouse_detected);
      
      delay(100);  // Check every 100ms
      
      // If mouse moves away (> 29mm), cancel the detection
      if (range > 29) {
        mouse_detected = 0;  // Clear detection flag
        Serial.println("Mouse left feeder!");
        break;  // Exit the duration checking loop
      }
    }
    
    // If we exit the while loop naturally (not via break),
    // mouse_detected remains 1 and feeding will be triggered
  }
}