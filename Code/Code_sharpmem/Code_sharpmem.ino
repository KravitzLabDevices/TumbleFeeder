/* Castle Fed 
 by Lex Kravitz & Yiyan Pan
 Last Modified April 12th, 2023
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
int analog_pos;
int *pt_middle = &analog_pos; 
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
  if (toggle == true) {
    if (current >= next_interval && freefeed == false) {
      check_inputs(middlepos, leftpos, rightpos); // put in all three position
      next_interval = current + display_interval;
      count_pos = 0;
    }
    if (current >= next_interval && freefeed == true) {
      free_inputs(middlepos, leftpos, rightpos);
      next_interval = current + display_interval;
      count_pos = 0;
    }
  } else {
    calibrate_servo ();
  }
}
