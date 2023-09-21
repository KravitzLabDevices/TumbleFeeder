//set clock
void SetClock() {

  DateTime now = rtc.now();
  // unixtime = now.unixtime();

  /********************************************************
       Display date and time of RTC
     ********************************************************/
  display.setCursor(1, 40);
  display.print("RTC set to:");
  display.setCursor(1, 40);
  display.print("RTC set to:");

  display.fillRoundRect(0, 45, 400, 25, 1, WHITE);
  //display.refresh();
  display.setCursor(1, 60);
  if (now.month() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.month(), DEC);
  display.print("/");
  if (now.day() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.day(), DEC);
  display.print("/");
  display.print(now.year(), DEC);
  display.print(" ");
  display.print(now.hour(), DEC);
  display.print(":");
  if (now.minute() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.minute(), DEC);
  display.print(":");
  if (now.second() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.println(now.second(), DEC);
  display.drawFastHLine(30, 80, 100, BLACK);
  display.refresh();

  if (green_touch == 0) {
    //   rtc.adjust(DateTime(unixtime - 60));
    //    EndTime = millis();
  }

  if (red_touch == 0) {
    //  rtc.adjust(DateTime(unixtime + 60));
    //  EndTime = millis();
  }
}