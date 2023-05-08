void calibrate_servo () {
  right_touch = digitalRead(A0); // RIGHT
  start_touch = digitalRead(A3);

  if (right_touch == 1) {// re-add debounce in later
    count_pos++;
    delay(100);
  }
  if (start_touch == 1) { // both pressed
    toggle = true;
    CreateFile();
    move_left(leftpos);
//    move_center(middlepos);
    writeConfigFile();
    update_display();
  }

  if (count_pos % 5 == 1) { // set device #
    CSL = settting_device_num(1);
  }
  else if (count_pos % 5 == 2) { // set left
    leftpos = setting_position(2);
  }
  else if (count_pos % 5 == 3) { // set middle
    rightpos = setting_position(3);
  }
  else if (count_pos % 5 == 4) { // set middlepos
    middlepos = setting_position(4);
  }
  else { // =0 // default device # and defualt pos
    fromsd = setting_position(0);
  }
}
