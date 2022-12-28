void startup() {
  Serial.begin(115200);

  /********************************************************
    Initialize pins
  ********************************************************/
  int right_b_pulse = 5;
  int left_b_pulse = 6;

  /*remember the left and right button for different castle fed is different*/
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(A5, INPUT);              // pin for current pos
  pinMode(right_b_pulse, OUTPUT);  //RIGHT SIDE PULSE
  pinMode(left_b_pulse, OUTPUT);   //LEFT SIDE PULSE

  /********************************************************
    Initialize RTC
  ********************************************************/
  rtc.begin();  // initialize RTC

  /********************************************************
    Start, clear, and setup the display
  ********************************************************/
  display.begin(THINKINK_GRAYSCALE4);
  display.clearBuffer();
  display.setTextSize(3);
  display.setCursor(20, 40);
  display.setTextColor(EPD_DARK);
  display.print("YY ");
  display.setTextColor(EPD_BLACK);
  display.print("CASTLE!");
  display.display();
  delay(5000);
  Serial.println("Did I get here?");

  /********************************************************
    start and baseline touch sensors
  ********************************************************/
  qt_0.begin();
  qt_1.begin();
  qt_2.begin();
  qt_3.begin();
  baseline_touch();

  /********************************************************
    Create file
  ********************************************************/
  //CreateFile();
  CreatePos();

  /********************************************************
    Center servo
  ********************************************************/
  Serial.println(leftpos);
  Serial.println(middlepos);
  Serial.println(rightpos);
  move_center(middlepos);
}