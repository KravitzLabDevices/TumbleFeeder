
void calibrate_servo () {
  int green_touch = digitalRead(1);
  int blue_touch = digitalRead(A5);

  if (green_touch == 0) {
    count_pos--;
    delay(100);
  }
  if (blue_touch == 0) {
    count_pos++;
    delay(100);
  }

  if (count_pos < 0) {
    count_pos = 7;
  }
  else if (count_pos == 0) { // =0 // default device # and defualt pos
    display_current_params(0);
  }
  else if (count_pos == 1) { // set feed paradigm
    freefeed = set_feed_paradigm();
  }
  else if (count_pos == 2) { // set on/off time for freefeed mode
    on_hour = setting_on_hour();
  }
  else if (count_pos  == 3) {  // set on/off time for freefeed mode
    off_hour = setting_off_hour();
  }
  else if (count_pos == 4) { //set device #
    CSL = settting_device_num(4);
  }
  else if (count_pos == 5) { // set open interval
    open_interval = setting_open_interval();
  }
  else if (count_pos == 6) { // set OPEN
    leftpos = setting_position(2);
  }
  else if (count_pos == 7) { // set CLOSE
    middlepos = setting_position(3);
  }
  else {
    count_pos = 0;
  }
}
