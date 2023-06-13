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

int fromsd;
int CSL;
int count_pos = 0; // 0 initialize count_pos here for switching between l,r,m using %

int left_touch;
int right_touch;
int start_touch;
int feed_touch;
boolean buttonLow = false;
boolean freefeed;
int analog_pos;
int *pt_middle = &analog_pos;
unsigned int wake_counter = 0;
/*****************************************************************
     Set up screen
 *****************************************************************/

void setup() {
  Serial.begin(9600);
  startup();
  display.begin();
  display.clearDisplay();

}

int margin = 10;
void loop() {
  while (!toggle) {
    calibrate_servo();
  }
  doWork();
  LowPower.sleep(5000);
  wake_counter++;
}

void left_interrupt() {
  left_touch = 1;
}

void right_interrupt() {
  right_touch = 1;
}

void feed_interrupt() {
  feed_touch = 1;
}

void interrupt() {
}


/********************************************************
  check for user button touch and start the device
********************************************************/
void doWork() {
  unsigned long current = millis();
  if (current >= next_interval && freefeed == false) {
    check_inputs(middlepos, leftpos); // put in all three position
    next_interval = current + display_interval;
    count_pos = 0;
  }
  else if (current >= next_interval && freefeed == true) {
    if (wake_counter % 180 == 0) {
      move_center(middlepos);
      move_left(leftpos);
      leftFeederCount--;
      logData();
    }
    free_inputs(middlepos, leftpos);
    next_interval = current + display_interval;
    count_pos = 0;
  }

}
