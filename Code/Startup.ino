void startup() {
  Serial.begin (9600);

  /********************************************************
    Initialize pins
  ********************************************************/
  int right_b_pulse = 5;
  int left_b_pulse = 6;


/*remember the left and right button for different castle fed is different*/
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(BUTTON_A,INPUT);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(A5, INPUT); // pin for current pos
  pinMode(right_b_pulse, OUTPUT); //RIGHT SIDE PULSE
  pinMode(left_b_pulse, OUTPUT); //LEFT SIDE PULSE


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
  delay(250); // wait for the OLED to power up
  display.begin(0x3C, true); // Address 0x3C default
  display.setRotation(1);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.clearDisplay();
  display.display();

  /********************************************************
    start and baseline touch sensors
  ********************************************************/
  qt_0.begin();
  qt_1.begin();
  qt_2.begin();
  qt_3.begin();
  baseline_touch();

  /********************************************************
    Center servo
  ********************************************************/


  /********************************************************
    Create file
  ********************************************************/
  //CreateFile();
  CreatePos();

  Serial.print(leftpos);
  Serial.print(middlepos);
  Serial.println(rightpos);








  move_center(middlepos);




}
