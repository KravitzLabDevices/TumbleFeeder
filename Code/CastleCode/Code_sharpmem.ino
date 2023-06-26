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
unsigned long open_interval;
int left_touch;
int right_touch;
int start_touch;
int feed_touch;
boolean buttonLow = false;
boolean freefeed;
unsigned int wake_counter = 0;
// allow user to set open and off hour during the freefeed mode

int on_hour;
int off_hour;

boolean open_now = true;

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
  //LowPower.sleep(5000);
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
    if (wake_counter % 150 == 0) {
      shake_food();
    }

  }
}

/////////////////////////////////////////////////////////////
boolean set_active() {
  DateTime t = rtc.now();
  Serial.println(t.hour());
  if ((off_hour - on_hour) < 0)
  {
    if (t.hour() >= on_hour || t.hour() <= off_hour) {
      return true;
    } else {
      return false;
    }
  }
  else {
    Serial.println("not overnight");
    if (t.hour() >= on_hour && t.hour() <= off_hour) {
      Serial.println("active");
      return true;
    } else {
      return false;
    }
  }
}



void shake_food() {
  shake ();
  move_center(middlepos);
  move_left(leftpos);
  leftFeederCount--;
  logData();
}
