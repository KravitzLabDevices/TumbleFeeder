/* Castle Feeder v 0.1.0
    Lex Kravitz 10-26-21
*/

/********************************************************
  Setup code
********************************************************/
#include "a_Header.h" //See "a_Header.h" for #defines and other constants 
#define SHARP_SCK  5
#define SHARP_MOSI 6
#define SHARP_SS   9

#define VBATPIN A7
#define cardSelect 4

Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 144, 168);
#define BLACK 0
#define WHITE 1
int minorHalfSize;

bool toggle = false;
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
int middlepos ;
int leftpos ;
int rightpos ;
int fromsd;
int CSL;
int count_pos = 0; // 0 initialize count_pos here for switching between l,r,m using %


boolean buttonLow = false;

boolean freefeed = false;


/*****************************************************************
     Set up screen
 *****************************************************************/



void setup(void) {

  Serial.begin(9600);
  startup();
  Serial.println("hello");
  display.begin();
  display.clearDisplay();


}

/// NEED TO DEBOUNCE THE BUTTON HERE

int margin = 10;
void loop(void) {

  doWork();
}



void doWork() {
  //myservo.detach();
  //digitalWrite(10, LOW);
  //LowPower.sleep(200);

  unsigned long current = millis();

  touch0 = qt_0.measure(); // right
  touch1 = qt_1.measure(); // left

  if ((touch0 - touch0base) > 100) {
    count_pos++;
    delay(100);
  }
  if ((touch0 - touch0base) > 50 && (touch1 - touch1base) > 50) { // button A pressed
    toggle = true;
    CreateFile();
    writeConfigFile();
  }




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
