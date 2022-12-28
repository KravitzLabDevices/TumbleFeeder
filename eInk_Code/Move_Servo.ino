void move_left(int leftpos) {
  unsigned long left_timer = millis();
  while(millis()-left_timer <=1000){
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write(leftpos);
  }
  myservo.detach();
}

void move_center(int middlepos) {
  unsigned long center_timer = millis();
  while(millis()-center_timer<=1000){
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write(middlepos);              // tell servo to go to position in variable 'pos'
    }
  myservo.detach();
}

void move_right(int rightpos) {
  unsigned long right_timer = millis();
  while(millis()-right_timer<=1000){
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write(rightpos);
    }
  myservo.detach();
}
