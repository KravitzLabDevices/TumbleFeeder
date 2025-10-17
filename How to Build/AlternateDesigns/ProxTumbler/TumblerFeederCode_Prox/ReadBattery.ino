/*****************************************************************
 * BATTERY VOLTAGE MONITORING
 * 
 * This file contains the function for reading the LiPo battery
 * voltage level. Many Adafruit Feather boards have a built-in
 * battery voltage divider circuit that allows monitoring the
 * battery level while it's connected.
 * 
 * The voltage divider uses two equal resistors (typically 100K each)
 * to divide the battery voltage by 2 before feeding it to the ADC.
 *****************************************************************/

/*****************************************************************
 * READ BATTERY VOLTAGE
 * 
 * Reads the LiPo battery voltage from pin A7 (VBATPIN) and
 * converts the ADC reading to actual voltage.
 * 
 * CONVERSION PROCESS:
 * 1. Read 10-bit ADC value (0-1023) from voltage divider
 * 2. Multiply by 2 (voltage divider has 2 equal resistors)
 * 3. Multiply by 3.3V (ADC reference voltage)
 * 4. Divide by 1024 (10-bit ADC resolution)
 * 
 * Result is stored in global variable measuredvbat.
 * 
 * TYPICAL LIPO VOLTAGES:
 * - Fully charged: ~4.2V
 * - Normal operation: 3.7V - 4.0V
 * - Low battery: < 3.5V
 * - Discharged: ~3.0V (should recharge before this)
 * 
 * GLOBALS MODIFIED:
 * - measuredvbat: Updated with current battery voltage
 *****************************************************************/
void ReadBatteryLevel() {
  measuredvbat = analogRead(VBATPIN);  // Read 10-bit ADC value (0-1023)
  measuredvbat *= 2;                   // Compensate for voltage divider (2:1 ratio)
  measuredvbat *= 3.3;                 // Multiply by ADC reference voltage
  measuredvbat /= 1024;                // Convert ADC reading to actual voltage
}
