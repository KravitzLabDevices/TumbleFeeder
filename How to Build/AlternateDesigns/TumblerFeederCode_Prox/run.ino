/********************************************************
  check for user button touch and start the device
********************************************************/
void run() {

  unsigned long current = millis();

  if (mode == 0) { //Prox mode
    check_inputs(closedpos, openpos, open_duration);
    if (current >= next_interval) {
      next_interval = current + display_interval;
    }
  }

  else if (mode == 1) {  //Free mode
    free_inputs(closedpos, openpos);
    if (current >= next_interval) {
      next_interval = current + display_interval;
      if (wake_counter % 180 == 0) {
        shake_food();
      }
    }
  }
}
