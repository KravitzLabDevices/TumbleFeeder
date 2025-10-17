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
  checkFeeder();

  // Process Prox detection
  if (mouse_detected == 1) {
    unsigned long startTime = millis();  // Start time for touch duration
    while (digitalRead(A2) == LOW) {
      delay(1);
    }
    FeederCount++;
    update_display();
    logData();
    mouse_detected = 0;
  }
}
/********************************************************
  General function to check prox and feeder touches
********************************************************/
void check_inputs(int closedpos, int openpos, unsigned long open_duration) {
  checkMousePresent(closedpos, openpos, open_duration);
  checkFeeder();
}

/********************************************************
  Check whether the mouse is present
  If so, log the event and open the chamber.
********************************************************/
void checkMousePresent(int closedpos, int openpos, unsigned long open_duration) {
  if (mouse_detected == 1) {
    FeederCount++;
    update_display();
    logData();
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
    timeout(5);  //5s timeout to ensure mouse is gone
    display.fillRect(122, 36, 28, 24, WHITE);
    feeder_close(closedpos);
    mouse_detected = 0;
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
    FeederDur = millis() - startTime;  // Calculate duration
    update_display();

    // Log the touch and reset relevant variables
    logData();
    feed_touch = 0;
    FeederDur = 0;  // Reset after logging
  }
}