
/********************************************************
  free feeding paradigm. servo move every free_feed
  interval
********************************************************/
void free_inputs(int middlepos, int leftpos) {

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
  Lcheckfeed();
}



/********************************************************
  fr-1 feeding paradigm. servo move when the left button is
  pressed. servo move to open HFD-chamber for fr-1 feeding
  interval
********************************************************/
void check_inputs(int middlepos, int leftpos, unsigned long open_interval) {
  checkRight();
  checkLeft(middlepos, leftpos, open_interval);
}



/********************************************************
  check whether the mice touch the left button, if so
  chamber open for 30s. during the opening period
  we check whether they are feeding.
********************************************************/
void checkLeft(int middlepos, int leftpos, unsigned long open_interval) {
  if (left_touch == 1) {

    int Start = millis();
    inputtriggered = 1;
    leftPokeCount++;
    leftPokeDur = millis() - Start;
    update_display();
    move_left(leftpos);
    feed_touch = 0;

    leftstart = millis();
    while (millis() - leftstart < open_interval) {
      Lcheckfeed();
    }
    logData();
    leftPokeDur = 0;
    leftFeederDur = 0;
    move_center(middlepos);
    
    left_touch = 0;
    shake();
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
void Lcheckfeed() {
  if (feed_touch == 1) { // touch3
    int Start = millis();
    inputtriggered = 3;
    leftFeederCount++;
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
