void move_left(int middlepos) {
  unsigned long left_timer = millis();
  while(millis()-left_timer <=1000){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("LEFT!");
  display.display();
  display.display();
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write(middlepos-48);              // YY change to 0 to check where analog read start
  }
//  display.clearDisplay();
//  display.setCursor(0, 0);
//  display.print("LEFT!");
//  display.display();
//  display.display();
//  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
//  myservo.write(0);              // YY change to 0 to check where analog read start
//  delay (1000);
  myservo.detach();
}

void move_center(int centerpos) {
  unsigned long center_timer = millis();
  while(millis()-center_timer<=1000){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("CENTER!");
  display.display();
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write(centerpos);              // tell servo to go to position in variable 'pos'
    }
//  display.clearDisplay();
//  display.setCursor(0, 0);
//  display.print("CENTER!");
//  display.display();
//  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
//  myservo.write(92);              // tell servo to go to position in variable 'pos'
//  delay (1000);
  myservo.detach();
}

void move_right(int middlepos) {
  unsigned long right_timer = millis();
  while(millis()-right_timer<=1000){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("RIGHT!");
  // PIN for reading current position is A5
  // CHECKING CURRENT POSITION
  display.display();
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write(middlepos+48); // COULD ADD ADJUSTMENT VAR              // tell servo to go to position in variable 'pos'
  int current_pos = analogRead(A5);
    }
//  display.clearDisplay();
//  display.setCursor(0, 0);
//  display.print("RIGHT!");
//  // PIN for reading current position is A5
//  // CHECKING CURRENT POSITION
//  display.display();
//  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
//  myservo.write(142); // COULD ADD ADJUSTMENT VAR              // tell servo to go to position in variable 'pos'
//  int current_pos = analogRead(A5);
  
//  delay (1000);
  myservo.detach();
}
