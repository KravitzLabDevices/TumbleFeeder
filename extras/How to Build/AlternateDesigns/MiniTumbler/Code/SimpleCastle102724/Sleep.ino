/********************************************************
  Sleep and wakeup
********************************************************/
void GoToSleep() {
  Serial.print("Sleeping...");
  digitalWrite(LED_BUILTIN, LOW);
  LowPower.sleep(sleeptime * 1000);  // wake every X ms
  //delay(sleeptime * 1000);  // wake every X ms
  Serial.println("Awake!");
  digitalWrite(LED_BUILTIN, HIGH);
}
