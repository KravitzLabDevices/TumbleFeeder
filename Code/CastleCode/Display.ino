
int set_pos;
int nums = 0;
int dnums = 0;
int fnums = 0;

int onums = 0;

int on_nums = 0;
int off_nums = 0;

/********************************************************
  setting the device number of castle fed
  when device is powered on, press b once to
  go to the device setting mode. press c to
  increment the device number. numbers range
  from 0 to 19
********************************************************/

int settting_device_num(int cur_pos) { // also display freefeed on screeen
  int red_touch = digitalRead(A3); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);

  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("MENU: Device #");

  display.setCursor(5, 45);
  display.println("Green Button : next menu");

  display.setCursor(5, 60);
  display.println("Blue Button : change params");
  display.setCursor(5, 75);
  display.print("Device: ");
  display.print(CSL);
  display.refresh();

  if (red_touch == 0) {
    delay(100);
    dnums += 1;
  }
  delay(500);
  return dnums % 20;
}



unsigned long setting_open_interval() {




  int red_touch = digitalRead(A3); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("MENU: Open Interval");

  display.setCursor(5, 45);
  display.println("Green Button : next menu");

  display.setCursor(5, 60);
  display.println("Blue Button : change params");
  display.setCursor(5, 75);
  display.print("time(s): ");
  display.print(open_interval);
  display.refresh();

  if (red_touch == 0) {
    delay(100);
    onums += 10;
  }
  delay(500);
  return (onums % 180) * 1000;
}





int set_feed_paradigm() {

  int red_touch = digitalRead(A3); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("MENU: Feed Paradigm");


  display.setCursor(5, 45);
  display.println("Green Button : next menu");

  display.setCursor(5, 60);
  display.println("Blue Button : change params");
  display.setCursor(5, 75);
  display.print("feed mode: ");
  fnums == 1 ? display.print("free feed") : display.print("FR 1");
  display.refresh();

  if (red_touch == 0) {
    delay(100);
    fnums = -(fnums - 1);
  }
  delay(500);
  return fnums;
}


/********************************************************
  setting position can set the position of left feeding space,
  middle block, and right feeding space. after the use finish
  setting the device number(pressed button B once), they can
  choose to directly start the program by pressing button A or
  continue pressing button B to set position. press C to move
  motor to the desirable pos and press b to go to the next
  position you want to set. after finish setting press A to
  start running
********************************************************/
int setting_position(int cur_pos) {

  int red_touch = digitalRead(A3); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("MENU: Motor Position");


  display.setCursor(5, 45);
  display.println("Green Button : next menu");

  display.setCursor(5, 60);
  display.println("Blue Button : change params");


  display.setCursor(5, 95);
  display.print("Open: ");
  display.print(leftpos);
  display.setCursor(70, 95);
  display.print("Close: ");
  display.print(middlepos);

  display.refresh();
  digitalWrite(13, HIGH);

  if (red_touch == 0) {
    delay(100);
    nums += 10;
    myservo.attach(10);
    myservo.write(nums % 180);
  }
  set_pos = nums % 180;
  delay(500);
  digitalWrite(13, LOW);
  display.refresh();
  return set_pos;
}

int setting_on_hour() {
  int red_touch = digitalRead(A3); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("MENU: On Hour");


  display.setCursor(5, 45);
  display.println("Green Button : next menu");

  display.setCursor(5, 60);
  display.println("Blue Button : change params");
  display.setCursor(5, 75);
  display.print("On Hour: ");
  display.print(on_hour);
  display.refresh();
  if (red_touch == 0) {
    delay(100);
    on_nums += 1;
  }
  delay(500);
  return (on_nums % 24) ;

}

int setting_off_hour() {
  int red_touch = digitalRead(A3); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("MENU: Off Hour");


  display.setCursor(5, 45);
  display.println("Green Button : next menu");

  display.setCursor(5, 60);
  display.println("Blue Button : change params");
  display.setCursor(5, 75);
  display.print("Off Hour: ");
  display.print(off_hour);
  display.refresh();
  if (red_touch == 0) {
    delay(100);
    off_nums += 1;
  }
  delay(500);
  return (off_nums % 24) ;

}



