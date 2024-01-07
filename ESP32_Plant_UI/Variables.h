//==========================================LIBRARIES==========================================//
#define FS_NO_GLOBALS
#include "FS.h"

#ifdef ESP32
#include "SPIFFS.h"  // For ESP32 only
#endif
#define ILI9481_DRIVER
//#define ILI9486_DRIVER
#include <TFT_eSPI.h>
#include "Free_Fonts.h"


//===========================================DEFINED===========================================//
#define yp 25
#define xm 26
#define ym 15
#define xp 4

#define HOMESCREEN 1
#define SIDESCREEN 2

#define theme tft.color565(2,204,190)

#define temperaturehighthreshold 28                       //      Thresholds for the sensors Value
#define temperaturelowthreshold 16                        //      Thresholds for the sensors Value
#define waterhighthreshold 80                             //      Thresholds for the sensors Value
#define waterlowthreshold 20                              //      Thresholds for the sensors Value
#define phhighthreshold 9.0                               //      Thresholds for the sensors Value
#define phlowthreshold 6.0                                //      Thresholds for the sensors Value
#define conclowthreshold 0.50                             //      Thresholds for the sensors Value
#define conchighthreshold 1.25                            //      Thresholds for the sensors Value

#define touchDebounce 80                                 //      Delay between two consevutive touch reads
#define LED 2


#define LOWER_TEMP 16
#define HIGHER_TEMP 27
#define LOWER_WATER 50
#define HIGHER_WATER 90
#define LOWER_pH 5.0
#define HIGHER_pH 9.0
#define LOWER_TDS 1.0
#define HIGHER_TDS 2.0
#define servoPin 45
#define debounce 400
#define debounceSmall 100
#define bgChoice 0
#define defaultLED_TIME 39600
#define defaultOFF_TIME 1800
#define servoThreshold 1000
#define rtc_update_interval 200
#define waterSensorPin A12
#define servoFeedbackPin A13
#define waterPumppin 38
#define wateroffSet 200
#define highLevel 800
#define defalutLedIntensity 125
#define DefalutTimerSelection 1
#define DefalutWingStat 1023
#define DefaultRiseValue 800
#define DefaultFallValue 130
#define DefaultServoSpeed 500
#define DefaultServoDirection 1
#define defaultPumpOn 50                          //Seconds
#define DefaultPumpOff 59                         //Minuter
#define Defaultlanguage 0

//===========================================OBJECT============================================//
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);
TFT_eSprite spr1 = TFT_eSprite(&tft);
//==========================================VARIABLES==========================================//
int x = 0, y = 0;
int rawX = 0, rawY = 0;
uint16_t xbuf = 0;
uint16_t ybuf = 0;
int avgx = 0, avgy = 0;
float XcalibrationFactor = -0.135215;
float YcalibrationFactor = 0.101486;
int color = 0;
float cx = 1, cy = 1;
float fontwidth = 0;
int calibrationMatrix[4][2] = {{3830, 608}, {422, 628}, {3833, 3554}, {300, 3663}};
String calibrationMSG = "PLEASE CLICK IN THE MIDDLE OF BOXES";
String calibrationMSG2 = "USING STYLUS";
String calibrationMSG3 = "TOP LEFT";
String calibrationMSG4 = "TOP RIGHT";
String calibrationMSG5 = "BOTTOM LEFT";
String calibrationMSG6 = "BOTTOM RIGHT";

int temperature = 18;
int waterlevel = 40;
String pumpstat = "OFF";
float ph = 7.2;
float conc = 0.25;
int pump = 0;

uint32_t scheduler[4] = {0, 0, 0, 0};  //[0] is for the home screen updat
//
//
//
//
//int page = 0;
int menuindex[3] = {0, 0, -1};
int menudrawn = 0;
int selectedMenu = 0;
int submenuindex[2] = {0, -1};

int ledTimer[4] = {360, 540, 720, 900};
uint16_t wingled = 65535;
int led_intensity = 0;
struct setting {
  int count;
  int selected;
  String setting1;
  String setting2;
  String setting3;
  String setting4;
  String setting5;
  String setting6;
  String setting7;
};

struct subsetting {
  int selected;
  String heading1;
  String heading2;
  String heading3;
  String heading4;
  String label1;
  String label2;
  String label3;
  String label4;
  String label5;
  String label6;
  int parm1;
  int parm2;
  int parm3;
  int parm4;
  int parm5;
  int parm6;
  int parm7;
};

struct setting ledSettings;
struct setting servoSettings;
struct setting Settings;
struct setting runningsetting;
struct subsetting ledsub1;
struct subsetting ledsub2;
struct subsetting servosub1;
struct subsetting servosub2;
struct subsetting servosub3;
struct subsetting datetime;
struct subsetting lang;
struct subsetting pumpSettings;
struct subsetting saveReset;

int increment = 1;
int Permission = 0;

String filename = "/save.TXT";


int op = 0;
uint32_t trcv = 0;
int passcode = 4512;
int hr = 0;
int mn = 0;
String tim;
uint32_t pumptimer = 0;
uint32_t stmdatatimer = 0;
int servoFeedback = 0;
int dt[6] = {0,0,0,0,0,0};
uint32_t dattimetimer = 0;
int ledstat = 0;








