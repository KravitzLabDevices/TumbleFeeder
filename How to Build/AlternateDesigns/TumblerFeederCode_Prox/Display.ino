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

  display.setCursor(12, 36);
  display.print("Mode: ");
  display.setCursor(80, 36);
  mode == 1 ? display.print("Free") : display.print("Prox");

  display.setCursor(12, 48);
  display.print("ProxTime: ");
  display.setCursor(80, 48);
  display.print(FR);

  display.setCursor(12, 60);
  display.print("Device#: ");
  display.setCursor(80, 60);
  display.print(CSL);

  display.setCursor(12, 72);
  display.print("Sec open: ");
  display.setCursor(80, 72);
  display.print(open_duration);
  display.setCursor(12, 84);
  display.print("Open Pos: ");
  display.setCursor(80, 84);
  display.print(openpos);
  display.setCursor(12, 96);

  display.print("Close Pos: ");
  display.setCursor(80, 96);
  display.print(closedpos);

  DisplayBattery();

  DateTime now = rtc.now();
  display.setCursor(5, 128);
  display.fillRect(5, 127, 200, 60, WHITE);
  if (now.month() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.month());
  display.print("-");
  if (now.day() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.day());
  display.print("-");
  display.print(now.year() % 100);
  display.print("     ");
  if (now.hour() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.minute());
  display.refresh();

  if (red_touch == 0) {
    Beep();
    SessionStarted = true;
    display_mouse();
    CreateFile();
    writeConfigFile();
    update_display();
  }

  if (blue_touch == 0) {
    Beep();
    delay(100);
    display.fillRect(117, 2, 60, 50, WHITE);
    menustart = millis();
    set_feed_paradigm();
  }

  if (green_touch == 0) {
  }
}

void set_feed_paradigm() {
  endstate = false;
  display.fillRect(134, 20, 35, 12, WHITE);
  display.setCursor(134, 20);
  display.println("Back");
  display.setCursor(135, 20);
  display.println("Back");

  display.fillRect(134, 60, 35, 12, WHITE);
  display.setCursor(134, 60);
  display.println("Next");
  display.setCursor(135, 60);
  display.println("Next");

  display.fillRect(134, 100, 35, 12, WHITE);
  display.setCursor(134, 100);
  display.println("Edit");
  display.setCursor(135, 100);
  display.println("Edit");
  display.refresh();

  read_buttons();
  display.setCursor(80, 36);
  mode == 1 ? display.print("Free") : display.print("Prox");
  display.refresh();

  if ((millis() - menustart) > 250) {
    display.fillRect(80, 36, 25, 12, WHITE);
    display.refresh();
    delay(5);
    menustart = millis();
  }

  //change mode
  if (red_touch == 0) {
    Beep();
    if (mode == 0) {
      mode = 1;
      delay(200);
    } else {
      mode = 0;
      delay(200);
    }
  }

  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 36, 25, 12, WHITE);
    display.setCursor(80, 36);
    mode == 1 ? display.print("Free") : display.print("Prox");
    display.refresh();
    delay(100);
    endstate = true;
    setting_FR();
  }

  if (green_touch == 0) {
    Beep();
    endstate = true;
    display_current_params();
  }

  if (endstate == false) set_feed_paradigm();
}

/********************************************************
  setting the FR
********************************************************/
void setting_FR() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 48);
  display.print(FR);
  display.refresh();

  if ((millis() - menustart) > 250) {
    display.fillRect(80, 48, 25, 12, WHITE);
    display.refresh();
    delay(5);
    menustart = millis();
  }

  if (red_touch == 0) {
    Beep();
    FR++;
    if (FR > 10) FR = 1;
    delay(200);
  }

  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 48, 25, 12, WHITE);
    display.refresh();
    display.setCursor(80, 48);
    display.print(FR);
    display.refresh();
    endstate = true;
    delay(200);
    setting_device_num();
  }

  if (green_touch == 0) {
    Beep();
    endstate = true;
    display_current_params();
  }

  if (endstate == false) setting_FR();
}


/********************************************************
  setting the device number of castle fed
  numbers range from 0 to 19
********************************************************/
void setting_device_num() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 60);
  display.print(CSL);
  display.refresh();

  if ((millis() - menustart) > 250) {
    display.fillRect(80, 60, 25, 12, WHITE);
    display.refresh();
    delay(5);
    menustart = millis();
  }

  if (red_touch == 0) {
    Beep();
    CSL++;
    if (CSL > 19) CSL = 0;
    delay(200);
  }

  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 60, 25, 12, WHITE);
    display.refresh();
    display.setCursor(80, 60);
    display.print(CSL);
    display.refresh();
    endstate = true;
    delay(200);
    setting_open_duration();
  }

  if (green_touch == 0) {
    Beep();
    endstate = true;
    display_current_params();
  }

  if (endstate == false) setting_device_num();
}

/////////////////////////
// open duration
void setting_open_duration() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 72);
  display.print(open_duration);
  display.refresh();

  if ((millis() - menustart) > 250) {
    display.fillRect(80, 72, 25, 12, WHITE);
    display.refresh();
    delay(5);
    menustart = millis();
  }

  if (red_touch == 0) {
    Beep();
    open_duration += 10;
    if (open_duration > 120) open_duration = 10;
    delay(100);
  }

  if (blue_touch == 0) {
    Beep();
    display.setCursor(80, 72);
    display.print(open_duration);
    display.refresh();
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(openpos);
    delay(300);
    myservo.detach();
    digitalWrite(13, LOW);
    endstate = true;
    setting_open_position();
  }

  if (green_touch == 0) {
    Beep();
    endstate = true;
    display_current_params();
  }

  if (endstate == false) setting_open_duration();
}

