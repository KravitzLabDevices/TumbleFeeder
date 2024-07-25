void startup() {
  Serial.begin(9600);

  /********************************************************
    Initialize pins
  ********************************************************/
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);  // output for pulse
  pinMode(13, OUTPUT);  // for mosfet control
  pinMode(12, OUTPUT);  // for mouserat control
  digitalWrite(11, LOW);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);

  pinMode(1, INPUT_PULLUP);   //green button
  pinMode(A3, INPUT_PULLUP);  // red button
  pinMode(A5, INPUT_PULLUP);  // blue button

  LowPower.attachInterruptWakeup(A0, right_interrupt, FALLING);
  LowPower.attachInterruptWakeup(A2, left_interrupt, FALLING);
  LowPower.attachInterruptWakeup(A1, feed_interrupt, FALLING);
  LowPower.attachInterruptWakeup(A3, interrupt, CHANGE);

  /********************************************************
    Initialize RTC
  ********************************************************/
  rtc.begin();  // initialize RTC

  /********************************************************
    Create file
  ********************************************************/
  SdFile::dateTimeCallback(dateTime);  //added this line so the files on the SD card have the correct date and time
  CreateFile();
  CreatePos();

  /********************************************************
    Start screen
  ********************************************************/
  display.begin();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.fillRect(0, 0, 168, 144, WHITE);
}