String name0 = "               ";
String name1 = "Controller";
String name2 = "Charlotte";

String home0 = "                ";
String home1 = "HOME";
String home2 = "CASA";

String led_setting0 = "               ";
String led_setting1 = "LED SETTING";
String led_setting2 = "LED SETTING";

String temperature0 = "               ";
String temperature1 = "TEMP";
String temperature2 = "TEMP";

String water0 = "               ";
String water1 = "WATER";
String water2 =  "ACQUA";

String pump0 = "               ";
String pump1 = "PUMP";
String pump2 = "POMPA";

String pH0 = "               ";
String pH1 = "pH";
String pH2 = "pH";

String concentration0 = "               ";
String concentration1 = "CONC.";
String concentration2 = "CONC.";

String led_timer0 = "               ";
String led_timer1 = "LED TIMER";
String led_timer2 = "LED ORE";

String hours0 = "           ";
String hours1 = "HOURS";
String hours2 = "ORE";

String led_intensity0 = "               ";
String led_intensity1 = "LED INTENSITY";
String led_intensity2 = "LED INTENSITÀ";

String led_brightness1 = "BRIGHTNESS";
String led_brightness2 = "LUMINOSITA";

String servoSetting1 = "SERVO SETTING";
String servoSetting2 = "SERVO SETTING";

String settings1 = "SYS. SETTING";
String settings2 = "DEV. SETTING";

String wings_control0 = "               ";
String wings_control1 = "WINGS CONTROL";
String wings_control2 = "ALA CONTROL";

String shut_down0 = "               ";
String shut_down1 = "SHUT DOWNN";
String shut_down2 = "SPEGNIMENTO";


String riseTime1 = "RISE VALUE";
String riseTime2 = "AUMENTO VALORE";


String fallTime1 = "FALL VALUE";
String fallTime2 = "DECLINO VALORE";


String servoSpeed1 = "SPEED/DIR";
String servoSpeed2 = "VELOCITA/DIR";

String rise1 = "RISE";
String rise2 = "AUMENTO";

String fall1 = "FALL";
String fall2 = "DECLINO";

String risefall0 = "               ";
String risefall1 = "RISEFALL";
String risefall2 = "AUM/DEC";

String stop0 = "        ";
String stop1 = "STOP";
String stop2 = "STOP";

String setTime1 = "TIME";
String setTime2 = "TEMPO";

String setDate1 = "DATE";
String setDate2 = "DATA";

String dateandtime1 = "DATE/TIME";
String dateandtime2 = "DATA/TEMPO";

String update0 = "              ";
String update1 = "UPDATE";
String update2 = "IMPOSTATO";


String resetsave1 = "RESET/SAVE";
String resetsave2 = "RIPR/SALVA";


String reset1 = "RESET SETTINGS";
String reset2 = "RIPRISTINA VALORI";


String save1 = "SAVE SETTINGS";
String save2 = "SALVA VALORI";

String language0 = "ENGLISH";
String language1 = "ITALIAN";

String Language1 = "LANGUAGE";
String Language2 = "LINGUAGGIO";

String pumptime1 = "SET PUMP";
String pumptime2 = "SET POMPA";

String yes0 = "      ";
String yes1 = "YES";
String yes2 = "SÌ";

String no = "              ";
String no1 = "NO";
String no2 = "NO";

String question0 = "                 ";
String question1 = "CONTINUE?";
String question2 = "CONTINUA?";

String setled1 = "SET LED";
String setled2 = "IMPOSTARE LED";

String setcurrentposition0 = "                               ";
String setcurrentposition1 = "SET CURRENT POSITION";
String setcurrentposition2 = "POSIZIONE CORRENTE";

String speed1 = "SPEED VALUE";
String speed2 = "VELOVITA VALORE";

String changeDirection0 = "                ";
String changeDirection1 = "CHANGE DIRECTION";
String changeDirection2 = "CAMBIA DIREZIONE";

String ontime1 = "ON TIME";
String ontime2 = "ON TEMPO";

String offtime1 = "OFF TIME";
String offtime2 = "OFF TEMPO";

String continue0 = "CONTINUE  SAVING?";
String continue1 = "CONTINUA SALVATAGGIO?";
String continue2 = "CONTINUE  RESET?";
String continue3 = "CONTINUA RIPRISTINA?";

String ledstarting0 = "                  ";
String ledstarting1 = "LED STARTING TIME";
String ledstarting2 ="AVVIAMENTO LED";
//=========================================================================================================//

