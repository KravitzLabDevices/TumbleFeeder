void move_left(int leftpos) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.refresh();
  digitalWrite(13, HIGH);
  myservo.attach(10); 
  for (int pos = middlepos; pos >= leftpos; pos -= 1) {
    myservo.write(pos);
    delay(50);
  }
  myservo.detach();
  digitalWrite(13, LOW);
}

void move_center(int middlepos) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.refresh();
  digitalWrite(13, HIGH);
  myservo.attach(10);
  for (int pos = leftpos; pos <= middlepos; pos += 1) {
    myservo.write(pos);
    delay(50);
  }
  myservo.detach();
  digitalWrite(13, LOW);
}
