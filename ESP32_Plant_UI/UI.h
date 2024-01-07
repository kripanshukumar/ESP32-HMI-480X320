void homescreen() {
  if (menuindex[0] != menuindex[2]) {
    Serial.println("Drawing Home Screen...");
    scr(230, 230, 230);
    Tclr(TFT_WHITE);
    //tft.setFreeFont(FS18);
    Font(3);
    clr(2, 204, 190);
    Sellipse(240, 0, 270, 220);
    clr16(TFT_WHITE);
    SRrect(20, 50, 439, 249, 15);
    optionbar();

    text("CHARLOTTE", (250 - (String("CHARLOTTE").length() * fontwidth)), 8 * cy);

    clr16(tft.color565(2, 204, 190));
    Rrect(50, 60, 379, 30, 15);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        SRrect(50 + (150 * i) , 100 + (100 * j) , 70, 68, 10);
      }
    }
    //if (cx < 1) {
    //      Font(1);
    //  }
    //   else {
    Font(2);
    //  }
    tft.drawString("09:45", 355 , 212 );
    tft.drawString("AM", 371 * cx, 236 * cy);
    if ((cx == 1) && (cy == 1)) {
      drawBmp("/temp.bmp", 60, 107);
      drawBmp("/waterlevel.bmp", 210, 107);
      drawBmp("/pump.bmp", 360, 107);
      drawBmp("/ph.bmp", 55, 205);
      drawBmp("/conductivity.bmp", 210, 207);
    }
    if ((cx < 1) && (cy < 1)) {
      drawBmp("/temp1.bmp", 60 * cx, (107 * cy) + 2);
      drawBmp("/waterlevel1.bmp", 210 * cx, (107 * cy) + 2);
      drawBmp("/pump1.bmp", 360 * cx, (107 * cy) + 2);
      drawBmp("/ph1.bmp", 55 * cx, (205 * cy) + 2);
      drawBmp("/conductivity1.bmp", 210 * cx, (207 * cy) + 2);
    }

    menuindex[2]  = menuindex[0] ;
  }
}

void updateHS() {
  String temp;
  String water;
  //  String tim;
  //  temperature = random(16, 37);
  //  waterlevel = random(0, 100);
  //  pump = random(0, 2);
  //  ph = float(random(1, 140)) / 10;
  //  conc = float(random(0 , 15)) / 10;
  temp = String(temperature) + " C";
  water = String(waterlevel) + "%";

  //if (cx < 1) {
  //   Font(1);
  //  }
  //  else {
  Font(2);
  // }

  clr16(TFT_WHITE);

  // Temperature Configuration=====================================================================================
  if (menuindex[0] == 0) {
    Srect(50, 173, 70, 25);
    if ((temperature >= temperaturehighthreshold) || (temperature <= temperaturelowthreshold)) {
      Tclr(TFT_RED);
      clr16(TFT_RED);
    }
    else {
      Tclr(theme);
      clr16(theme);
    }
    circle(92, 176, 4);
    circle(92, 176, 3);
    tft.drawString(temp, (85 * cx) - (temp.length() * fontwidth), 173 * cy);

    // PH CONFIGURATION============================================================================================

    if ((ph >= phhighthreshold) ||  (ph <= phlowthreshold)) {
      Tclr(TFT_RED);
    }
    else {
      Tclr(theme);
    }
    clr16(TFT_WHITE);
    Srect(50, 273, 80, 25);
    tft.drawString(String(ph), ((85 * cx) - (String(ph).length() * fontwidth)), 273 * cy);
  }

  //  Serial.print("Menu index0 = ");Serial.println(menuindex[0]);
  //  Serial.print("Menu index1 = ");Serial.println(menuindex[1]);

  if (((menuindex[0] <= 1) && (menuindex[1] <= 1)) || (menuindex[1] == 5)) {
    // WATER LEVEL CONFIGURATION=====================================================================================

    clr16(TFT_WHITE);
    if ((waterlevel >= waterhighthreshold) || (waterlevel <= waterlowthreshold)) {
      Tclr(TFT_RED);
    }
    else {
      Tclr(theme);
    }
    Srect(200, 173, 70, 25);
    tft.drawString(water, (235 * cx) - (water.length() * fontwidth), 173 * cy);


    //CONCENTRATION CONFIGURATION====================================================================================


    if ((conc >= conchighthreshold) || (conc <= conclowthreshold)) {
      Tclr(TFT_RED);
    }
    else {
      Tclr(theme);
    }
    Srect(200, 273, 70, 25);
    tft.drawString(String(conc), ((235 * cx) - (String(conc).length() * fontwidth)), 273 * cy);

    //PUMP CONFIGURATION====================================================================================

    if ( pump == 0) {
      Tclr(TFT_RED);
      pumpstat = "OFF";
    }
    else {
      Tclr(theme);
      pumpstat = "ON";
    }
    Srect(350, 173, 80, 25);
    tft.drawString(pumpstat, ((385 * cx) - (pumpstat.length() * fontwidth)), 173 * cy);

    //TIME CONFIGURATION====================================================================================

    Tclr(TFT_WHITE);
    clr16(theme);
    Srect(350, 212, 70, 50);
    if (datetime.parm1 <= 12) {
      tim = String(datetime.parm1) + ':' + String(datetime.parm2);
      tft.drawString("AM", 371 * cx, 236 * cy);
    }
    else {
      tim = String(datetime.parm1 - 12) + ':' + String(datetime.parm2);
      tft.drawString("PM", 371 * cx, 236 * cy);
    }
    tft.drawString(tim, (385 * cx) - (tim.length()*fontwidth), 212 * cy);
  }

}

