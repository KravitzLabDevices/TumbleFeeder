/* Castle Feeder v 0.1.0
    Lex Kravitz 10-26-21
*/

/********************************************************
  Setup code
********************************************************/
#include "a_Header.h" //See "a_Header.h" for #defines and other constants 
int lastButtonState;
int currentButtonState;
bool toggle = false;
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
int middlepos = 467; // temp here 

void setup() {
  startup();
  currentButtonState = digitalRead(BUTTON_B);
}



void loop() {
  unsigned long current = millis();
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(BUTTON_B);
  if(lastButtonState = HIGH &&currentButtonState ==LOW){
    toggle = true;
    writeConfigFile();
    }

  if(toggle == true){
      if(current>=next_interval){
      update_display();
      check_inputs(middlepos);
      serial_out();
      next_interval = current+display_interval;
      }
    }else{
     middlepos = set_middle(); 
      }


  

}
