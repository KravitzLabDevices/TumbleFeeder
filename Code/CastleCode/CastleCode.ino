/* Castle Fed
  by Lex Kravitz & Yiyan Pan
  Last Modified April 12th, 2023
*/

/*****************************************************************
     Set up device
 *****************************************************************/
#include "a_header.h" //See "a_Header.h" for #defines and other constants 
void setup() {
  Serial.begin(9600);
  startup();
  display.begin();
  display.clearDisplay();  
  display_current_params(0);
  while (!SessionStarted) {
    Setup();
  }
}

/*****************************************************************
     Run device
 *****************************************************************/
void loop() {
  doWork();
  LowPower.sleep(5000);
  wake_counter++;
}

/********************************************************
  check for user button touch and start the device
********************************************************/
void doWork() {
  boolean active_flag = set_active();
  // change to case switch
  unsigned long current = millis();
  if (current >= next_interval && freefeed == false) {
    check_inputs(middlepos, leftpos, open_interval); // put in all three position
    next_interval = current + display_interval;
  }
  else if (current >= next_interval && freefeed == true && active_flag) {

    free_inputs(middlepos, leftpos);
    next_interval = current + display_interval;
    if (wake_counter % 180 == 0) {
      shake_food();
    }
    else if (current >= next_interval && freefeed == true && !active_flag) {
      if (wake_counter % 180 == 0) {
        shake_food();
        move_center(middlepos);
      }
    }
  }
}