//=========================================================================================================

void sidescreen() {
  if (menuindex[0] != menuindex[2] ) {
    Serial.println("Displaying Side Screen...");
    for (int i = 0; i <= (64 * cy); i += 8) {
      clr(1, 90, 84);
      if (cy == 1) {
        backicon(i - 64, 0);
        drawBmp("/ledsettings.bmp", i - 64 , 64);
        drawBmp("/servo.bmp", i - 64, 128);
        drawBmp("/settings.bmp", i - 64, 192);
        drawBmp("/home.bmp", i - 64, 256);
      }
      else {
        backicon(i - 48, 0);
        drawBmp("/ledsettings1.bmp", i - 48 , 48);
        drawBmp("/servo1.bmp", i - 48, 96);
        drawBmp("/settings1.bmp", i - 48, 144);
        drawBmp("/home1.bmp", i - 48, 192);
      }
      delay(10 );

    }
    //    for (int i = 0; i <= (68 * cy); i += 2) {
    //      clr(1, 90, 84);
    //      tft.fillRect(64 * cy, 0, i, 320 * cy, color);
    //      delay(35);
    //    }
    menuindex[2] = menuindex[0] ;
  }
  else {
    //    if (menuindex[1] == 0) {
    //      homescreen();
    //    }
    //    else {
    Serial.println(menuindex[1]);
    setmenu(menuindex[1]);
  }
}

void drawMenu() {
  scr(230, 230, 230);
  Tclr(TFT_WHITE);
  tft.setFreeFont(FS18);
  clr(2, 204, 190);
  Sellipse(240, 0, 270, 220);
  clr16(TFT_WHITE);
  SRrect(20, 50, 439, 249, 15);
  optionbar();

  clr(230, 230, 230);
  Srect(40, 70, 150, 209);
  Srect(190, 70, 250, 209);
  clr16(TFT_WHITE);
  Srect(44, 74, 142, 201);
  Srect(190, 74, 246, 201);


  clr(230, 230, 230);
  for (int i = 1; i < 6; i++) {
    Srect(48, 74 + (33 * i), 134, 3);
  }
  clr16(theme);
  //    Striangle(115, 50, 106, 68, 124, 68);
  //    Striangle(115, 298, 106, 280, 124, 280);
}




