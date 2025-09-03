/********************************************************
  Read photoresistor and battery level
********************************************************/
void ReadSensors() {
  lux = analogRead(A3);
  Serial.print("Lux: ");
  Serial.println(lux);
  ReadBatteryLevel();
}
