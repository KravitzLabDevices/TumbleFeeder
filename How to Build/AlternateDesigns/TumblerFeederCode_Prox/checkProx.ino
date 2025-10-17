void checkProx() {
  // Don't check proximity if we're already processing a touch
  if (mouse_detected == 1) {
    return;
  }
  
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();
  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Range: ");
    Serial.println(range);
  }
  delay(100);

  //if mouse approaches feeder
  if (range < 30) {
    Beep();
    Serial.println("Mouse detected.");
    mouse_detected = 1;
    ApproachCount++;

    //start a timer
    unsigned long startProx = millis();
    // keep ranging to check if mouse is still there
    while ((millis() - startProx) < (FR * 1000)) {
      uint8_t range = vl.readRange();
      uint8_t status = vl.readRangeStatus();
      Serial.print("Range: ");
      Serial.print(range);
      Serial.print(", mouse_detected: ");
      Serial.println(mouse_detected);
      delay(100);
      //If mouse leaves feeder
      if (range > 29) {
        mouse_detected = 0;
        Serial.println ("Mouse left feeder!");
        break;
      }
    }
  }
}