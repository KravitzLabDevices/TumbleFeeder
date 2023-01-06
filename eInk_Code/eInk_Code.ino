/* Castle Feeder v 0.2.0
    Lex Kravitz + Yiyan Pan 11-25-22
*/

/********************************************************
  Setup code
********************************************************/
#include "a_Header.h"  //See "a_Header.h" for #defines and other constants

void setup() {
  startup();
}

void loop() {
  check_inputs(middlepos, leftpos, rightpos);  // put in all three position
  unsigned long displaytime = millis();
  if (millis() - displaytime > 10000) {
    update_display();
  }
}