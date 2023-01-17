
int set_pos;
int nums = 0;
int dnums = 0;




/********************************************************
 setting the device number of castle fed
 when device is powered on, press b once to
 go to the device setting mode. press c to 
 increment the device number. numbers range
 from 0 to 19
********************************************************/

int settting_device_num(int cur_pos) { // also display freefeed on screeen 
left_touch = digitalRead(A1); // left
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  display.println("now setting Device #");
  display.setCursor(0, 15);
  display.println("Press Button C :>");
  display.setCursor(0, 25);
  display.print("Device: ");
  display.print(CSL);
  display.refresh();
  
  if(left_touch == 1){
    delay(100);
        dnums += 1;
      }
  delay(500);
  return dnums % 20;
}




/********************************************************
  setting position can set the position of left feeding space, 
  middle block, and right feeding space. after the use finish 
  setting the device number(pressed button B once), they can 
  choose to directly start the program by pressing button A or 
  continue pressing button B to set position. press C to move
  motor to the desirable pos and press b to go to the next 
  position you want to set. after finish setting press A to 
  start running
********************************************************/
int setting_position(int cur_pos) {

  left_touch = digitalRead(A1); // left
  ReadBatteryLevel();
  //currentpos = analogRead(A5);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  display.println("Press B: switch");
  display.setCursor(0, 10);
  display.println("Press C: move");
  display.setCursor(0, 20);
  display.println("Press A: start");
  display.setCursor(0, 30);
  display.println("Cur Pos from L to R: ");
  display.setCursor(0, 40);
  display.print(leftpos);
  display.print(" ");
  display.print(middlepos);
  display.print(" ");
  display.println(rightpos);
  display.setCursor(0, 55);
  display.print("Bat V: ");
  display.println(measuredvbat);
  display.refresh();
  
  if( left_touch == 1){
    delay(100);
        nums += 10;
        myservo.attach(10);
        myservo.write(nums % 180);
      }
  set_pos = nums % 180;
  delay(500);
  return set_pos;
}




/********************************************************
  update display of the total number of left and right poke whenever left or right button
  is pressed. during the 20s window proceeding the button press, the function will also update
  on the number of feeding and feeding duration. the current battery level and  
  time elapsed is also displayed
*********************************************************/
void update_display() {
  ReadBatteryLevel();
  //currentpos = analogRead(A5);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  display.print("Pos:");
  display.print(currentpos);
  display.print(" Time:");
  display.println(millis() / 1000);

  display.setCursor(0, 15);
  display.print("Poke L: ");
  display.print(leftPokeCount);
  display.setCursor(60, 15);
  display.print(" Dur: ");
  display.println(leftPokeDur);

  display.setCursor(0, 25);
  display.print("Poke R: ");
  display.print(rightPokeCount);
  display.setCursor(60, 25);
  display.print(" Dur: ");
  display.println(rightPokeDur);

  display.setCursor(0, 35);
  display.print("Feed: ");
  display.print(leftFeederCount);
  display.setCursor(60, 35);
  display.print(" Dur: ");
  display.println(leftFeederDur);


  display.setCursor(0, 55);
  display.print("Bat V: ");
  display.print(measuredvbat);
  display.setCursor(80, 55);
  display.print("CSL: ");
  display.print(" ");
  display.print(CSL);
  display.print(" ");
  display.refresh();
  inputtriggered = 0;
}


/********************************************************
  Display SD Card error
********************************************************/
void DisplaySDError() {
  Blink (13, 50, 3);
  delay (25);
  Blink (8, 50, 3);
  delay (25);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(10, 10);
  display.println("Check SD card!");
  display.refresh();
}
