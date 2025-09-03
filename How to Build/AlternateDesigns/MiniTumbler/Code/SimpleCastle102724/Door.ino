/********************************************************
  Operate door based on light levels
********************************************************/
void LightControlledDoor() {
  //if it's dark
  if (lux > 5 and doorOpen == false) {
    open_door();
  }

  //if it's light
  else if (lux < 6 and doorOpen == true) {
    close_door();
  }
}

/********************************************************
  Operate door based on hour between 8pm and 4am
********************************************************/
void TimedDoor() {
  rtc.begin();  //restart rtc
  DateTime now = rtc.now();
  Serial.print("Hour: ");
  Serial.println(now.hour());

  if (now.year() > 2020) {  // if there's an issue with the RTC it will return 2000.  If that happens let's ignore it and try again on the next loop.
    //if it's between 8pm and 4am
    if ((now.hour() >= 20 || now.hour() <= 3)) {
      if (doorOpen == false) {
        open_door();
      }
    } else if (doorOpen == true) {
      close_door();
    }
  }
}

/********************************************************
  Open door
********************************************************/
void open_door() {
  digitalWrite(11, HIGH);
  myservo.attach(A0);  // attaches the servo on pin A0 to the servo object

  //smoothly open servo door
  for (int pos = 110; pos >= -10; pos--) {
    myservo.write(pos);  // Move the servo to the current position
    delay(30);           // Wait before moving to the next position
  }

  digitalWrite(11, LOW);
  doorOpen = true;

  myservo.detach();
}

/********************************************************
  Close door
********************************************************/
void close_door() {
  digitalWrite(11, HIGH);
  myservo.attach(A0);  // attaches the servo on pin A0 to the servo object

  //smoothly close  servo door
  for (int pos = -10; pos <= 100; pos++) {
    myservo.write(pos);  // Move the servo to the current position
    delay(30);           // Wait before moving to the next position
  }

  digitalWrite(11, LOW);
  doorOpen = false;

  // Detach the servo to free up the pin
  myservo.detach();
}
