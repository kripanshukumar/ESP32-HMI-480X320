#include "Arduino.h"
#include "uRTCLib.h"
#include <Servo.h>
#include <OneWire.h>

//===================================Defined Variables====================================//

#define LED_BUILTIN PC13

//-----------------------------------ph----------------------------
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40
#define SensorPin PA0
#define Offset 0.00

//----------------------------------conc---------------------------
#define VREF 5.0                      // analog reference voltage(Volt) of the ADC
#define SCOUNT  30                    // sum of sample point
#define TdsSensorPin PA1

//----------------------------------servo--------------------------
#define servofeedbackpin PA2
#define servoPin PB1

//----------------------------------LED pins-----------------------
#define led1 PA9
#define led2 PA10
#define led3 PB3
#define led4 PB4
#define led5 PA15
#define led6 PB12
#define led7 PB13
#define led8 PB14
#define led9 PB15
#define led10 PA8

//---------------------------------Water Pump----------------------
#define pumpPin PB3

//---------------------------------Temperature---------------------
#define ONE_WIRE_BUS PB9

//--------------------------------Water Level-----------------------
#define waterSensorPin PA3
#define higherthreshold 200
#define lowerthreshold 800
//========================================Variables=======================================//

String payload;
int passcode = 4512;
uint32_t t = 0, trcv = 0;

//-----------------------------------ph----------------------------
int pHArray[ArrayLenth];
int pHArrayIndex=0;
int phValue = 0;

//----------------------------------conc---------------------------
float tdsValue = 0;
int analogBuffer[SCOUNT]; 
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0,copyIndex = 0;
float averageVoltage = 0,temperature = 25;

//----------------------------------servo---------------------------
int upperThreshold = 1000;
int lowerThreshold = 23;
uint32_t caseTimer = 0;
int servofeedback = 0;
int caseRunning = 0;
int velocity = 500;
int servostat = 0;
int rest = 1500;
int dir = 1;

//-----------------------------------LEDs---------------------------
int ledpins[10];
uint16_t ledstat = 0;
volatile int ledintensity = 50;
uint32_t counter = 0;
volatile uint16_t porta = 0,PORTA = 30975;
volatile uint16_t portb = 0,PORTB = 4071;
volatile uint16_t andporta = 0;
volatile uint16_t andportb = 0;
//---------------------------------Water Pump-----------------------
int pumpstat = 0;

//--------------------------------Water Level-----------------------
int waterlevel = 0;

//--------------------------------temperature-----------------------
int tempera = 0;

//----------------------------------Menu----------------------------
int menu = 0;
//=========================================OBJECTS========================================//

uRTCLib rtc(0x68);
Servo myservo;
OneWire  ds(ONE_WIRE_BUS);
HardwareTimer timer(2);
