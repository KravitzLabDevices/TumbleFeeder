
int set_pos;

int A_lastButtonState = HIGH;
int A_currentButtonState = HIGH;
unsigned long A_lastDebounceTime = 0;
unsigned long A_debounceDelay = 50;




int nums=0;
  int setting_position(int cur_pos) {
  ReadBatteryLevel();
  currentpos = analogRead(A5);
  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Pos:");
  display.print(currentpos);
  display.print(" Time:");
  display.println(millis() / 1000);



  display.setCursor(0, 15);
  display.print("now setting 0m-1l-2r: ");
  display.print(cur_pos);
  
  display.setCursor(0, 55);
  display.print("Bat V: ");
  display.println(measuredvbat);
  display.display();

  int A_reading = digitalRead(BUTTON_A);
  if(A_reading!=A_lastButtonState){
    A_lastDebounceTime = millis();
    }
  if((millis()-A_lastDebounceTime) > debounceDelay){
    if(A_reading!=A_currentButtonState){
      A_currentButtonState = A_reading;
      if(A_currentButtonState == LOW){
        nums+=10; // moves 10 degrees everytime 
        myservo.write(nums%180);
        }
      }
    }

  set_pos = nums;
  Serial.print("servo pos: ");
  Serial.println(nums);
  return set_pos;
  }









void update_display() {
  ReadBatteryLevel();
  currentpos = analogRead(A5);
  display.clearDisplay();
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
  display.print("Feed L: ");
  display.print(leftFeederCount);
  display.setCursor(60, 35);
  display.print(" Dur: ");
  display.println(leftFeederDur);

  display.setCursor(0, 45);
  display.print("Feed R: ");
  display.print(rightFeederCount);
  display.setCursor(60, 45);
  display.print(" Dur: ");
  display.println(rightFeederDur);

  display.setCursor(0, 55);
  display.print("Bat V: ");
  display.println(measuredvbat);

  display.display();
  //delay (100);
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
  display.display();
}
