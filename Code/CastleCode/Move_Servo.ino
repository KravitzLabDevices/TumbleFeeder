void move_left(int openpos) {
//  display.fillRect(0, 0, 168, 144, WHITE);
  display.setCursor(0, 0);
  display.refresh();
  digitalWrite(13, HIGH);
  myservo.attach(10); 
  for (int pos = closedpos; pos >= openpos; pos -= 1) {
    myservo.write(pos);
    delay(50);
  }
  myservo.detach();
  digitalWrite(13, LOW);
}

void move_center(int closedpos) {
//  display.fillRect(0, 0, 168, 144, WHITE);
  display.setCursor(0, 0);
  display.refresh();
  digitalWrite(13, HIGH);
  myservo.attach(10);
  for (int pos = openpos; pos <= closedpos; pos += 1) {
    myservo.write(pos);
    delay(50);
  }
  myservo.detach();
  digitalWrite(13, LOW);
}
