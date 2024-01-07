void rtcinit() {
#ifdef ARDUINO_ARCH_ESP8266
  URTCLIB_WIRE.begin(0, 2); // D3 and D4 on ESP8266
#else
  URTCLIB_WIRE.begin();
#endif
}

void getcurrentTime() {
  rtc.refresh();
  
}
