/* Castle Feeder v 0.1.0
    Lex Kravitz 10-26-21
*/

/********************************************************
  Setup code
********************************************************/
#include "a_header.h" //See "a_Header.h" for #defines and other constants 
bool toggle = false;
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
int middlepos ;
int leftpos ;
int rightpos ;
int fromsd;
int CSL;
int count_pos = 0; // 0 initialize count_pos here for switching between l,r,m using %

int left_touch;
int right_touch;
int start_touch;
boolean buttonLow = false;
boolean freefeed = false;


/*****************************************************************
     Set up screen
 *****************************************************************/



void setup(void) {
  Serial.begin(9600);
  startup();
  display.begin();
  display.clearDisplay();
}

/// NEED TO DEBOUNCE THE BUTTON HERE

int margin = 10;
void loop(void) {

  doWork();
  LowPower.sleep();

}

void interrupt() {
  // This function will be called once on device wakeup
}


/********************************************************
  check for user button touch and start the device 
********************************************************/
void doWork() {
  unsigned long current = millis();
  right_touch = digitalRead(A0); // RIGHT 
  start_touch = digitalRead(A3);
  
  if (right_touch == 1) {// re-add debounce in later 
    count_pos++;
    delay(100);
  }
  if (start_touch==1) { // both pressed
    toggle = true;
    CreateFile();
    move_center(middlepos);
    writeConfigFile();
    update_display();
  }


  if (toggle == true) {
    if (current >= next_interval && freefeed == false) {
      check_inputs(middlepos, leftpos, rightpos); // put in all three position
      next_interval = current + display_interval;
      count_pos = 0;
    }
    if (current >= next_interval && freefeed == true) {
      Serial.println("freefeed mode");
      free_inputs(middlepos, leftpos, rightpos);
      next_interval = current + display_interval;
      count_pos = 0;
    }
  } else {
    if (count_pos % 5 == 1) { // set device #
      CSL = settting_device_num(1);
    }
    else if (count_pos % 5 == 2) { // set left
      leftpos = setting_position(2);
    }
    else if (count_pos % 5 == 3) { // set middle
      middlepos = setting_position(3);
    }
    else if (count_pos % 5 == 4) { // set right
      rightpos = setting_position(4);
    }
    else { // =0 // default device # and defualt pos
      fromsd = setting_position(0);
    }
  }

}