void initLanguage(int x) {
  if (x == 0) {
    name0 = name1;
    home0 = home1;
    led_setting0 = led_setting1;
    temperature0 = temperature1 ;
    water0 = water1;
    pump0 = pump1;
    pH0 =  pH1;
    concentration0 = concentration1;
    ledSettings.setting2 = led_timer1;
    //led_intensity0 = led_intensity1;
    ledSettings.setting1 = led_intensity1;
    servoSettings.setting1 = servoSetting1;
    Settings.setting1 = settings1;
    wings_control0 = wings_control1 ;
    shut_down0 = shut_down1;
    servosub1.heading1 = riseTime1;
    servosub2.heading1 = fallTime1;
    servoSettings.setting4 = servoSpeed1;
    servoSettings.setting2 = rise1;
    servoSettings.setting3 = fall1;
    risefall0 = risefall1;
    stop0 = stop1;
    datetime.heading1 = setTime1;
    datetime.heading2 = setDate1;
    Settings.setting2 = dateandtime1;
    update0 = update1;
    Settings.setting5 = resetsave1;
    saveReset.heading1 = reset1;
    saveReset.heading2 = save1;
    Settings.setting4 = pumptime1;
    yes0 = yes1;
    no = no1;
    question0 = question1;
    ledSettings.setting3 = led_brightness1;
    hours0 = hours1;
    setcurrentposition0 = setcurrentposition1;
    servosub3.heading1 = speed1;
    changeDirection0 = changeDirection1;
    Settings.setting3 = Language1;
    lang.heading1 = "SET LANGUAGE";
    pumpSettings.heading1 = ontime1;
    pumpSettings.heading2 = offtime1;
    saveReset.label2 = continue0;
    saveReset.label1 = continue2;
    ledstarting0 =ledstarting1;
  }
  if (x == 1) {
    name0 = name2;
    home0 = home2;
    led_setting0 = led_setting2;
    temperature0 = temperature2 ;
    water0 = water2;
    pump0 = pump2;
    pH0 =  pH2;
    concentration0 = concentration2;
    ledSettings.setting2  = led_timer2;
    ledSettings.setting1 = led_intensity2;
    servoSettings.setting1 = servoSetting2;
    Settings.setting1 = settings2;
    wings_control0 = wings_control2 ;
    shut_down0 = shut_down2;
    servosub1.heading1 = riseTime2;
    servosub2.heading1 = fallTime2;
    servoSettings.setting4 = servoSpeed2;
    servoSettings.setting2 = rise2;
    servoSettings.setting3 = fall2;
    risefall0 = risefall2;
    stop0 = stop2;
    datetime.heading1 = setTime2;
    datetime.heading2 = setDate2;
    Settings.setting2 = dateandtime2;
    update0 = update2;
    Settings.setting5= resetsave2;
    saveReset.heading1 = reset2;
    saveReset.heading2 = save2;
    Settings.setting4 = pumptime2;
    yes0 = yes2;
    no = no2;
    question0 = question2;
    ledSettings.setting3 = led_brightness2;
    hours0 = hours2;
    setcurrentposition0 = setcurrentposition2;
    servosub3.heading1 = speed2;
    changeDirection0 = changeDirection1;
    Settings.setting3 = Language2;
    lang.heading1 = "SET LINGUAGGIO";
    pumpSettings.heading1 = ontime2;
    pumpSettings.heading2 = offtime2;
    saveReset.label2 = continue1;
    saveReset.label1 = continue3;
    ledstarting0 = ledstarting2;
  }
  //Serial.println(temperature0.length());
}

void initializeVariables() {
  //======================================================================================
  ledSettings.count = 3;
  ledSettings.selected = 1;
  //---------------------------------------------------------------------------------------
  ledsub1.selected = 1;
  ledsub1.parm1 = 360;
  ledsub1.parm2 = 540;
  ledsub1.parm3 = 720;
  ledsub1.parm4 = 900;
  //---------------------------------------------------------------------------------------
  ledsub2.parm1 = 75;
  ledsub2.parm2 = 32767;
  //======================================================================================
  servoSettings.count = 4;
  //---------------------------------------------------------------------------------------
  servosub1.parm1 = 980;
  //---------------------------------------------------------------------------------------
  servosub2.parm1 = 68;
  //---------------------------------------------------------------------------------------
  servosub3.parm1 = 500;
  servosub3.parm2 = 1;
  //======================================================================================
  Settings.count = 5;
  //--------------------------------------------------------------------------------------
  datetime.selected = 1;
  datetime.parm1 = 12;
  datetime.parm2 = 56;
  datetime.parm3 = 48;
  datetime.parm4 = 21;
  datetime.parm5 = 10;
  datetime.parm6 = 20;
  //--------------------------------------------------------------------------------------
  datetime.label1 = "SEC";
  datetime.label2 = "MIN";
  datetime.label3 = "HOUR";
  datetime.label4 = "DAY";
  datetime.label5 = "MONTH";
  datetime.label6 = "YEAR";
  //========================================================================================
  lang.parm1 = 1;
  //========================================================================================
  pumpSettings.parm1 = 50;
  pumpSettings.parm2 = 59;
}

void setmenu( int mn);
int chkin(int x1, int y1, int x2, int y2);
int submenu();
void handlesubmenu();
void ledtimer(int sl);
void brightness();
void displayStrings( int highlight);
void updateIcon(int i);
void updateSlider(int per);
void riseSetting();
void fallSetting();
void speedSetting();
int input();
void dateTime();
void setlanguage(int lg);
void setPump();
void resetSave();
void activeDateTime(int atv);
void permission(int pr);
void managePump();
void saveSettings();
void manageLED();
