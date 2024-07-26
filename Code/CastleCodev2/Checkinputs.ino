void read_buttons() {
  red_touch = digitalRead(A3);
  green_touch = digitalRead(1);
  blue_touch = digitalRead(A5);
}

/********************************************************
  free feeding paradigm. servo move every free_feed
  interval
********************************************************/
void free_inputs(int closedpos, int openpos) {
  checkRight();
  if (left_touch == 1) {
    int Start  = millis();
    inputtriggered = 1;
    leftPokeCount++;
    leftPokeDur = millis() - Start;
    update_display();
    leftPokeDur = 0;
    leftFeederDur = 0;
    left_touch = 0;
    delay(250);
  }
  checkFeeder();
}

void check_inputs(int closedpos, int openpos, unsigned long open_duration) {
  checkRight();
  checkLeft(closedpos, openpos, open_duration);
  checkFeeder();
}

/********************************************************
  check whether the mice touch the left button, if so
  chamber open. during the opening period
  we check whether they are feeding.
********************************************************/
void checkLeft(int closedpos, int openpos, unsigned long open_duration) {
  if (left_touch == 1) {
    int Start = millis();
    inputtriggered = 1;
    leftPokeCount++;
    leftPokeDur = millis() - Start;
    update_display();

    //If the FR ratio has been reached
    if (leftPokeCount % FR == 0) {
      feeder_open(openpos);

      feed_touch = 0;

      leftstart = millis();
      while (millis() - leftstart < (open_duration * 1000)) {  //while feeder is open
        if (digitalRead(A1) == LOW)   {
          feed_touch = 1;
        }
        checkFeeder();

        display.fillRect(122, 36, 28, 24, WHITE);
        display.setCursor(122, 48);
        display.println("Feeding");
        display.setCursor(122, 60);
        display.print(((open_duration * 1000) - (millis() - leftstart)) / 1000);;
        display.refresh();

        update_display();

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////
        //If we want to extend the open interval if the mouse touches, we can add code here to detect touches.
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////
      }

        display.fillRect(122, 36, 28, 24, WHITE);
      logData();
      leftPokeDur = 0;
      leftFeederDur = 0;
      feeder_close(closedpos);

      left_touch = 0;
      shake();
    }
  }
}

/********************************************************
  check whether the mice touch the right button
********************************************************/
void checkRight() {
  if (right_touch == 1) {
    int Start  = millis();
    inputtriggered = 2;
    rightPokeCount++;
    rightPokeDur = millis() - Start;
    update_display();

    logData();
    rightPokeDur = 0;
    rightFeederCount = 0;
    rightFeederDur = 0;
    right_touch = 0;
    delay(250);
  }
}

/********************************************************
  check whether mouse is touching the metal rod for feeding
********************************************************/
void checkFeeder() {

  if (feed_touch == 1) { // touch3
    int Start = millis();
    inputtriggered = 3;
    FeederCount++;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///// THIS NEXT CODE IS FOR TAKING TRIGGERED VIDEOS WITH BONSAI, IF YOU'RE NOT DOING THAT LEAVE IT COMMENTED OUT!
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //    //send a pulse to trigger Bonsai for video recording
    //    digitalWrite (11, HIGH);
    //    delay (100);
    //    digitalWrite (11, LOW);
    //    delay (30000);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    leftFeederDur = leftFeederDur + (millis() - Start);
    while (millis() - Start <= 250) {
      digitalWrite(12, HIGH); ////
    }
    digitalWrite(12, LOW);
    update_display();
    logData(); // added logdata here
    leftFeederDur = 0;
    feed_touch = 0;
  }
}
