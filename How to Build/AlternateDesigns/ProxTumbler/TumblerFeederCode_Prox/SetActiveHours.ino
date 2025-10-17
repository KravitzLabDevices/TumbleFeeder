/*****************************************************************
 * ACTIVE HOURS SCHEDULING
 * 
 * This file contains functions for checking whether the device
 * should be active based on scheduled on/off hours. Currently
 * disabled but could be re-enabled for circadian experiments.
 * 
 * POTENTIAL USE CASES:
 * - Light/dark cycle experiments (e.g., only active during light phase)
 * - Time-restricted feeding protocols
 * - Conservation of battery during specific hours
 *****************************************************************/

/*****************************************************************
 * CHECK IF DEVICE SHOULD BE ACTIVE
 * 
 * This function would check if the current time falls within
 * the active hours defined by on_hour and off_hour variables.
 * 
 * CURRENTLY DISABLED - Always returns false
 * 
 * COMMENTED CODE LOGIC (if re-enabled):
 * - Handles both same-day and overnight schedules
 * - If off_hour < on_hour: overnight schedule (e.g., 20:00 to 08:00)
 *   Device is active if hour >= on_hour OR hour < off_hour
 * - If off_hour > on_hour: same-day schedule (e.g., 08:00 to 20:00)
 *   Device is active if hour >= on_hour AND hour < off_hour
 * 
 * RETURNS:
 * - true: Device should be active (allow feeding)
 * - false: Device should be inactive (sleep/ignore inputs)
 * 
 * TO RE-ENABLE:
 * 1. Uncomment the code below
 * 2. Add menu options to set on_hour and off_hour
 * 3. Call this function in run() to gate feeding operations
 *****************************************************************/
boolean set_active() {
  // CURRENTLY DISABLED - ALWAYS RETURNS FALSE
  // To enable time-based scheduling, uncomment the code below
  
  //  DateTime t = rtc.now();
  //  Serial.println(t.hour());
  //  
  //  // Check if schedule spans midnight (e.g., 20:00 to 08:00)
  //  if ((off_hour - on_hour) < 0) {
  //    // Overnight schedule
  //    if (t.hour() >= on_hour || t.hour() < off_hour) {
  //      return true;  // Active during evening/night/early morning
  //    } else {
  //      return false; // Inactive during day
  //    }
  //  }
  //  else {
  //    // Same-day schedule (e.g., 08:00 to 20:00)
  //    Serial.println("not overnight");
  //    if (t.hour() >= on_hour && t.hour() < off_hour) {
  //      Serial.println("active");
  //      return true;  // Active during specified day hours
  //    } else {
  return false;  // Currently always inactive
  //    }
  //  }
}