void displayStrings( int highlight) {
  clr16(TFT_WHITE);
  for (int i = 1; i <= 6; i++) {
    Srect(48, 44 + (33 * i), 134, 30);
  }
  Font(3);
  Tclr(TFT_WHITE);
  text(runningsetting.setting1, 250 - (runningsetting.setting1.length() * fontwidth), 8);
  //if (cx == 1) {
  Font(1);
  //  }
  //  else {
  //    tft.setFreeFont(FF0);
  //    fontwidth = 4.5;
  //  }
  Tclr(theme);
  //for(int i = 0; i < runningsetting.count; i++){
  if (runningsetting.count >= 2) {
    text(runningsetting.setting2, 115 - (runningsetting.setting2.length() * fontwidth) , 85 );
  }

  if (runningsetting.count >= 3) {
    text(runningsetting.setting3, 115 - (runningsetting.setting3.length() * fontwidth) , 85 + (33 * 1));
  }

  if (runningsetting.count >= 4) {
    text(runningsetting.setting4, 115 - (runningsetting.setting4.length() * fontwidth) , 85 + (33 * 2));
  }

  if (runningsetting.count >= 5) {
    text(runningsetting.setting5, 115 - (runningsetting.setting5.length() * fontwidth) , 85 + (33 * 3));
  }

  if (runningsetting.count >= 6) {
    text(runningsetting.setting6, 115 - (runningsetting.setting6.length() * fontwidth) , 85 + (33 * 4));
  }

  if (runningsetting.count >= 7) {
    text(runningsetting.setting7, 115 - (runningsetting.setting7.length() * fontwidth) , 85 + (33 * 5));
  }
  clr16(theme);
  //  if (cx == 1) {
  Font(1);
  //  }
  //  else {
  //    tft.setFreeFont(FF0);
  //    fontwidth = 4.5;
  //  }
  Tclr(TFT_WHITE);
  switch (highlight) {
    case 1:
      Srect(48, 44 + (33 * 1), 134, 30);
      text(runningsetting.setting2, 115 - (runningsetting.setting2.length() * fontwidth) , 85 );
      break;

    case 2:
      Srect(48, 44 + (33 * 2), 134, 30);
      text(runningsetting.setting3, 115 - (runningsetting.setting3.length() * fontwidth) , 85 + (33 * 1));
      break;

    case 3:
      Srect(48, 44 + (33 * 3), 134, 30);
      text(runningsetting.setting4, 115 - (runningsetting.setting4.length() * fontwidth) , 85 + (33 * 2));
      break;

    case 4:
      Srect(48, 44 + (33 * 4), 134, 30);
      text(runningsetting.setting5, 115 - (runningsetting.setting5.length() * fontwidth) , 85 + (33 * 3));
      break;

    case 5:
      Srect(48, 44 + (33 * 5), 134, 30);
      text(runningsetting.setting6, 115 - (runningsetting.setting6.length() * fontwidth) , 85 + (33 * 4));
      break;

    case 6:
      Srect(48, 44 + (33 * 6), 134, 30);
      text(runningsetting.setting7, 115 - (runningsetting.setting7.length() * fontwidth) , 85 + (33 * 5));
      break;
  }
}

