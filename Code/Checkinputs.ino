
int right_b_pulse = 12; // right // 12 // 10 for device 03fa
int left_b_pulse = 10; // left change from 12 to 10  // 11 for device 03fa
bool left_feed_flag = false;
bool right_feed_flag = false;
bool first_touch = false;

const unsigned long freefeed_interval = 864000; // 864000
unsigned long next_freefeed_interval = 0;

void free_inputs(int middlepos, int leftpos, int rightpos){
  touch0 = qt_0.measure();
  touch1 = qt_1.measure();
  Lcheckfeed();
  if ((touch0 - touch0base) > 50) { // R, record button press but do not turn insert 
    unsigned long Start  = millis();
    inputtriggered = 2;
    rightPokeCount++;
    while ((qt_0.measure() - touch0base) > 50) {
      delay (1);
    }
    rightPokeDur = millis() - Start;
    update_display();
    logData();
    rightPokeDur = 0;
//    rightFeederCount = 0;
//    rightFeederDur = 0;
  }

  if ((touch1 - touch1base) > 50) { // L, record button press but do not turn insert 
    unsigned long Start = millis();
    inputtriggered = 1;
    leftPokeCount++;
    while ((qt_1.measure() - touch1base) > 50) {
      delay (1);
    }
    leftPokeDur = millis() - Start;
    update_display();
    logData();
    leftPokeDur = 0;
//    leftFeederCount = 0;
//    leftFeederDur = 0;
  }
  unsigned long move_start= millis();
  while (move_start>=next_freefeed_interval){
      move_left(leftpos);
      delay(1000);
      move_center(middlepos);
      delay(1000);
      move_left(leftpos);
      next_freefeed_interval = millis()+ freefeed_interval;
    }
}




void check_inputs(int middlepos, int leftpos, int rightpos) {

  //Check touch sensors
  touch0 = qt_0.measure();
  touch1 = qt_1.measure();
  Lcheckfeed();
//  Rcheckfeed();
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
    update_display();

    first_touch = false;
    logData();
    rightPokeDur = 0;
    rightFeederCount = 0;
    rightFeederDur = 0;
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
    update_display();
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


void Lcheckfeed() {
  touch3 = qt_3.measure();
  if ((touch3 - touch3base) > 50) { // touch3
    int Start = millis();
    inputtriggered = 3;
    leftFeederCount++;

    while (millis() - Start <= 250) {
      digitalWrite(left_b_pulse, HIGH);
    }
    while ((qt_3.measure() - touch3base) > 50) {
      delay (1);
    }
    digitalWrite(left_b_pulse, LOW);
    leftFeederDur = leftFeederDur + (millis() - Start);
    update_display();
    logData(); // added logdata here 
    leftFeederDur = 0;
    left_feed_flag = true;
  }
}

void baseline_touch() {
  touch0base = qt_0.measure();
  touch1base = qt_1.measure();
  touch2base = qt_2.measure();
  touch3base = qt_3.measure();
}
