void display_current_params() {
  display.fillRect(0, 0, 168, 128, WHITE);  //clear screen

  digitalWrite(13, LOW);
  read_buttons();
  display.drawRect(5, 5, 104, 25, BLACK);
  display.setCursor(35, 14);
  display.println("Settings");
  display.setCursor(138, 60);
  display.println("Edit");
  display.setCursor(134, 100);
  display.println("Start");
  display.setCursor(36, 14);
  display.println("Settings");
  display.setCursor(139, 60);
  display.println("Edit");
  display.setCursor(135, 100);
  display.println("Start");
  display.drawRect(5, 5, 104, 110, BLACK);
  display.drawRect(2, 2, 110, 116, BLACK);

  display.setCursor(12, 40);
  display.print("Mode: ");
  display.setCursor(80, 40);
  mode == 1 ? display.print("Free") : display.print("FR1");
  display.setCursor(12, 55);
  display.print("Device#: ");
  display.setCursor(80, 55);
  display.print(CSL);
  display.setCursor(12, 70);
  display.print("Time open: ");
  display.setCursor(80, 70);
  display.print(open_duration);
  display.setCursor(12, 85);
  display.print("Open Pos: ");
  display.setCursor(80, 85);
  display.print(openpos);
  display.setCursor(12, 100);
  display.print("Close Pos: ");
  display.setCursor(80, 100);
  display.print(closedpos);

  DisplayBattery();

  display.refresh();

  DateTime now = rtc.now();
  display.setCursor(10, 130);
  display.fillRect(10, 129, 200, 60, WHITE);
  display.print(now.month());
  display.print("/");
  display.print(now.day());
  display.print("/");
  display.print(now.year());
  display.print("      ");
  if (now.hour() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.minute());
  display.refresh();

  if (red_touch == 0) {
    display.refresh();
    SessionStarted = true;
    CreateFile();
    display_mouse();
    writeConfigFile();
    update_display();
  }

  if (blue_touch == 0) {
    delay(100);
    display.fillRect(117, 2, 60, 50, WHITE);
    set_feed_paradigm();
  }

  if (green_touch == 0) {
  }
}

void set_feed_paradigm() {
  display.fillRect(134, 20, 35, 12, WHITE);
  display.setCursor(134, 20);
  display.println("Back");
  display.setCursor(135, 20);
  display.println("Back");

  display.fillRect(132, 60, 35, 12, WHITE);
  display.setCursor(132, 60);
  display.println("Next");
  display.setCursor(133, 60);
  display.println("Next");

  display.fillRect(128, 100, 35, 12, WHITE);
  display.setCursor(128, 100);
  display.println("Update");
  display.setCursor(129, 100);
  display.println("Update");
  display.refresh();

  endstate = false;
  read_buttons();
  display.setCursor(80, 40);
  mode == 1 ? display.print("Free") : display.print("FR1");
  display.refresh();
  delay(50);
  display.fillRect(80, 40, 25, 12, WHITE);
  display.refresh();
  delay(50);

  //change mode
  if (red_touch == 0) {
    if (mode == 0) {
      mode = 1;
    } else {
      mode = 0;
    }
  }

  if (blue_touch == 0) {
    endstate = true;
    display.setCursor(80, 40);
    mode == 1 ? display.print("Free") : display.print("FR1");
    display.refresh();
    delay(100);
    setting_device_num();
  }

  if (green_touch == 0) {
    endstate = true;
    display_current_params();
  }

  if (endstate == false) set_feed_paradigm();
}

/********************************************************
  setting the device number of castle fed
  numbers range from 0 to 19
********************************************************/
void setting_device_num() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 55);
  display.print(CSL);
  display.refresh();
  delay(80);
  display.fillRect(80, 55, 25, 12, WHITE);
  display.refresh();
  delay(20);

  if (red_touch == 0) {
    CSL++;
    if (CSL > 9) CSL = 0;
    delay(200);
  }

  if (blue_touch == 0) {
    display.setCursor(80, 55);
    display.print(CSL);
    display.refresh();
    endstate = true;
    delay(100);
    setting_open_duration();
  }

  if (green_touch == 0) {
    endstate = true;
    display_current_params();
  }

  if (endstate == false) setting_device_num();
}

