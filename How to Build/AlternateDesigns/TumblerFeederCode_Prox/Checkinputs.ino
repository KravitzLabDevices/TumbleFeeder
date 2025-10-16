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
  checkFeeder();

  // Process left touches
  if (left_touch == 1) {
    unsigned long startTime = millis();  // Start time for touch duration
    while (digitalRead(A2) == LOW) {
      delay(1);
    }
    leftPokeCount++;
    leftPokeDur = millis() - startTime;  // Calculate duration
    update_display();
    logData();
    left_touch = 0;

    leftPokeDur = 0;
  }
}
  /********************************************************
  General function to check inputs for left, right, and feeder
********************************************************/
  void check_inputs(int closedpos, int openpos, unsigned long open_duration) {
    checkRight();
    checkLeft(closedpos, openpos, open_duration);
    checkFeeder();
  }

  /********************************************************
  Check whether the mice touch the left button.
  If touched, log the event and open the chamber.
********************************************************/
  void checkLeft(int closedpos, int openpos, unsigned long open_duration) {
    if (left_touch == 1) {
      unsigned long startTime = millis();  // Start time for touch duration
      while (digitalRead(A2) == LOW) {
        delay(1);
      }
      leftPokeCount++;
      leftPokeDur = millis() - startTime;  // Calculate duration
      update_display();
      logData();
      left_touch = 0;
      leftPokeDur = 0;

      // Check if FR condition is met to open feeder
      if (FR == 0) FR = 1;  // Ensure FR is not 0
      if (leftPokeCount % FR == 0) {
        feeder_open(openpos);
        unsigned long feederStart = millis();

        while (millis() - feederStart < (open_duration * 1000)) {  // Feeder open period
          checkFeeder();                                           // Check and log feed touches during open period

          // Display remaining open time and status
          display.fillRect(122, 36, 28, 24, WHITE);
          display.setCursor(122, 48);
          display.println("Feeding");
          display.setCursor(122, 60);
          display.print(((open_duration * 1000) - (millis() - feederStart)) / 1000);
          display.refresh();

          update_display();  // Update other display elements
        }

        display.fillRect(122, 36, 28, 24, WHITE);
        feeder_close(closedpos);
      }  // Reset after logging
    }
  }
  /********************************************************
  Check whether the mice touch the right button.
********************************************************/
  void checkRight() {
    if (right_touch == 1) {
      unsigned long startTime = millis();  // Start time for touch duration
      while (digitalRead(A0) == LOW) {
        delay(1);
      }
      rightPokeCount++;
      rightPokeDur = millis() - startTime;  // Calculate duration
      update_display();

      // Log the touch and reset relevant variables
      logData();
      right_touch = 0;
      rightPokeDur = 0;  // Reset after logging
    }
  }
  /********************************************************
  Check whether the mouse touches the feeding rod.
********************************************************/
  void checkFeeder() {
    if (feed_touch == 1) {
      unsigned long startTime = millis();  // Start time for touch duration
      while (digitalRead(A1) == LOW) {
        delay(1);
      }
      FeederCount++;
      leftFeederDur = millis() - startTime;  // Calculate duration
      update_display();

      // Log the touch and reset relevant variables
      logData();
      feed_touch = 0;
      leftFeederDur = 0;  // Reset after logging
    }
  }