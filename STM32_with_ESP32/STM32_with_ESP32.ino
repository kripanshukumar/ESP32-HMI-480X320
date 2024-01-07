#include "variables.h"
#include "rtc.h"
#include "pH.h"
#include "conc.h"
#include "servo.h"
#include "led.h"
#include "temperature.h"
#include "water.h"

void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  Serial3.setTimeout(15);
  rtcinit();
  intializeServo();
  initializeLED();
  intializeTemperature();
  pinMode(LED_BUILTIN, OUTPUT);
  //myservo.writeMicroseconds(2000);
}

void loop() {
  sendData();
  rcvCommand();
  getcurrentTime();
  compute_pH();
  getTDSvalue();
  runServo();
  setleds();
  getTem();
  waterLevel();
  //delay(100);
}


void sendData() {
  if (millis() - t >= 300) {
    payload = ',' + String(passcode) + ',' + String(rtc.hour()) + ',' + String(rtc.minute()) + ',' + String(rtc.second()) + ',' + String(rtc.day()) + ',' + String(rtc.month()) + ',' + String(rtc.year()) + ','  + String(tdsValue) + ',' + String(pumpstat) + ',' + String(phValue) + ',' + String(tempera) + ','  + String(waterlevel) + ',' + String(servofeedback) + ',';
    Serial3.println(payload + '\n');
    Serial.println(payload);
    t = millis();
  }
}
void rcvCommand() {
  int commandindex[20];
  int j = 0;
  String temp;
  if (Serial3.available()) {
    temp = Serial3.readStringUntil('\n');
    Serial.println(temp);
    for (int i = 0; i < temp.length(); i++) {
      if (temp[i] == ',') {
        commandindex[j] = i;
        j++;
      }
    }
    if (temp.substring(commandindex[0] + 1, commandindex[1]).toInt() == passcode) {
      switch (temp.substring(commandindex[1] + 1, commandindex[2]).toInt()) {
        case 0:
          Serial.println("CASE 0");
          pumpstat = temp.substring(commandindex[2] + 1, commandindex[3]).toInt();
          ledstat = temp.substring(commandindex[3] + 1, commandindex[4]).toInt();
          upperThreshold = temp.substring(commandindex[4] + 1, commandindex[5]).toInt();
          lowerThreshold = temp.substring(commandindex[5] + 1, commandindex[6]).toInt();
          velocity = temp.substring(commandindex[6] + 1, commandindex[7]).toInt();
          if (temp.substring(commandindex[7] + 1, commandindex[8]).toInt() == 1) {
            dir = 1;
          }
          else {
            dir = -1;
          }
          menu =  temp.substring(commandindex[8] + 1, commandindex[9]).toInt();
          ledintensity = temp.substring(commandindex[9] + 1, commandindex[10]).toInt();
          Serial.print("PUMP : "); Serial.print(pumpstat);
          Serial.print("LED : "); Serial.print(ledstat);
          Serial.print(" RISE : "); Serial.print(upperThreshold);
          Serial.print(" FALL : "); Serial.print(lowerThreshold);
          Serial.print(" VELOCITY : "); Serial.print(velocity);
          Serial.print(" DIRECTION : "); Serial.print(dir);
          Serial.print(" menu : "); Serial.print(menu);
          Serial.print(" ledintensity : "); Serial.println(ledintensity);
          break;

        case 1:
          Serial.println("CASE 1");
          byte dt[6];
          for (int m = 0; m < 6; m++) {
            dt[m] = temp.substring(commandindex[m + 2] + 1, commandindex[m + 3]).toInt();
          }
          rtc.set(dt[2], dt[1], dt[0], 6, dt[3], dt[4], dt[5]);
          break;

        case 2:
          Serial.println("CASE 2");
          if (temp.substring(commandindex[2] + 1, commandindex[3]).toInt() == 1) {
            riseServo();
          }
          else {
            stopServo();
          }
          break;

        case 3:
          Serial.println("CASE 3");
          if (temp.substring(commandindex[2] + 1, commandindex[3]).toInt() == 1) {
            fallServo();
          }
          else {
            stopServo();
          }
      }
      trcv = millis();
    }
  }
  if (millis() - trcv >= 1000) {
    digitalWrite(LED_BUILTIN, LOW);
    Serial3.println("STM32 is not receiving from ESP32");
  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
