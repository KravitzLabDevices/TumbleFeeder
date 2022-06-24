/* Castle Feeder v 0.1.0
    Lex Kravitz 10-26-21
*/

/********************************************************
  Setup code
********************************************************/
#include "a_Header.h" //See "a_Header.h" for #defines and other constants 
int B_lastButtonState = HIGH;
int B_currentButtonState = HIGH;


int C_lastButtonState;
int C_currentButtonState;

bool toggle = false;
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
int middlepos = 467; // temp here 
int leftpos = 331;
int rightpos = 639;
int count_pos = 0; // initialize count_pos here for switching between l,r,m using %



unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;




void setup() {
  startup();
  C_currentButtonState = digitalRead(BUTTON_C);
}


/// NEED TO DEBOUNCE THE BUTTON HERE 


void loop() {
  unsigned long current = millis();
  int reading = digitalRead(BUTTON_B);

  if(reading!=B_lastButtonState){ // start button B press timer 
    lastDebounceTime = millis();
    }
    
   if((millis() - lastDebounceTime) > debounceDelay){
    if(reading!=B_currentButtonState){
      B_currentButtonState = reading;
      if(B_currentButtonState == LOW){
        count_pos++;
        }
      }
   }
   B_lastButtonState = reading;
   
  C_lastButtonState = C_currentButtonState;
  C_currentButtonState = digitalRead(BUTTON_C);

   if(C_lastButtonState = HIGH &&C_currentButtonState ==LOW){ // button B pressed 
    toggle = true;
    writeConfigFile();
    }

    

  if(toggle == true){
      if(current>=next_interval){
      update_display();
      check_inputs(middlepos,leftpos,rightpos); // put in all three position 
      serial_out();
      next_interval = current+display_interval;
      }
    }else{
      if(count_pos%3 == 0){
        middlepos = setting_position(0); 
        }
      else if(count_pos%3 == 1){
        leftpos = setting_position(1);
        }
      else{ // ==2
        rightpos = setting_position(2);
          }
      }
}
