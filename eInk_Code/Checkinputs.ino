void check_inputs(int middlepos, int leftpos, int rightpos) {
  //Check touch sensors
  touch0 = qt_0.measure();
  touch1 = qt_1.measure();
  Lcheckfeed();
  Rcheckfeed();
  //right poke
  if ((touch0 - touch0base) > 50) {
    Serial.println("right poke"); // yy
    int Start  = millis();
    inputtriggered = 2;
    rightPokeCount++;
    while ((qt_0.measure() - touch0base) > 50) {
      delay (1);
    }
    rightPokeDur = millis() - Start;
    move_right(rightpos);
    rightstart = millis();

    while ((millis() - rightstart) < opentime) {
      touch2 = qt_2.measure();
      if (((touch2 - touch2base) > 50) && first_touch == false) { // if touch left bar
        rightstart = millis(); // restart timer
        first_touch = true;
      }
      Rcheckfeed();
    }

    first_touch = false;
    logData();
    rightPokeDur = 0;
    rightFeederCount = 0;
    rightFeederDur = 0;
    move_center(middlepos);
  }


  //left poke
  if ((touch1 - touch1base) > 50) {
    int Start = millis();
    inputtriggered = 1;
    leftPokeCount++;
    while ((qt_1.measure() - touch1base) > 50) {
      delay (1);
    }
    leftPokeDur = millis() - Start;
    move_left(leftpos);
    leftstart = millis();

    while ((millis() - leftstart) < opentime) {
      touch3 = qt_3.measure();
      Serial.println(first_touch);
      if (((touch3 - touch3base) > 50) && first_touch == false) { // if touch left bar
        leftstart = millis(); // restart timer
        first_touch = true;
      }
      Lcheckfeed();
    }

    first_touch = false;
    logData();
    leftPokeDur = 0;
    leftFeederCount = 0;
    leftFeederDur = 0;
    move_center(middlepos);
  }
}

void Rcheckfeed() {
  touch2 = qt_2.measure();
  if ((touch2 - touch2base) > 50) { // touch3
    int Start = millis();
    inputtriggered = 4;
    rightFeederCount++;

    while (millis() - Start <= 250) {
      digitalWrite(right_b_pulse, HIGH);
    }
    digitalWrite(right_b_pulse, LOW);
    while ((qt_2.measure() - touch2base) > 50) {
      delay (1);
    }
    rightFeederDur = rightFeederDur + (millis() - Start);
    right_feed_flag = true;
  }
}


void Lcheckfeed() {
  touch3 = qt_3.measure();
  if ((touch3 - touch3base) > 50) { // touch3
    int Start = millis();
    inputtriggered = 3;
    leftFeederCount++;

    while (millis() - Start <= 250) {
      digitalWrite(left_b_pulse, HIGH);
    }
    digitalWrite(left_b_pulse, LOW);
    while ((qt_3.measure() - touch3base) > 50) {
      delay (1);
    }
    leftFeederDur = leftFeederDur + (millis() - Start);
    left_feed_flag = true;
  }
}

void baseline_touch() {
  touch0base = qt_0.measure();
  touch1base = qt_1.measure();
  touch2base = qt_2.measure();
  touch3base = qt_3.measure();
}