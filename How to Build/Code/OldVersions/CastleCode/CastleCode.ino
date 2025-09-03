/* Castle Fed
  by Lex Kravitz & Yiyan Pan
  Last Modified April 12th, 2023
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
  run();
  LowPower.sleep(5000);
  wake_counter++;
  update_display();
}
