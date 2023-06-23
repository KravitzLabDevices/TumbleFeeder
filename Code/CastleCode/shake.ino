void shake () {
  for (int i = 0; i < 10; i++) {
    digitalWrite (13, HIGH);
    delay (50);
    digitalWrite (13, LOW);    
    delay(50);
  }
}
