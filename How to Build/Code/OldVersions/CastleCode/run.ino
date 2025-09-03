/********************************************************
  check for user button touch and start the device
********************************************************/
void run() {
  Serial.println (mode);

  //boolean active_flag = set_active();

  // change to case switch
  unsigned long current = millis();

  if (current >= next_interval && mode == 0) {
    check_inputs(closedpos, openpos, open_duration);  // put in all three position
    next_interval = current + display_interval;
  }

  else if (current >= next_interval && mode == 1) {
    free_inputs(closedpos, openpos);
    next_interval = current + display_interval;
    if (wake_counter % 180 == 0) {
      shake_food();
    }

    else if (current >= next_interval && mode == 0) {
      if (wake_counter % 180 == 0) {
        shake_food();
        feeder_close(closedpos);
      }
    }
  }
}
