
int right_b_pulse = 11; // right // 12 // 10 for device 03fa
int left_b_pulse = 11; // left change from 12 to 10  // 11 for device 03fa
bool left_feed_flag = false;
bool right_feed_flag = false;
bool first_touch = false;
bool rotating = false;
const unsigned long freefeed_interval = 864000; // 864000
unsigned long next_freefeed_interval = 0;

int feed_touch;


/********************************************************
  free feeding paradigm. servo move every free_feed
  interval
********************************************************/
void free_inputs(int middlepos, int leftpos, int rightpos) {
  while (millis() <= next_freefeed_interval) {
    Lcheckfeed();
  }
  move_center(middlepos);
  move_left(leftpos);
  next_freefeed_interval = millis() + freefeed_interval;
}



/********************************************************
  fr-1 feeding paradigm. servo move when the left button is
  pressed. servo move to open HFD-chamber for fr-1 feeding
  interval
********************************************************/
void check_inputs(int middlepos, int leftpos, int rightpos) {

  //Check touch sensors
  right_touch = digitalRead(A0); // RIGHT
  if (right_touch == 1) {
    left_touch = 0;
    int Start  = millis();
    inputtriggered = 2;
    rightPokeCount++;

    rightPokeDur = millis() - Start;
    update_display();

    first_touch = false;
    logData();
    rightPokeDur = 0;
    rightFeederCount = 0;
    rightFeederDur = 0;
  }


  //left poke
  left_touch = digitalRead(A1);
  if (left_touch == 1) {
    int Start = millis();
    inputtriggered = 1;
    leftPokeCount++;

    leftPokeDur = millis() - Start;
    update_display();
    move_left(leftpos);

    leftstart = millis();

    while ((millis() - leftstart) < 10000) {
      feed_touch = digitalRead(A2);
      if (feed_touch == 1 && first_touch == false) { // if touch left bar
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




/********************************************************
  check whether mouse is touching the metal rod for feeding
********************************************************/
void Lcheckfeed() {
  feed_touch = digitalRead(A2);
  if (feed_touch == 1) { // touch3
    int Start = millis();
    inputtriggered = 3;
    leftFeederCount++;
    //    while (millis() - Start <= 250) {
    //      digitalWrite(left_b_pulse, HIGH);
    //    }
    //
    //    digitalWrite(left_b_pulse, LOW);
    leftFeederDur = leftFeederDur + (millis() - Start);
    update_display();
    logData(); // added logdata here
    leftFeederDur = 0;
    left_feed_flag = true;
  }
}
