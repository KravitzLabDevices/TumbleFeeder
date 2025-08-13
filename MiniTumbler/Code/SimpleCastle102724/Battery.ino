/********************************************************
  Read battery voltage
********************************************************/
void ReadBatteryLevel() {
  analogReadResolution(10);  //    Set Analog Read Resolution at 10 bits
  measuredvbat = analogRead(A7);
  measuredvbat *= 2;     // we divided by 2, so multiply back
  measuredvbat *= 3.3;   // Multiply by 3.3V, our reference voltage
  measuredvbat /= 1024;  // convert to voltage
}
