
void calibrate_servo () {
  int green_touch = digitalRead(1); 
  int red_touch = digitalRead(A3);
  
  if (green_touch == 0) {
    count_pos++;
    delay(100);
  }
  if (red_touch == 0) {  
    toggle = true;
    CreateFile();
    display_mouse();
    writeConfigFile();
    update_display();
  }


  if (count_pos % 5 == 1) { // set feed paradigm
    freefeed = set_feed_paradigm();
  }
  else if (count_pos % 5 == 2) { // set open
    leftpos = setting_position(2);
  }
  else if (count_pos % 5 == 3) { // set close
    middlepos = setting_position(3);
  }
  else if (count_pos % 5 == 4) { //set device #
     CSL = settting_device_num(4);
  }
  else { // =0 // default device # and defualt pos
    fromsd = setting_position(0);
  }
}
