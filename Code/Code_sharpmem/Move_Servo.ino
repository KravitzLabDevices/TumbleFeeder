void move_left(int leftpos) {
  unsigned long left_timer = millis();
  while (millis() - left_timer <= 1000) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.refresh();
    digitalWrite(13, HIGH);
    myservo.attach(10);  // attaches the servo on pin 10 to the servo object
    //Serial.println(middlepos);
    for (int pos = 180; pos >= leftpos; pos -= 1) { 
      Serial.print("left");
      Serial.println(pos);
      myservo.write(pos);             
      delay(50);                      
    }
  }
  myservo.detach();
  digitalWrite(13, LOW);
}

void move_center(int middlepos) {
  unsigned long center_timer = millis();
  while (millis() - center_timer <= 1000) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.refresh();
    digitalWrite(13, HIGH);
    myservo.attach(10);
    //Serial.println(leftpos);            
    for (int pos = leftpos; pos <= middlepos; pos += 1) { 
      Serial.print("center");
      Serial.println(pos);
      myservo.write(pos);              
      delay(50);                     
    }
  }
  myservo.detach();
  digitalWrite(13, LOW);

}

void move_right(int rightpos) {
  unsigned long right_timer = millis();
  while (millis() - right_timer <= 1000) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.refresh();
    digitalWrite(13, HIGH);
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object
    myservo.write(rightpos);
  }
  myservo.detach();
  digitalWrite(13, LOW);

}
