/* Castle Fed
  by Lex Kravitz & Yiyan Pan
  Last Modified December 3rd, 2024
*/

/*****************************************************************
     Set up device
 *****************************************************************/
#include "a_header.h"  //See "a_Header.h" for #defines and other constants

void setup() {
  startup();
  while (!SessionStarted) {
    display_current_params();
  }
}

/*****************************************************************
     Run device
 *****************************************************************/
void loop() {
  checkProx();
  run();
  update_display();
}