int set_pos;
int nums = 0;
int dnums = 0;
bool mode = 0;
int onums = 0;
int on_nums = 0;
int off_nums = 0;

void display_current_params() {
  read_buttons();
  ReadBatteryLevel();
  display.fillRect(0, 0, 168, 144, WHITE);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.fillRect(0, 0, 168, 144, WHITE);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(40, 20);
  display.println("Castle Feeder!");
  display.setCursor(5, 45);
  display.println("Blue: Edit settings");
  display.setCursor(5, 60);
  display.println("Red: Start device");
  display.drawRect (5, 75, 156, 15, BLACK);
  display.setCursor(20, 80);
  display.println("Current settings: ");
  display.setCursor(5, 95);
  display.print("Open: ");
  display.print(openpos);
  display.setCursor(70, 95);
  display.print("Close: ");
  display.print(closedpos);
  display.setCursor(5, 110);
  display.print("Device#: ");
  display.print(CSL);
  display.setCursor(80, 110);
  display.print("Mode: ");
  mode == 1 ? display.print("Free") : display.print("FR1");
  display.setCursor(5, 125);
  display.print("Open duration: ");
  display.print(open_duration);
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
    set_feed_paradigm();
  }

  if (green_touch == 0) {
  }
}

void set_feed_paradigm() {
  endstate = false;
  read_buttons();
  display.fillRect(0, 0, 168, 144, WHITE);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("Mode");
  display.setCursor(5, 45);
  display.println("Green: Home");
  display.setCursor(5, 60);
  display.println("Blue: Next menu");
  display.setCursor(5, 75);
  display.println("Red: Change mode");
  display.setCursor(5, 90);
  display.print("Feed mode: ");
  mode == 1 ? display.print("Free") : display.print("FR1");
  display.refresh();

  //change mode
  if (red_touch == 0) {
    if (mode == 0) {
      mode = 1;
    }
    else {
      mode = 0;
    }
    delay(100);
  }

  if (blue_touch == 0) {
    endstate = true;
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
  when device is powered on, press b once to
  go to the device setting mode. numbers range
  from 0 to 19
********************************************************/

void setting_device_num() {
  endstate = false;
  starttime = millis();
  read_buttons();
  display.fillRect(0, 0, 168, 144, WHITE);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("Device #");
  display.setCursor(5, 45);
  display.println("Green: Home");
  display.setCursor(5, 60);
  display.println("Blue: Next menu");
  display.setCursor(5, 75);
  display.println("Red: Increase Device #");
  display.setCursor(5, 90);
  display.print("Device: ");
  display.print(CSL);
  display.refresh();

  if (red_touch == 0) {
    CSL++;
    if (CSL > 9) CSL = 0;
    delay(200);
  }

  if (blue_touch == 0) {
    endstate = true;
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
  display.fillRect(0, 0, 168, 144, WHITE);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("Open Duration");

  display.setCursor(5, 45);
  display.println("Green: Home");
  display.setCursor(5, 60);
  display.println("Blue: Next menu");
  display.setCursor(5, 75);
  display.println("Red: Increase Open Duration");
  display.setCursor(5, 90);
  display.println("Open Duration:");
  display.setCursor(5, 105);
  display.print(open_duration);
  display.print("s");
  display.refresh();

  if (red_touch == 0) {
    display.refresh();
    delay(200);
    open_duration += 10;
    if (open_duration > 120) open_duration = 10;
  }

  if (blue_touch == 0) {
    endstate = true;
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(openpos);
    delay(300);
    digitalWrite(13, LOW);
    setting_open_position();
  }

  if (green_touch == 0) {
    endstate = true;
    display_current_params();
  }

  if (endstate == false)  setting_open_duration();
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
  display.fillRect(0, 0, 168, 144, WHITE);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("Open Position");
  display.setCursor(5, 45);
  display.println("Green: Home");
  display.setCursor(5, 60);
  display.println("Blue: Next menu");
  display.setCursor(5, 75);
  display.println("Red: Increase Open Pos");
  display.setCursor(5, 90);
  display.print("Open: ");
  display.print(openpos);
  display.refresh();
  digitalWrite(13, HIGH);

  if (red_touch == 0) {
    display.refresh();
    openpos += 5;
    myservo.attach(10);
    myservo.write(openpos);
    delay(300);
    if (openpos > 160) openpos = 0;
  }

  if (blue_touch == 0) {
    endstate = true;
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(closedpos);
    delay(300);
    digitalWrite(13, LOW);
    setting_closed_position();
  }

  if (green_touch == 0) {
    endstate = true;
    display_current_params();
  }

  digitalWrite(13, LOW);
  if (endstate == false)  setting_open_position();
}

void setting_closed_position() {
  endstate = false;

  read_buttons();
  display.fillRect(0, 0, 168, 144, WHITE);
  display.drawRect(5, 5, 156, 35, BLACK);
  display.setCursor(20, 20);
  display.println("Closed Position");
  display.setCursor(5, 45);
  display.println("Green: Home");
  display.setCursor(5, 60);
  display.println("Blue: Next menu");
  display.setCursor(5, 75);
  display.println("Red: Increase Closed Pos");
  display.setCursor(5, 90);
  display.print("Closed: ");
  display.print(closedpos);
  display.refresh();
  digitalWrite(13, HIGH);

  if (red_touch == 0) {
    display.refresh();
    closedpos += 5;
    myservo.attach(10);
    myservo.write(closedpos);
    delay(300);
    if (closedpos > 160) closedpos = 0;
  }

  if (blue_touch == 0) {
    endstate = true;
    display_current_params();
  }

  if (green_touch == 0) {
    endstate = true;
    display_current_params();
  }

  digitalWrite(13, LOW);
  if (endstate == false)  setting_closed_position();
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
  ReadBatteryLevel();
  display.fillRect(0, 0, 168, 144, WHITE);
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
  if (freefeed) {
    display.setCursor(5, 95);
    display.print("On hour: ");
    display.print(on_hour);
    display.print("  Off hour: ");
    display.print(off_hour);
  }
  display.setCursor(5, 110);
  display.print("current time (h): ");
  display.print(rtc.now().hour());
  display.print(" : ");
  display.print(rtc.now().minute());
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
