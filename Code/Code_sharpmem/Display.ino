
int set_pos;
int nums = 0;
int dnums = 0;
int fnums = 0;



/********************************************************
  setting the device number of castle fed
  when device is powered on, press b once to
  go to the device setting mode. press c to
  increment the device number. numbers range
  from 0 to 19
********************************************************/

int settting_device_num(int cur_pos) { // also display freefeed on screeen
  int blue_touch = digitalRead(A1); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  //display.setRotation(1);
  display.setCursor(5, 5);
  display.println("now setting Device #");
  display.setCursor(5, 20);
  display.println("Press Button C :");
  display.setCursor(5, 35);
  display.print("Device: ");
  display.print(CSL);
  display.refresh();

  if (blue_touch == 1) {
    delay(100);
    dnums += 1;
  }
  delay(500);
  return dnums % 20;
}





int set_feed_paradigm() {
  int blue_touch = digitalRead(A1); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  //display.setRotation(1);
  display.setCursor(5, 5);
  display.println("now setting feed paradigm ");
  display.setCursor(0, 20);
  display.println("Press Button 2 :");
  display.setCursor(0, 35);
  display.print("free feed ?: ");
  display.print(fnums);
  display.refresh();

  if (blue_touch == 1) {
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

  int blue_touch = digitalRead(A1); // left
  ReadBatteryLevel();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  //display.setRotation(1);

  display.drawRect(5, 5, 135, 35, BLACK);
  display.setCursor(20, 20);
  display.println("Button Instruction");



  display.setCursor(5, 45);
  display.println("Press 1: switch mode");
  display.setCursor(5, 60);
  display.println("Press 2: move servo");
  display.setCursor(5, 75);
  display.println("Press 3: start device");

  display.drawRect (5, 90, 135, 35, BLACK);
  display.setCursor(5, 105);
  display.println("Current Servo Position: ");
  display.setCursor(5, 130);
  display.print("Open: ");
  display.print(leftpos);
  display.setCursor(70, 130);
  display.print("Close: ");
  display.print(middlepos);
  display.setCursor(5, 145);
  display.print("Bat V: ");
  display.println(measuredvbat);

  display.refresh();
  digitalWrite(13, HIGH); // MOSFET ON

  if (blue_touch == 1) {
    delay(100);
    nums += 10;
    myservo.attach(10);
    myservo.write(nums % 180);
  }
  set_pos = nums % 180;
  delay(500);
  if (cur_pos == 4) {
    analog_pos = analogRead(A5);
    *pt_middle = analog_pos;
  }
  digitalWrite(13, LOW);
  display.refresh();
  return set_pos;
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
  //display.setRotation(1);
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
  //display.setRotation(1);
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