void setting_open_duration() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 70);
  display.print(open_duration);
  display.refresh();
  delay(80);
  display.fillRect(80, 70, 25, 12, WHITE);
  display.refresh();
  delay(20);

  if (red_touch == 0) {
    display.refresh();
    open_duration += 10;
    if (open_duration > 120) open_duration = 10;
  }

  if (blue_touch == 0) {
    display.setCursor(80, 70);
    display.print(open_duration);
    display.refresh();
    endstate = true;
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(openpos);
    delay(300);
    myservo.detach();
    digitalWrite(13, LOW);
    setting_open_position();
  }

  if (green_touch == 0) {
    endstate = true;
    display_current_params();
  }

  if (endstate == false) setting_open_duration();
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
void setting_open_position() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 85);
  display.print(openpos);
  display.refresh();
  delay(80);
  display.fillRect(80, 85, 25, 12, WHITE);
  display.refresh();
  delay(20);

  if (red_touch == 0) {
    delay(100);
    display.refresh();
    openpos += 5;
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(openpos);
    delay(300);
    myservo.detach();
    digitalWrite(13, LOW);
    if (openpos > 160) openpos = 0;
  }

  if (blue_touch == 0) {
    display.setCursor(80, 85);
    display.print(openpos);
    display.refresh();
    endstate = true;
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(closedpos);
    delay(300);
    myservo.detach();
    digitalWrite(13, LOW);
    setting_closed_position();
  }

  if (green_touch == 0) {
    delay(100);
    endstate = true;
    display_current_params();
  }
  if (endstate == false) setting_open_position();
}

void setting_closed_position() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 100);
  display.print(closedpos);
  display.refresh();
  delay(80);
  display.fillRect(80, 100, 25, 12, WHITE);
  display.refresh();
  delay(20);

  if (red_touch == 0) {
    delay(100);
    display.refresh();
    closedpos += 5;
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(closedpos);
    delay(300);
    myservo.detach();
    digitalWrite(13, LOW);
    if (closedpos > 150) closedpos = 0;
  }

  if (blue_touch == 0) {
    display.setCursor(80, 100);
    display.print(closedpos);
    display.refresh();
    endstate = true;
    display_current_params();
  }

  if (green_touch == 0) {
    endstate = true;
    display_current_params();
  }
  if (endstate == false) setting_closed_position();
}

void setting_on_hour() {
  //  read_buttons();
  //  display.fillRect(0, 0, 168, 144, WHITE);
  //  display.drawRect(5, 5, 156, 35, BLACK);
  //  display.setCursor(20, 20);
  //  display.println("On Hour");
  //
  //  display.setCursor(5, 45);
  //  display.println("Green Button : next menu");
  //
  //  display.setCursor(5, 60);
  //  display.println("Blue Button : change params");
  //  display.setCursor(5, 75);
  //  display.print("On Hour: ");
  //  display.print(on_hour);
  //  //  display.refresh();
  //  if (red_touch == 0) {
  //    display.refresh();
  //    delay(100);
  //    on_nums += 1;
  //  }
  //  return (on_nums % 24) ;
}

void setting_off_hour() {
  //  read_buttons();
  //  display.fillRect(0, 0, 168, 144, WHITE);
  //  display.drawRect(5, 5, 156, 35, BLACK);
  //  display.setCursor(20, 20);
  //  display.println("Off Hour");
  //  display.setCursor(5, 45);
  //  display.println("Green Button : next menu");
  //  display.setCursor(5, 60);
  //  display.println("Blue Button : change params");
  //  display.setCursor(5, 75);
  //  display.print("Off Hour: ");
  //  display.print(off_hour);
  //  if (red_touch == 0) {
  //    display.refresh();
  //    delay(100);
  //    off_nums += 1;
  //  }
  //  return (off_nums % 25) ;
}

/********************************************************
  update display of the total number of left and right poke whenever left or right button
  is pressed. during the 20s window proceeding the button press, the function will also update
  on the number of feeding and feeding duration. the current battery level and
  time elapsed is also displayed
*********************************************************/
void update_display() {

  display.fillRect(0, 0, 168, 128, WHITE);  //clear screen

  display.setCursor(35, 14);
  display.println("Running!");
  display.setCursor(36, 14);
  display.println("Running!");

  digitalWrite(13, LOW);
  read_buttons();
  display.setCursor(134, 100);
  display.println("Reset");
  display.setCursor(135, 100);
  display.println("Reset");

  display.drawRect(5, 5, 104, 110, BLACK);
  display.drawRect(2, 2, 110, 116, BLACK);

  display.setCursor(12, 40);
  display.print("Mode: ");
  display.setCursor(80, 40);
  mode == 1 ? display.print("Free") : display.print("FR1");
  display.setCursor(12, 55);
  display.print("Device#: ");
  display.setCursor(80, 55);
  display.print(CSL);
  display.setCursor(12, 70);
  display.print("Left: ");
  display.setCursor(80, 70);
  display.print(leftPokeCount);
  display.setCursor(12, 85);
  display.print("Right: ");
  display.setCursor(80, 85);
  display.print(rightPokeCount);
  display.setCursor(12, 100);
  display.print("Feed: ");
  display.setCursor(80, 100);
  display.print(leftFeederCount);

  DisplayBattery();

  DateTime now = rtc.now();
  display.setCursor(10, 130);
  display.fillRect(10, 129, 200, 60, WHITE);
  display.print(now.month());
  display.print("/");
  display.print(now.day());
  display.print("/");
  display.print(now.year());
  display.print("      ");
  if (now.hour() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.minute());
  display.refresh();

  if (red_touch == 0) {
    delay(1000);
    if (red_touch == 0) {
      NVIC_SystemReset();
    }
  }


  display.refresh();
  inputtriggered = 0;
}


