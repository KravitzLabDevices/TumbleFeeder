void feeder_open(int openpos) {
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

void feeder_close(int closedpos) {
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

void shake () {
  for (int i = 0; i < 10; i++) {
    digitalWrite (13, HIGH);
    delay (50);
    digitalWrite (13, LOW);
    delay(50);
  }
}

void shake_food() {
  shake ();
  feeder_close(closedpos);
  feeder_open(openpos);
  logData();
}
