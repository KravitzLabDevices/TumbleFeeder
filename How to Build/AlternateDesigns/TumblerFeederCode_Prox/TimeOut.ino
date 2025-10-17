void timeout(int seconds) {
  unsigned long start = millis();
  unsigned long duration = seconds * 1000UL;
  bool on = false;
  unsigned long lastToggle = millis();
  while ((millis() - start) < duration) {
    if ((millis() - lastToggle) >= 500) { // Toggle every 500ms for 1Hz blink
      on = !on;
      lastToggle = millis();
      // Clear area
      display.fillRect(122, 36, 48, 24, WHITE);
      if (on) {
        display.setCursor(122, 48);
        display.println("Timeout");
      }
      display.refresh();
    }
    delay(10); // Small blocking delay
  }
  // Clear "Timeout" at the end
  display.fillRect(122, 36, 48, 24, WHITE);
  display.refresh();
}