
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


  if (count_pos % 8 == 1) { // set feed paradigm
    freefeed = set_feed_paradigm();
  }
  else if (count_pos % 8 == 2) { // set open
    leftpos = setting_position(2);
  }
  else if (count_pos % 8 == 3) { // set close
    middlepos = setting_position(3);
  }
  else if (count_pos % 8 == 4) { //set device #
     CSL = settting_device_num(4);
  }
  else if(count_pos % 8 == 5){ // set open interval
    open_interval = setting_open_interval();
  }
  else if(count_pos % 8 == 6){ // set on/off time for freefeed mode
    on_hour = setting_on_hour();
  }
  else if(count_pos % 8 == 7){ // set on/off time for freefeed mode
    off_hour = setting_off_hour();
  }
  else { // =0 // default device # and defualt pos
    display_current_params(0);
  }
}
