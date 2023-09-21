/********************************************************
  check for user button touch and start the device
********************************************************/
void run() {
  boolean active_flag = set_active();
  // change to case switch
  unsigned long current = millis();
  if (current >= next_interval && freefeed == false) {
    check_inputs(closedpos, openpos, open_duration);  // put in all three position
    next_interval = current + display_interval;
  } else if (current >= next_interval && freefeed == true && active_flag) {

    free_inputs(closedpos, openpos);
    next_interval = current + display_interval;
    if (wake_counter % 180 == 0) {
      shake_food();
    } else if (current >= next_interval && freefeed == true && !active_flag) {
      if (wake_counter % 180 == 0) {
        shake_food();
        move_center(closedpos);
      }
    }
  }
}