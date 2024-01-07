#include "Variables.h"
#include "STM_Receiver.h"
#include "TFT_SPIFFS_BMP.h"
#include "Screen.h"
#include "Touch.h"
#include "UI.h"
#include "SDK.h"


void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial2.setTimeout(10);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  if (!SPIFFS.begin()) {
    Serial.println("SPIFFS initialisation failed!");
    while (1) yield(); // Stay here twiddling thumbs waiting
  }
  Serial.println("\r\nSPIFFS initialised.");
  initializeVariables();
  loadSettings();
  initLanguage((lang.parm1 - 1));
  initScreen();
  homescreen();
}


void loop() {
  taskHandeler();
  op++;
//  Serial.println();
//  Serial.print("No of loops executed: ");
//  Serial.println(op);
}
