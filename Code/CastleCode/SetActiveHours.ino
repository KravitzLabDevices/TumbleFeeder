boolean set_active() {
  DateTime t = rtc.now();
  Serial.println(t.hour());
  if ((off_hour - on_hour) < 0)
  {
    if (t.hour() >= on_hour || t.hour() < off_hour) {
      return true;
    } else {
      return false;
    }
  }
  else {
    Serial.println("not overnight");
    if (t.hour() >= on_hour && t.hour() < off_hour) {
      Serial.println("active");
      return true;
    } else {
      return false;
    }
  }
}
