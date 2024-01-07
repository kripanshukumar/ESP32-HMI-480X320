void handler_led(void) {
  if (ledintensity != 0) {
    if (counter == 1) {
      GPIOA->regs->ODR |= porta;
      GPIOB->regs->ODR |= portb;
    }
  }
  if (counter >= ledintensity) {
    GPIOA->regs->ODR &= PORTA;
    GPIOB->regs->ODR &= PORTB;
  }
  counter++;
  if (counter >= 100) {
    counter = 0;
  }
}

void initializeLED() {
  ledpins[0] = 9;
  ledpins[1] = 10;
  ledpins[2] = 3;
  ledpins[3] = 4;
  ledpins[4] = 15;
  ledpins[5] = 12;
  ledpins[6] = 13;
  ledpins[7] = 14;
  ledpins[8] = 15;
  ledpins[9] = 8;
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  timer.pause();

  // Set up period
  timer.setPeriod(10); // in microseconds

  // Set up an interrupt on channel 1
  timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
  timer.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
  timer.attachCompare1Interrupt(handler_led);

  // Refresh the timer's count, prescale, and overflow
  timer.refresh();

  // Start the timer counting
  timer.resume();
}

void setleds() {
  bitWrite(porta, ledpins[0], bitRead(ledstat, 0));
  bitWrite(porta, ledpins[1], bitRead(ledstat, 1));
  bitWrite(portb, ledpins[2], bitRead(ledstat, 2));
  bitWrite(portb, ledpins[3], bitRead(ledstat, 3));
  bitWrite(porta, ledpins[4], bitRead(ledstat, 4));
  bitWrite(portb, ledpins[5], bitRead(ledstat, 5));
  bitWrite(portb, ledpins[6], bitRead(ledstat, 6));
  bitWrite(portb, ledpins[7], bitRead(ledstat, 7));
  bitWrite(portb, ledpins[8], bitRead(ledstat, 8));
  bitWrite(porta, ledpins[9], bitRead(ledstat, 9));
  //  andporta = !porta;
  //  andportb = !portb;
  digitalWrite(pumpPin, pumpstat);
}