void display_current_params(int cur_pos) {

  int red_touch = digitalRead(A3);
  ReadBatteryLevel();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);

  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("Button Instruction");

  display.setCursor(5, 45);
  display.println("Press Green: set params");
  display.setCursor(5, 60);
  display.println("Press Red: start device");

  display.drawRect (5, 75, 156, 15, BLACK);
  display.setCursor(20, 80);
  display.println("Current params values: ");
  display.setCursor(5, 95);
  display.print("Open: ");
  display.print(leftpos);
  display.setCursor(70, 95);
  display.print("Close: ");
  display.print(middlepos);

  display.setCursor(5, 110);
  display.print("Device #: ");
  display.print(CSL);

  display.setCursor(80, 110);
  display.print("Mode: ");
  freefeed == 1 ? display.print("freefeed") : display.print("FR 1");

  display.setCursor(5, 125);
  display.print("FR open interval: ");
  display.print(open_interval);
  display.refresh();
  if (red_touch == 0) {
    toggle = true;
    CreateFile();
    display_mouse();
    writeConfigFile();
    update_display();
  }
  delay(1000);
}
































/********************************************************
  update display of the total number of left and right poke whenever left or right button
  is pressed. during the 20s window proceeding the button press, the function will also update
  on the number of feeding and feeding duration. the current battery level and
  time elapsed is also displayed
*********************************************************/
void update_display() {
  ReadBatteryLevel();
  //currentpos = analogRead(A5);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.setCursor(5, 5);
  display.print("Pos:");
  display.print(currentpos);
  display.print(" Time:");
  display.println(millis() / 1000);

  display.setCursor(5, 20);
  display.print("Poke L: ");
  display.print(leftPokeCount);

  display.setCursor(5, 35);
  display.print("Poke R: ");
  display.print(rightPokeCount);

  display.setCursor(5, 50);
  display.print("Feed: ");
  display.print(leftFeederCount);


  display.setCursor(5, 65);
  display.print("Bat V: ");
  display.print(measuredvbat);
  display.setCursor(80, 65);
  display.print("CSL: ");
  display.print(" ");
  display.print(CSL);
  display.print(" ");
  display.setCursor(5, 80);
  display.print("free feed?: ");
  display.print(freefeed);
  display.refresh();
  inputtriggered = 0;
}


/********************************************************
  Display SD Card error
********************************************************/
void DisplaySDError() {
  Blink (13, 50, 3);
  delay (25);
  Blink (8, 50, 3);
  delay (25);
  display.clearDisplay();
  display.setTextSize(1);
  display.setRotation(1);
  display.setCursor(10, 10);
  display.println("Check SD card!");
  display.refresh();
}



void display_mouse() {
  display.setRotation(1);
  for (int i = -50; i < 200; i += 15) {
    display.fillRoundRect (i + 25, 82, 15, 10, 6, BLACK);    //head
    display.fillRoundRect (i + 22, 80, 8, 5, 3, BLACK);      //ear
    display.fillRoundRect (i + 30, 84, 1, 1, 1, WHITE);      //eye
    //movement of the mouse
    if ((i / 10) % 2 == 0) {
      display.fillRoundRect (i, 84, 32, 17, 10, BLACK);      //body
      display.drawFastHLine(i - 8, 85, 18, BLACK);           //tail
      display.drawFastHLine(i - 8, 86, 18, BLACK);
      display.drawFastHLine(i - 14, 84, 8, BLACK);
      display.drawFastHLine(i - 14, 85, 8, BLACK);
      display.fillRoundRect (i + 22, 99, 8, 4, 3, BLACK);    //front foot
      display.fillRoundRect (i , 97, 8, 6, 3, BLACK);        //back foot
    }
    else {
      display.fillRoundRect (i + 2, 82, 30, 17, 10, BLACK);  //body
      display.drawFastHLine(i - 6, 91, 18, BLACK);           //tail
      display.drawFastHLine(i - 6, 90, 18, BLACK);
      display.drawFastHLine(i - 12, 92, 8, BLACK);
      display.drawFastHLine(i - 12, 91, 8, BLACK);
      display.fillRoundRect (i + 15, 99, 8, 4, 3, BLACK);    //foot
      display.fillRoundRect (i + 8, 97, 8, 6, 3, BLACK);     //back foot
    }
    display.refresh();
    delay (80);
    display.fillRect (i - 25, 73, 95, 33, WHITE);

  }
}
