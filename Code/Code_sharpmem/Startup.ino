void startup() {


  /********************************************************
    Initialize pins
  ********************************************************/


  /*remember the left and right button for different castle fed is different*/
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT); // for mosfet control
  pinMode(12, OUTPUT); // for mouserat control
  
  pinMode(A0, INPUT_PULLDOWN);
  pinMode(A1, INPUT_PULLDOWN);
  pinMode(A2, INPUT_PULLDOWN);

 // pinMode(1, INPUT_PULLUP); //green button 
  pinMode(A3, INPUT_PULLDOWN); // red button
 // pinMode(A5, INPUT_PULLUP); // blue button 

  LowPower.attachInterruptWakeup(A0, right_interrupt, RISING);
  LowPower.attachInterruptWakeup(A1, left_interrupt, RISING);
  LowPower.attachInterruptWakeup(A2, feed_interrupt, CHANGE);
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

}
