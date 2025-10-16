/********************************************************
   HELPER FUNCTION FOR BLINKING ONBOARD LEDS ON FEATHER
 ********************************************************/
void Blink(byte PIN, byte DELAY_MS, byte loops) {
  for (byte i = 0; i < loops; i++) {
    digitalWrite(PIN, HIGH);
    delay(DELAY_MS);
    digitalWrite(PIN, LOW);
    delay(DELAY_MS);
  }
}

void Beep() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(13, HIGH);
    delayMicroseconds(250);
    digitalWrite(13, LOW);
    delayMicroseconds(450);
  }
}