/********************************************************
  setting position can set the position of hopper when open,
********************************************************/
void setting_open_position() {

  display.fillRect(115, 20, 60, 12, WHITE);
  display.setCursor(115, 20);
  display.println("Decrease");
  display.setCursor(116, 20);
  display.println("Decrease");

  display.fillRect(115, 100, 60, 12, WHITE);
  display.setCursor(115, 100);
  display.println("Increase");
  display.setCursor(116, 100);
  display.println("Increase");
  display.refresh();


  endstate = false;
  read_buttons();
  display.setCursor(80, 84);
  display.print(openpos);
  display.refresh();

  if ((millis() - menustart) > 250) {
    display.fillRect(80, 84, 25, 12, WHITE);
    display.refresh();
    delay(5);
    menustart = millis();
  }

  if (red_touch == 0) {
    Beep();
    delay(100);
    openpos += 10;
    digitalWrite(13, HIGH);
    myservo.attach(10);

    //slowly move servo to new openpos
    for (int move = openpos - 10; move < openpos; move++) {
      myservo.write(move);
      delay(50);
    }

    myservo.detach();
    digitalWrite(13, LOW);

    if (openpos > 90) openpos = 0;
  }

  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 84, 25, 12, WHITE);
    display.setCursor(80, 84);
    display.print(openpos);
    display.refresh();
    digitalWrite(13, HIGH);
    myservo.attach(10);
    myservo.write(closedpos);
    delay(300);
    myservo.detach();
    digitalWrite(13, LOW);
    endstate = true;
    setting_closed_position();
  }

  if (green_touch == 0) {
    Beep();
    delay(100);
    openpos -= 10;
    digitalWrite(13, HIGH);
    myservo.attach(10);

    //slowly move servo to new openpos
    for (int move = openpos + 10; move > openpos; move--) {
      myservo.write(move);
      delay(50);
    }

    myservo.detach();
    digitalWrite(13, LOW);

    if (openpos > 90) openpos = 90;
  }

  if (endstate == false) setting_open_position();
}

void setting_closed_position() {
  endstate = false;
  read_buttons();
  display.setCursor(80, 96);
  display.print(closedpos);
  display.refresh();

  if ((millis() - menustart) > 250) {
    display.fillRect(80, 96, 25, 12, WHITE);
    display.refresh();
    delay(5);
    menustart = millis();
  }

  if (red_touch == 0) {
    Beep();
    delay(100);
    closedpos += 10;
    digitalWrite(13, HIGH);
    myservo.attach(10);

    //slowly move servo to new closedpos
    for (int move = closedpos - 10; move < closedpos; move++) {
      myservo.write(move);
      delay(50);
    }

    myservo.detach();
    digitalWrite(13, LOW);
    if (closedpos > 140) closedpos = 140;
  }

  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 96, 25, 12, WHITE);
    display.setCursor(80, 96);
    display.print(closedpos);
    display.refresh();
    endstate = true;
    display_current_params();
  }

  if (green_touch == 0) {
    Beep();
    delay(100);
    closedpos -= 10;
    digitalWrite(13, HIGH);
    myservo.attach(10);

    //slowly move servo to new openpos
    for (int move = closedpos + 10; move > closedpos; move--) {
      myservo.write(move);
      delay(50);
    }
    myservo.detach();
    digitalWrite(13, LOW);
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
  update display of the total number of approaches and feed events
*********************************************************/
void update_display() {
  display.fillRect(0, 0, 168, 128, WHITE);  //clear screen

  display.setCursor(35, 14);
  display.println("Tumble!");
  display.setCursor(36, 14);
  display.println("Tumble!");

  digitalWrite(13, LOW);
  read_buttons();
  display.setCursor(134, 100);
  display.println("Reset");
  display.setCursor(135, 100);
  display.println("Reset");

  display.drawRect(5, 5, 104, 110, BLACK);
  display.drawRect(2, 2, 110, 116, BLACK);

  display.setCursor(12, 30);
  display.print("Mode: ");
  display.setCursor(80, 30);
  mode == 1 ? display.print("Free") : display.print("Prox");

  display.setCursor(12, 42);
  display.print("ProxTime: ");
  display.setCursor(80, 42);
  display.print(FR);
  display.setCursor(12, 56);
  display.print("Device#: ");
  display.setCursor(80, 56);
  display.print(CSL);

  display.drawFastHLine(10, 70, 80, BLACK);

  display.setCursor(12, 78);
  display.print("Approach: ");
  display.setCursor(80, 78);
  display.print(ApproachCount);
  display.setCursor(12, 90);
  display.print("Feed: ");
  display.setCursor(80, 90);
  display.print(FeederCount);

  DisplayBattery();

  DateTime now = rtc.now();
  display.setCursor(5, 128);
  display.fillRect(5, 127, 200, 60, WHITE);
  if (now.month() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.month());
  display.print("-");
  if (now.day() < 10)
    display.print('0');  // Trick to add leading zero for formatting
  display.print(now.day());
  display.print("-");
  display.print(now.year() % 100);
  display.print("     ");
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
      display.fillRect(0, 0, 200, 150, WHITE);
      display.setCursor(50, 50);
      display.print("RESETTING...");
      display.refresh();
      Beep();
      delay(200);
      Beep();
      delay(200);
      Beep();
      delay(200);
      Beep();

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
  display.setTextSize(2);
  display.setRotation(1);
  display.setCursor(5, 20);
  display.println("Check SD card");

  //Here's a fun riddle for users who don't have an SD card to ponder 
  display.setTextSize(1);
  display.setCursor(5, 60);
  display.println("I'm smaller than a mouse");
  display.setCursor(5, 70);
  display.println("but I can fill up a house.");
  display.setCursor(5, 85);
  display.println("What am I?");

  display.refresh();
  while (1);
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
