void checkProx() {
  uint8_t range = vl.readRange();
  uint8_t status = vl.readRangeStatus();
  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Range: ");
    Serial.println(range);
  }
  delay(100);

  left_touch = 0;

  //If mouse is close to feeder
  if (range < 30) {
    left_touch = 1;
  }
}