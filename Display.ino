
  int mid_pos;
  int set_middle() {
  ReadBatteryLevel();
  currentpos = analogRead(A5);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Pos:");
  display.print(currentpos);
  display.print(" Time:");
  display.println(millis() / 1000);

  display.setCursor(0, 55);
  display.print("Bat V: ");
  display.println(measuredvbat);
  display.display();
  mid_pos = (analogRead(A5)-193)/3; //YY
  return mid_pos;
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