/********************************************************
  Display SD Card error
********************************************************/
void DisplaySDError() {
  Blink(13, 50, 3);
  delay(25);
  Blink(8, 50, 3);
  delay(25);
  display.fillRect(0, 0, 168, 144, WHITE);
  display.setTextSize(1);
  display.setRotation(1);
  display.setCursor(10, 10);
  display.println("Check SD card!");
  display.refresh();
}

/********************************************************
  Mouse animation
********************************************************/
void display_mouse() {
  display.setRotation(1);
  for (int i = -50; i < 200; i += 15) {
    display.fillRoundRect(i + 25, 82, 15, 10, 6, BLACK);  //head
    display.fillRoundRect(i + 22, 80, 8, 5, 3, BLACK);    //ear
    display.fillRoundRect(i + 30, 84, 1, 1, 1, WHITE);    //eye
    //movement of the mouse
    if ((i / 10) % 2 == 0) {
      display.fillRoundRect(i, 84, 32, 17, 10, BLACK);  //body
      display.drawFastHLine(i - 8, 85, 18, BLACK);      //tail
      display.drawFastHLine(i - 8, 86, 18, BLACK);
      display.drawFastHLine(i - 14, 84, 8, BLACK);
      display.drawFastHLine(i - 14, 85, 8, BLACK);
      display.fillRoundRect(i + 22, 99, 8, 4, 3, BLACK);  //front foot
      display.fillRoundRect(i, 97, 8, 6, 3, BLACK);       //back foot
    } else {
      display.fillRoundRect(i + 2, 82, 30, 17, 10, BLACK);  //body
      display.drawFastHLine(i - 6, 91, 18, BLACK);          //tail
      display.drawFastHLine(i - 6, 90, 18, BLACK);
      display.drawFastHLine(i - 12, 92, 8, BLACK);
      display.drawFastHLine(i - 12, 91, 8, BLACK);
      display.fillRoundRect(i + 15, 99, 8, 4, 3, BLACK);  //foot
      display.fillRoundRect(i + 8, 97, 8, 6, 3, BLACK);   //back foot
    }
    display.refresh();
    delay(80);
    display.fillRect(i - 25, 73, 95, 33, WHITE);
  }
}

void DisplayBattery() {
  ReadBatteryLevel();
  display.fillRect(119, 5, 40, 16, WHITE);
  display.drawRect(118, 4, 42, 18, BLACK);
  display.drawRect(159, 9, 6, 8, BLACK);

  //  Battery graphic showing bars indicating voltage levels
  //4 bars
  if (measuredvbat > 3.85) {
    display.fillRect(122, 7, 7, 12, BLACK);
    display.fillRect(131, 7, 7, 12, BLACK);
    display.fillRect(140, 7, 7, 12, BLACK);
    display.fillRect(149, 7, 7, 12, BLACK);
  }

  //3 bars
  else if (measuredvbat > 3.7) {
    display.fillRect(121, 6, 26, 13, WHITE);
    display.fillRect(122, 7, 7, 12, BLACK);
    display.fillRect(131, 7, 7, 12, BLACK);
    display.fillRect(140, 7, 7, 12, BLACK);
  }

  //2 bars
  else if (measuredvbat > 3.55) {
    display.fillRect(121, 6, 26, 13, WHITE);
    display.fillRect(122, 7, 7, 12, BLACK);
    display.fillRect(131, 7, 7, 12, BLACK);
  }

  //1 bar
  else {
    display.fillRect(121, 6, 26, 13, WHITE);
    display.fillRect(122, 7, 7, 12, BLACK);
  }

  //display voltage
  display.fillRect(122, 26, 28, 12, WHITE);
  display.setCursor(122, 26);
  display.print(measuredvbat, 2);
  display.print("V");
}