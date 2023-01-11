void startup() {


  /********************************************************
    Initialize pins
  ********************************************************/


  /*remember the left and right button for different castle fed is different*/
//  pinMode(8, OUTPUT);
//  pinMode(13, OUTPUT);
//
    pinMode(10, OUTPUT);
//  pinMode(11, OUTPUT); // YY ADDED 12/21/22
  //pinMode(A5, INPUT); // pin for current pos
  //pinMode(right_b_pulse, OUTPUT); //RIGHT SIDE PULSE
  //pinMode(left_b_pulse, OUTPUT); //LEFT SIDE PULSE
  
  pinMode(A0, INPUT_PULLDOWN);
  pinMode(A1, INPUT_PULLDOWN);
  pinMode(A2, INPUT_PULLDOWN);
  pinMode(A3, INPUT_PULLDOWN);

  LowPower.attachInterruptWakeup(A0, interrupt, CHANGE);
  LowPower.attachInterruptWakeup(A1, interrupt, CHANGE);
  LowPower.attachInterruptWakeup(A2, interrupt, CHANGE);
  LowPower.attachInterruptWakeup(A3, interrupt, CHANGE);
  

  // use A0 and A1 here

  /********************************************************
    Initialize RTC
  ********************************************************/
  //RTCZero rtc;
  //RTC_DS1307 rtc;
  rtc.begin(); // initialize RTC
  //rtc_lib.begin();

  /********************************************************
    Start, clear, and setup the display
  ********************************************************/
  // start & clear the display
//  display.begin();
//  display.clearDisplay();
//  minorHalfSize = min(display.width(), display.height()) / 2;
//  display.setRotation(0);
// 
//  // text display tests
//  display.setTextSize(1);
//  display.setTextColor(BLACK);
//  display.setCursor(0, 0);
//  display.println("Hello, world!");
//  display.refresh();
//  delay(500); 
//  display.clearDisplay();
//  
  /********************************************************
    start and baseline touch sensors
  ********************************************************/
//  qt_0.begin();
//  qt_1.begin();
//  qt_2.begin();
//  qt_3.begin();
  //baseline_touch();

  /********************************************************
    Center servo
  ********************************************************/


  /********************************************************
    Create file
  ********************************************************/
  CreateFile();
  CreatePos();


  move_center(middlepos);




}
