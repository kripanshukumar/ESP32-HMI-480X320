void waterLevel() {
  int temp = 0;
  temp = analogRead(PA3) / 4;
  waterlevel = map(temp, lowerthreshold, higherthreshold, 0, 100);
}
