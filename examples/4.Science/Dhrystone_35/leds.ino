void blinks() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
    delay(100);
  }
}
