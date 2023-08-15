void startup() {
  /********************************************************
    Initialize pins
  ********************************************************/
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);  // output for pulse
  pinMode(13, OUTPUT); // for mosfet control
  pinMode(12, OUTPUT); // for mouserat control
  digitalWrite (11, LOW);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);

  pinMode(1, INPUT_PULLUP); //green button
  pinMode(A3, INPUT_PULLUP); // red button
  pinMode(A5, INPUT_PULLUP); // blue button

  LowPower.attachInterruptWakeup(A0, right_interrupt, FALLING);
  LowPower.attachInterruptWakeup(A1, left_interrupt, FALLING);
  LowPower.attachInterruptWakeup(A2, feed_interrupt, CHANGE);
  LowPower.attachInterruptWakeup(A3, interrupt, CHANGE);

  /********************************************************
    Initialize RTC
  ********************************************************/
  rtc.begin(); // initialize RTC

  /********************************************************
    Create file
  ********************************************************/
  CreateFile();
  CreatePos();
}