void ledStartingTime() {
  Font(2);
  clr16(TFT_WHITE);
  SRrect( 185 + (70), 209, 47, 47, 15);
  SRrect( 195 + 127, 209, 47, 47, 15);
  Tclr(theme);
  clr16(theme);
  text(ledstarting0, 313 - (ledstarting0.length() * fontwidth), 187 -  (tft.fontHeight(GFXFF) / 2));
  ledsub1.parm7 = 1;
  //Rrect( 190 + 14, 209, 47, 47, 15);
  SRrect( 185 + (70), 209, 47, 47, 15);
  Rrect( 195 + 127, 209, 47, 47, 15);
  //Rrect( 190 + (184), 209, 47, 47, 15);
  Scircle(311,224,3);
  Scircle(311,240,3);
  Striangle(210, 232, 236, 217, 236, 247);
  Striangle(415, 232, 389, 217, 389, 247);
  text(String(ledsub1.parm6), 232 + (56.76 * 2) - (String(ledsub1.parm6).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
  Tclr(TFT_WHITE);
  text(String(ledsub1.parm5), 222 + (56.76) - (String(ledsub1.parm5).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
  
}


void ledtimer(int sl) {
  ledsub1.selected = sl;
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);
  SRrect( 190 + 14, 90 + 28, 47, 47, 15);
  SRrect( 190 + (70), 90 + (28), 47, 47, 15);
  SRrect( 190 + 127, 90 + (28), 47, 47, 15);
  SRrect( 190 + (184), 90 + 28 , 47, 47, 15);

  clr16(theme);
  Rrect( 190 + 14, 90 + 28, 47, 47, 15);
  Rrect( 190 + (70), 90 + (28), 47, 47, 15);
  Rrect( 190 + 127, 90 + (28), 47, 47, 15);
  Rrect( 190 + (184), 90 + 28 , 47, 47, 15);

  Font(2);

  Tclr(theme);
  text(hours0, 313 - (hours0.length() * fontwidth), 96 -  (tft.fontHeight(GFXFF) / 2));

  Font(2);

  text(String(ledsub1.parm1 / 60), 227 - (String(ledsub1.parm1 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
  text(String(ledsub1.parm2 / 60), 227 + (56.76) - (String(ledsub1.parm2 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
  text(String(ledsub1.parm3 / 60), 227 + (56.76 * 2) - (String(ledsub1.parm3 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
  text(String(ledsub1.parm4 / 60), 227 + (56.76 * 3) - (String(ledsub1.parm4 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
  Tclr(TFT_WHITE);
  Serial.println(ledsub1.selected);
  switch (ledsub1.selected) {
    case 1:
      SRrect(190 + 14, 90 + 28, 47, 47, 15);
      text(String(ledsub1.parm1 / 60), 227 - (String(ledsub1.parm1 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
      break;

    case 2:
      SRrect( 190 + (70), 90 + (28), 47, 47, 15);
      text(String(ledsub1.parm2 / 60), 227 + (56.76) - (String(ledsub1.parm2 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
      break;

    case 3:
      SRrect( 190 + 127, 90 + (28), 47, 47, 15);
      text(String(ledsub1.parm3 / 60), 227 + (56.76 * 2) - (String(ledsub1.parm3 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
      break;

    case 4:
      SRrect( 190 + (184), 90 + 28 , 47, 47, 15);
      text(String(ledsub1.parm4 / 60), 227 + (56.76 * 3) - (String(ledsub1.parm4 / 60).length() * fontwidth), 92 + 52 -  (tft.fontHeight(GFXFF) / 2));
      break;
  }
  ledStartingTime();
}


void updateIcon(int i) {
  int sw = i - 1;
  if (cx == 1) {
    Font(2);
  }
  else {
    Font(1);
  }
  if (sw == 9) {
    if (bitRead(ledsub2.parm2, sw) == 1) {
      Tclr(TFT_WHITE);
      clr16(theme);
      SRrect(258 + 56 , 82 + (3 * 48) , 48, 40, 10);
      text(String(sw + 1), 266 + 56, 92 + (3 * 48));
    }
    else {
      clr16(TFT_WHITE);
      SRrect(258 + 56 , 82 + (3 * 48) , 48, 40, 10);
      Tclr(theme);
      clr16(theme);
      Rrect(258 + 56 , 82 + (3 * 48) , 48, 40, 10);
      text(String(sw + 1), 266 + 56 , 92 + (3 * 48));
    }
  }
  else {
    if (bitRead(ledsub2.parm2, sw) == 1) {
      Tclr(TFT_WHITE);
      clr16(theme);
      SRrect(258 + (56 * (sw % 3)), 82 + ((sw / 3) * 48) , 48, 40, 10);
      text(String(sw + 1), 274 + (56 * (sw % 3)), 92 + (sw / 3) * 48);
    }
    else {
      clr16(TFT_WHITE);
      SRrect(258 + (56 * (sw % 3)), 82 + ((sw / 3) * 48) , 48, 40, 10);
      Tclr(theme);
      clr16(theme);
      Rrect(258 + (56 * (sw % 3)), 82 + ((sw / 3) * 48) , 48, 40, 10);
      text(String(sw + 1), 274 + (56 * (sw % 3)), 92 + (sw / 3) * 48);
    }
  }
}

void updateSlider(int per) {
  ledsub2.parm1 = per;
  clr16(TFT_WHITE);
  Srect(191, 235, 45, 35);
  Srect(195, 80, 38, 155);
  clr(230, 230, 230);
  Srect(211, 80, 6, 150);
  clr16(theme);
  Srect(211, 80 + map(per, 100, 0, 0, 150) , 6 , 150 - map(per, 100, 0, 0, 150));
  SRrect(196, 80 + map(per, 100, 0, 0, 130), 36, 20, 5);
  if (cx == 1) {
    Font(2);
  }
  else {
    Font(1);
  }
  Tclr(theme);
  led_intensity = per;
  text(String(led_intensity) , 216 - ((String(led_intensity)).length()*fontwidth), 240);
}

void brightness() {
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);
  clr(230, 230, 230);
  Srect(190 , 74, 52, 201);
  clr16(TFT_WHITE);
  Srect(190, 74, 48, 201);

  clr16(theme);
  //  Striangle(115, 50, 106, 68, 124, 68);
  //  Striangle(115, 298, 106, 280, 124, 280);
  Font(2);
  for (int i = 1; i <= 10; i++) {
    updateIcon(i);
  }
  updateSlider(ledsub2.parm1);

}

void ledsetting() {
  runningsetting = ledSettings;
  if (menuindex[0] != menuindex[2]) {
    ledSettings.selected = 1;
    drawMenu();
    displayStrings(ledSettings.selected);
    ledtimer(ledsub1.selected);
    menuindex[2] = menuindex[0];
  }
}

//====================================================================================================//
void riseSetting() {
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);
  Font(2);
  Tclr(theme);
  text(servosub1.heading1, 190 + 123 - (servosub1.heading1.length()*fontwidth), 84);
  clr16(theme);
  Striangle(230, 145, 260, 130, 260, 160);
  Striangle(396, 145, 366, 130, 366, 160);
  Rrect(270, 130, 86, 30, 10);
  Rrect(270, 178, 86, 30, 10);
  Rrect(195, 226, 236, 30, 10);
  Font(1);
  text(String(servosub1.parm1), 190 + 123 - (String(servosub1.parm1).length()*fontwidth), 137);
  text(servoSettings.setting2, 190 + 123 - (servoSettings.setting2.length()*fontwidth), 185);
  text(setcurrentposition0, 190 + 123 - (setcurrentposition0.length()*fontwidth), 234);
}

//====================================================================================================//

void fallSetting() {
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);
  Font(2);
  Tclr(theme);
  text(servosub2.heading1, 190 + 123 - (servosub2.heading1.length()*fontwidth), 84);
  clr16(theme);
  Striangle(230, 145, 260, 130, 260, 160);
  Striangle(396, 145, 366, 130, 366, 160);
  Rrect(270, 130, 86, 30, 10);
  Rrect(270, 178, 86, 30, 10);
  Rrect(195, 226, 236, 30, 10);
  Font(1);
  text(String(servosub2.parm1), 190 + 123 - (String(servosub2.parm1).length()*fontwidth), 137);
  text(servoSettings.setting3, 190 + 123 - (servoSettings.setting3.length()*fontwidth), 185);
  text(setcurrentposition0, 190 + 123 - (setcurrentposition0.length()*fontwidth), 234);
}


//====================================================================================================//

void speedSetting() {
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);
  Font(2);
  Tclr(theme);
  text(servosub3.heading1, 190 + 123 - (servosub3.heading1.length()*fontwidth), 84);
  Font(1);
  clr16(theme);
  Striangle(230, 145, 260, 130, 260, 160);
  Striangle(396, 145, 366, 130, 366, 160);
  Rrect(270, 130, 86, 30, 10);
  text(String(servosub3.parm1), 190 + 123 - (String(servosub3.parm1).length()*fontwidth), 137);
  if (servosub3.parm2 == 1) {
    SRrect(205, 202, 216, 30, 10);
    Tclr(TFT_WHITE);
    text(changeDirection0, 190 + 123 - (changeDirection0.length()*fontwidth), 209);
  }
  else {
    clr16(TFT_WHITE);
    SRrect(205, 202, 216, 30, 10);
    clr16(theme);
    Rrect(205, 202, 216, 30, 10);
    Tclr(theme);
    text(changeDirection0, 190 + 123 - (changeDirection0.length()*fontwidth), 209);
  }
}


//====================================================================================================//

void servosettings() {
  runningsetting = servoSettings;
  if (menuindex[0] != menuindex[2]) {
    servoSettings.selected = 1;
    drawMenu();
    displayStrings(servoSettings.selected);
    riseSetting();
    menuindex[2] = menuindex[0];
  }
}

//====================================================================================================//

void activeDateTime(int atv) {
  datetime.selected = atv;

  clr16(TFT_WHITE);
  for (int i = 0; i < 6; i++) {
    SRrect(205 + ((i % 3) * 60), 110 + (98 * (i / 3)), 47, 41, 10);
  }
  clr16(theme);
  Tclr(theme);
  Font(1);
  text(String(dt[0]), 229 - (String(dt[0]).length()*fontwidth), 123 );
  text(String(dt[1]), 289 - (String(dt[1]).length()*fontwidth), 123 );
  text(String(dt[2]), 349 - (String(dt[2]).length()*fontwidth), 123 );
  text(String(dt[3]), 229 - (String(dt[3]).length()*fontwidth), 221 );
  text(String(dt[4]), 289 - (String(dt[4]).length()*fontwidth), 221 );
  text(String(dt[5]), 349 - (String(dt[5]).length()*fontwidth), 221 );

  for (int i = 0; i < 6; i++) {
    Rrect(205 + ((i % 3) * 60), 110 + (98 * (i / 3)), 47, 41, 10);
  }

  Tclr(TFT_WHITE);

  switch (datetime.selected) {
    case 1:
      clr16(TFT_WHITE);
      SRrect(205 , 110 , 47, 41, 10);
      clr16(theme);
      SRrect(205 , 110 , 47, 41, 10);
      clr16(TFT_WHITE);
      text(String(dt[0]), 229 - (String(dt[0]).length()*fontwidth), 123 );
      break;

    case 2:
      clr16(TFT_WHITE);
      SRrect(205 + ((1 % 3) * 60), 110, 47, 41, 10);
      clr16(theme);
      SRrect(205 + ((1 % 3) * 60), 110, 47, 41, 10);
      clr16(TFT_WHITE);
      text(String(dt[1]), 289 - (String(dt[1]).length()*fontwidth), 123 );
      break;

    case 3:
      clr16(TFT_WHITE);
      SRrect(205 + ((2 % 3) * 60), 110 , 47, 41, 10);
      clr16(theme);
      SRrect(205 + ((2 % 3) * 60), 110 , 47, 41, 10);
      clr16(TFT_WHITE);
      text(String(dt[2]), 349 - (String(dt[2]).length()*fontwidth), 123 );
      break;

    case 4:
      clr16(TFT_WHITE);
      SRrect(205 + ((3 % 3) * 60), 208, 47, 41, 10);
      clr16(theme);
      SRrect(205 + ((3 % 3) * 60), 208, 47, 41, 10);
      clr16(TFT_WHITE);
      text(String(dt[3]), 229 - (String(dt[3]).length()*fontwidth), 221 );
      break;

    case 5:
      clr16(TFT_WHITE);
      SRrect(205 + ((4 % 3) * 60), 208, 47, 41, 10);
      clr16(theme);
      SRrect(205 + ((4 % 3) * 60), 208, 47, 41, 10);
      clr16(TFT_WHITE);
      text(String(dt[4]), 289 - (String(dt[4]).length()*fontwidth), 221 );
      break;

    case 6:
      clr16(TFT_WHITE);
      SRrect(205 + ((5 % 3) * 60), 208, 47, 41, 10);
      clr16(theme);
      SRrect(205 + ((5 % 3) * 60), 208, 47, 41, 10);
      clr16(TFT_WHITE);
      text(String(dt[5]), 349 - (String(dt[5]).length()*fontwidth), 221 );
      break;
  }
}

//====================================================================================================//

void dateTime() {
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);

  clr16(theme);
  Tclr(TFT_WHITE);

  SRrect(385, 156, 47, 41, 10);
  text("SET", 392, 167);
  Striangle(390, 136, 428, 136, 409, 107);
  Striangle(390, 217, 428, 217, 409, 247);

  Tclr(theme);

  Font(1);
  text(datetime.label3, 229 - (datetime.label3.length()*fontwidth), 155 );
  text(datetime.label2, 289 - (datetime.label2.length()*fontwidth), 155 );
  text(datetime.label1, 349 - (datetime.label1.length()*fontwidth), 155 );
  text(datetime.label4, 229 - (datetime.label4.length()*fontwidth), 253 );
  text(datetime.label5, 289 - (datetime.label5.length()*fontwidth), 253 );
  text(datetime.label6, 349 - (datetime.label6.length()*fontwidth), 253 );

  Font(2);
  text(datetime.heading1, 190 + 100 - (datetime.heading1.length()*fontwidth), 84);
  text(datetime.heading2, 190 + 100 - (datetime.heading2.length()*fontwidth), 182);
  activeDateTime(1);
}

//====================================================================================================//

void setlanguage(int lg) {
  lang.parm1 = lg;

  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);

  clr16(theme);
  Tclr(theme);

  Srect(190, 74, 246, 35);

  Rrect(240, 130, 146, 30, 10);
  Rrect(240, 190, 146, 30, 10);
  Font(1);
  text(language0, 190 + 123 - (language0.length()*fontwidth), 136);
  text(language1, 190 + 123 - (language1.length()*fontwidth), 196);
  Tclr(TFT_WHITE);
  text(lang.heading1, 190 + 123 - (lang.heading1.length()*fontwidth), 84);

  switch (lang.parm1) {
    case 1:
      SRrect(240, 130, 146, 30, 10);
      text(language0, 190 + 123 - (language0.length()*fontwidth), 136);
      initLanguage(0);
      break;

    case 2:
      SRrect(240, 190, 146, 30, 10);
      text(language1, 190 + 123 - (language1.length()*fontwidth), 196);
      initLanguage(1);
      break;
  }
}

//====================================================================================================//

void setPump() {
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);

  clr16(theme);
  Tclr(theme);

  Rrect(229, 150, 49, 41, 10);
  Rrect(347, 150, 49, 41, 10);
  Font(1);
  Striangle(239, 140, 254, 110, 269, 140);
  Striangle(357, 140, 372, 110, 387, 140);
  Striangle(239, 201, 254, 231, 269, 201);
  Striangle(357, 201, 372, 231, 387, 201);
  text(pumpSettings.heading1, 229 + 24 - (pumpSettings.heading1.length()*fontwidth), 84);
  text(pumpSettings.heading2, 347 + 24 - (pumpSettings.heading2.length()*fontwidth), 84);
  text(String(pumpSettings.parm1), 229 + 24 - (String(pumpSettings.parm1).length()*fontwidth), 162);
  text(String(pumpSettings.parm2), 347 + 24 - (String(pumpSettings.parm2).length()*fontwidth), 162);
  text("SECONDS", 229 + 24 - (String("MINUTES").length()*fontwidth), 245);
  text("MINUTES", 347 + 24 - (String("MINUTES").length()*fontwidth), 245);
}

//====================================================================================================//

void resetSave() {
  clr16(TFT_WHITE);
  Srect(190, 74, 246, 201);

  clr16(theme);
  Tclr(theme);

  Rrect(210, 120, 206, 30, 10);
  Rrect(210, 180, 206, 30, 10);

  text(saveReset.heading1, 190 + 123 - (saveReset.heading1.length()*fontwidth), 126);
  text(saveReset.heading2, 190 + 123 - (saveReset.heading2.length()*fontwidth), 186);
}

//====================================================================================================//

void settings() {
  runningsetting = Settings;
  if (menuindex[0] != menuindex[2]) {
    Settings.selected = 1;
    drawMenu();
    displayStrings(Settings.selected);
    dateTime();
    menuindex[2] = menuindex[0];
  }
}

//====================================================================================================//

void permission(int pr) {
  clr16(TFT_WHITE);
  SRrect(200, 110, 226, 110, 10);
  clr16(theme);
  Rrect(195, 110, 236, 110, 10);
  Font(1);
  if (pr == 1) {
    text(saveReset.label1, 190 + 123 - (saveReset.label1.length()*fontwidth), 120);
    Permission = 1;
  }
  else {
    text(saveReset.label2, 190 + 123 - (saveReset.label2.length()*fontwidth), 120);
    Permission = 2;
  }
  Rrect(190 + 31, 180, 61, 30, 10);
  Rrect(190 + 154, 180, 61, 30, 10);
  text(no, 190 + 61 - (no.length()*fontwidth), 186);
  text(yes0, 190 + 184 - (yes0.length()*fontwidth), 186);

}

//====================================================================================================//
