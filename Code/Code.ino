/* Castle Feeder v 0.1.0
    Lex Kravitz 10-26-21
*/

/********************************************************
  Setup code
********************************************************/
#include "a_Header.h" //See "a_Header.h" for #defines and other constants 
int B_lastButtonState = HIGH;
int B_currentButtonState = HIGH;

//
int A_lastButtonState;
int A_currentButtonState;

bool toggle = false;
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
int middlepos ;
int leftpos ;
int rightpos ;
int fromsd;
int CSL;
int count_pos = 0; // initialize count_pos here for switching between l,r,m using %
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

boolean buttonLow = false;


void setup() {
  startup();
  Serial.begin(9600);
  
}


/// NEED TO DEBOUNCE THE BUTTON HERE

int margin = 10;
void loop() {
  doWork();
}





void doWork() {
  unsigned long current = millis();
  int reading = digitalRead(BUTTON_B);

  if (reading != B_lastButtonState) { // start button B press timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != B_currentButtonState) {
      B_currentButtonState = reading;
      if (B_currentButtonState == LOW) {
        count_pos++;
      }
    }
  }
  B_lastButtonState = reading;

  A_lastButtonState = A_currentButtonState;
  A_currentButtonState = analogRead(BUTTON_A);
  if (A_lastButtonState > 500 && A_currentButtonState < 100) { // button B pressed
    toggle = true;
    CreateFile();
    writeConfigFile();
  }



  if (toggle == true) {
    if (current >= next_interval) {
      //update_display();
      LowPower.sleep(300);
      myservo.detach();
      digitalWrite(10,LOW);
      check_inputs(middlepos, leftpos, rightpos); // put in all three position
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
