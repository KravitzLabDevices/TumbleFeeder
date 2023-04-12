void startup() {


  /********************************************************
    Initialize pins
  ********************************************************/


  /*remember the left and right button for different castle fed is different*/
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT); // for mosfet control

  pinMode(A0, INPUT_PULLDOWN);
  pinMode(A1, INPUT_PULLDOWN);
  pinMode(A2, INPUT_PULLDOWN);
  pinMode(A3, INPUT_PULLDOWN);

  pinMode(A5, INPUT_PULLDOWN);

  LowPower.attachInterruptWakeup(A0, interrupt, CHANGE);
  LowPower.attachInterruptWakeup(A1, interrupt, CHANGE);
  LowPower.attachInterruptWakeup(A2, interrupt, CHANGE);
  LowPower.attachInterruptWakeup(A3, interrupt, CHANGE);


  // use A0 and A1 here

  /********************************************************
    Initialize RTC
  ********************************************************/

  rtc.begin(); // initialize RTC

  /********************************************************
    Create file
  ********************************************************/
  CreateFile();
  CreatePos();
  //

  //  move_center(middlepos);
  //



}
