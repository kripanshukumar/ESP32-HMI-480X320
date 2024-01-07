//========================================================================================================//

void touchled() {
  int selectedmenu = submenu();
  switch (selectedmenu) {
    case 1:
      ledSettings.selected = 1;
      displayStrings(ledSettings.selected);
      ledtimer(ledsub1.selected);
      break;

    case 2:
      ledSettings.selected = 2;
      displayStrings(ledSettings.selected);
      brightness();
      break;
  }
  switch (ledSettings.selected) {
    case 1:
      if (chkin(190 + 14, 90 + 28, 47, 47) == 1) {
        ledtimer(1);

      }
      if (chkin( 190 + (70), 90 + (28), 47, 47) == 1) {
        ledtimer(2);
      }
      if (chkin(190 + 127, 90 + (28), 47, 47) == 1) {
        ledtimer(3);
      }
      if (chkin( 190 + (184), 90 + 28 , 47, 47) == 1) {
        ledtimer(4);
      }
      if (chkin(190 + (184), 209, 47, 47) == 1) {
        if (ledsub1.parm7 == 1) {
          ledsub1.parm5++;
          if (ledsub1.parm5 >= 23) {
            ledsub1.parm5 = 23;
          }
          Tclr(TFT_WHITE);
          clr16(theme);
          SRrect( 185 + (70), 209, 47, 47, 15);
          text(String(ledsub1.parm5), 222 + (56.76) - (String(ledsub1.parm5).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
        }
        else {
          ledsub1.parm6++;
          if (ledsub1.parm6 >= 59) {
            ledsub1.parm6 = 59;
          }
          Tclr(TFT_WHITE);
          clr16(theme);
          SRrect( 195 + 127, 209, 47, 47, 15);
          text(String(ledsub1.parm6), 232 + (56.76 * 2) - (String(ledsub1.parm6).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
        }
      }
      if (chkin(190 + 14, 209, 47, 47) == 1) {
        if (ledsub1.parm7 == 1) {
          ledsub1.parm5--;
          if (ledsub1.parm5 <= 0) {
            ledsub1.parm5 = 0;
          }
          Tclr(TFT_WHITE);
          clr16(theme);
          SRrect( 185 + (70), 209, 47, 47, 15);
          text(String(ledsub1.parm5), 222 + (56.76) - (String(ledsub1.parm5).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
        }
        else {
          ledsub1.parm6--;
          if (ledsub1.parm6 <= 0) {
            ledsub1.parm6 = 0;
          }
          Tclr(TFT_WHITE);
          clr16(theme);
          SRrect( 195 + 127, 209, 47, 47, 15);
          text(String(ledsub1.parm6), 232 + (56.76 * 2) - (String(ledsub1.parm6).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
        }
      }
      if (chkin(185 + (70), 209, 47, 47) == 1) {
        ledsub1.parm7 = 1;
        clr16(TFT_WHITE);
        SRrect( 195 + 127, 209, 47, 47, 15);
        clr16(theme);
        Tclr(theme);
        Rrect( 195 + 127, 209, 47, 47, 15);
        text(String(ledsub1.parm6), 232 + (56.76 * 2) - (String(ledsub1.parm6).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
        Tclr(TFT_WHITE);
        SRrect( 185 + (70), 209, 47, 47, 15);
        text(String(ledsub1.parm5), 222 + (56.76) - (String(ledsub1.parm5).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
      }
      if (chkin(195 + 127, 209, 47, 47) == 1) {
        ledsub1.parm7 = 0;
        clr16(TFT_WHITE);
        SRrect( 185 + (70), 209, 47, 47, 15);
        clr16(theme);
        Tclr(theme);
        Rrect( 185 + (70), 209, 47, 47, 15);
        text(String(ledsub1.parm5), 222 + (56.76) - (String(ledsub1.parm5).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
        Tclr(TFT_WHITE);
        SRrect( 195 + 127, 209, 47, 47, 15);
        text(String(ledsub1.parm6), 232 + (56.76 * 2) - (String(ledsub1.parm6).length() * fontwidth), 233 -  (tft.fontHeight(GFXFF) / 2));
      }
      break;

    case 2:
      if (chkin(195, 75, 38, 160) == 1) {
        ledsub2.parm1 = constrain(map(y, 80, 230, 100, 0), 0, 100);
        Serial.println(ledsub2.parm1);
        updateSlider(ledsub2.parm1);
        delay(touchDebounce);
      }
      for (int i = 0; i < 9; i++) {
        if (chkin(258 + (56 * (i % 3)), 82 + ((i / 3) * 48) , 48, 40) == 1) {
          bitWrite(ledsub2.parm2, i, !(bitRead(ledsub2.parm2, i)));
          updateIcon(i + 1);
          delay(touchDebounce);
        }
      }
      if (chkin(258 + 56 , 82 + (3 * 48) , 48, 40) == 1) {
        bitWrite(ledsub2.parm2, 9, !(bitRead(ledsub2.parm2, 9)));
        updateIcon(10);
        delay(touchDebounce);
      }
      break;
  }
}

//========================================================================================================//

void touchServo() {
  int selectedmenu = submenu();
  switch (selectedmenu) {
    case 1:
      servoSettings.selected = 1;
      displayStrings(servoSettings.selected);
      riseSetting();
      break;

    case 2:
      servoSettings.selected = 2;
      displayStrings(servoSettings.selected);
      fallSetting();
      break;

    case 3:
      servoSettings.selected = 3;
      displayStrings(servoSettings.selected);
      speedSetting();
      break;
  }

  switch (servoSettings.selected) {
    case 1:
      if (chkin(340, 125, 60, 40) == 1) {
        servosub1.parm1 += increment;
        if (servosub1.parm1 >= 1000) {
          servosub1.parm1 = 1000;
        }
        Tclr(theme);
        clr16(TFT_WHITE);
        SRrect(272, 132, 82, 26, 10);
        Font(1);
        text(String(servosub1.parm1), 190 + 123 - (String(servosub1.parm1).length()*fontwidth), 137);
        increment++;
        delay(touchDebounce);
      }
      else {
        if (chkin(210, 125, 55, 40) == 1) {
          servosub1.parm1 -= increment;
          if (servosub1.parm1 <= 23) {
            servosub1.parm1 = 23;
          }
          Tclr(theme);
          clr16(TFT_WHITE);
          SRrect(272, 132, 82, 26, 10);
          Font(1);
          text(String(servosub1.parm1), 190 + 123 - (String(servosub1.parm1).length()*fontwidth), 137);
          increment++;
        }
        else {
          increment = 1;
        }
        delay(touchDebounce);
      }
      if (chkin(270, 178, 86, 30) == 1) {
        Font(1);
        clr16(theme);
        SRrect(270, 178, 86, 30, 10);
        Tclr(TFT_WHITE);
        text(servoSettings.setting2, 190 + 123 - (servoSettings.setting2.length()*fontwidth), 185);
        sendSTMdata(2);
      }
      else {
        if (input() == 0) {
          Font(1);
          clr16(TFT_WHITE);
          SRrect(270, 178, 86, 30, 10);
          clr16(theme);
          Rrect(270, 178, 86, 30, 10);
          Tclr(theme);
          text(servoSettings.setting2, 190 + 123 - (servoSettings.setting2.length()*fontwidth), 185);
          sendSTMdata(3);
        }
      }
      if (chkin(195, 226, 236, 30) == 1) {
        servosub1.parm1 = servoFeedback;
        Font(1);
        clr16(theme);
        Tclr(TFT_WHITE);
        SRrect(195, 226, 236, 30, 10);
        text(setcurrentposition0, 190 + 123 - (setcurrentposition0.length()*fontwidth), 234);

        delay(touchDebounce);
        Tclr(theme);
        clr16(TFT_WHITE);
        SRrect(272, 132, 82, 26, 10);
        Font(1);
        text(String(servosub1.parm1), 190 + 123 - (String(servosub1.parm1).length()*fontwidth), 137);

        clr16(TFT_WHITE);
        SRrect(195, 226, 236, 30, 10);
        clr16(theme);
        Rrect(195, 226, 236, 30, 10);
        Tclr(theme);
        text(setcurrentposition0, 190 + 123 - (setcurrentposition0.length()*fontwidth), 234);
      }
      break;
    //----------------------------------------------------------------------------------------------
    case 2:
      if (chkin(340, 125, 60, 40) == 1) {
        servosub2.parm1 += increment;
        if (servosub2.parm1 >= 1000) {
          servosub2.parm1 = 1000;
        }
        Tclr(theme);
        clr16(TFT_WHITE);
        SRrect(272, 132, 82, 26, 10);
        Font(1);
        text(String(servosub2.parm1), 190 + 123 - (String(servosub2.parm1).length()*fontwidth), 137);
        increment++;
        delay(touchDebounce);
      }
      else {
        if (chkin(210, 125, 55, 40) == 1) {
          servosub2.parm1 -= increment;
          if (servosub2.parm1 <= 23) {
            servosub2.parm1 = 23;
          }
          Tclr(theme);
          clr16(TFT_WHITE);
          SRrect(272, 132, 82, 26, 10);
          Font(1);
          text(String(servosub2.parm1), 190 + 123 - (String(servosub2.parm1).length()*fontwidth), 137);
          increment++;
        }
        else {
          increment = 1;
        }
        delay(touchDebounce);
      }
      if (chkin(270, 178, 86, 30) == 1) {
        Font(1);
        clr16(theme);
        SRrect(270, 178, 86, 30, 10);
        Tclr(TFT_WHITE);
        text(servoSettings.setting3, 190 + 123 - (servoSettings.setting3.length()*fontwidth), 185);
        sendSTMdata(4);
      }
      else {
        if (input() == 0) {
          Font(1);
          clr16(TFT_WHITE);
          SRrect(270, 178, 86, 30, 10);
          clr16(theme);
          Rrect(270, 178, 86, 30, 10);
          Tclr(theme);
          text(servoSettings.setting3, 190 + 123 - (servoSettings.setting3.length()*fontwidth), 185);
          sendSTMdata(5);
        }
      }
      if (chkin(195, 226, 236, 30) == 1) {
        servosub2.parm1 = servoFeedback;
        Font(1);
        clr16(theme);
        Tclr(TFT_WHITE);
        SRrect(195, 226, 236, 30, 10);
        text(setcurrentposition0, 190 + 123 - (setcurrentposition0.length()*fontwidth), 234);

        delay(touchDebounce);
        Tclr(theme);
        clr16(TFT_WHITE);
        SRrect(272, 132, 82, 26, 10);
        Font(1);
        text(String(servosub2.parm1), 190 + 123 - (String(servosub2.parm1).length()*fontwidth), 137);

        clr16(TFT_WHITE);
        SRrect(195, 226, 236, 30, 10);
        clr16(theme);
        Rrect(195, 226, 236, 30, 10);
        Tclr(theme);
        text(setcurrentposition0, 190 + 123 - (setcurrentposition0.length()*fontwidth), 234);
      }
      break;
    //-------------------------------------------------------------------------------------------------
    case 3:
      if (chkin(340, 125, 60, 40) == 1) {
        servosub3.parm1 += increment;
        if (servosub3.parm1 >= 1000) {
          servosub3.parm1 = 1000;
        }
        Tclr(theme);
        clr16(TFT_WHITE);
        SRrect(272, 132, 82, 26, 10);
        Font(1);
        text(String(servosub3.parm1), 190 + 123 - (String(servosub3.parm1).length()*fontwidth), 137);
        increment++;
        delay(touchDebounce);
      }
      else {
        if (chkin(210, 125, 55, 40) == 1) {
          servosub3.parm1 -= increment;
          if (servosub3.parm1 <= 20) {
            servosub3.parm1 = 20;
          }
          Tclr(theme);
          clr16(TFT_WHITE);
          SRrect(272, 132, 82, 26, 10);
          Font(1);
          text(String(servosub3.parm1), 190 + 123 - (String(servosub3.parm1).length()*fontwidth), 137);
          increment++;
        }
        else {
          increment = 1;
        }
        delay(touchDebounce);
      }
      if (chkin(205, 202, 216, 30) == 1) {
        servosub3.parm2 = !servosub3.parm2;
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
      break;
  }
}

//========================================================================================================//

void touchSettings() {
  int selectedmenu = submenu();
  switch (selectedmenu) {
    case 1:
      Settings.selected = 1;
      displayStrings(Settings.selected);
      dateTime();
      break;

    case 2:
      Settings.selected = 2;
      displayStrings(Settings.selected);
      setlanguage(lang.parm1);
      break;

    case 3:
      Settings.selected = 3;
      displayStrings(Settings.selected);
      setPump();
      break;

    case 4:
      Settings.selected = 4;
      displayStrings(Settings.selected);
      resetSave();
      break;
  }
  int increment = 0;
  switch (Settings.selected) {
    case 1:
      for (int i = 0; i < 6; i++) {
        if (chkin(190 + ((i % 3) * 60), 110 + (98 * (i / 3)), 47, 41) == 1) {
          activeDateTime(i + 1);
        }
      }
      if (chkin(370, 80, 70, 70) == 1) {
        increment = 1;
        delay(touchDebounce);
      }
      else {
        if (chkin(370, 210, 70, 70) == 1) {
          increment = -1;
          delay(touchDebounce);
        }
        else {
          increment = 0;
        }
      }
      clr16(theme);
      Tclr(TFT_WHITE);
      Font(1);
      if (increment != 0) {
        switch (datetime.selected) {
          case 1:
            dt[0] += increment;
            dt[0] = constrain(dt[0], 0, 23);
            clr16(TFT_WHITE);
            SRrect(205 , 110 , 47, 41, 10);
            clr16(theme);
            SRrect(205 , 110 , 47, 41, 10);
            clr16(TFT_WHITE);
            text(String(dt[0]), 229 - (String(dt[0]).length()*fontwidth), 123 );
            break;

          case 2:
            dt[1] += increment;
            dt[1] = constrain(dt[1], 0, 59);
            clr16(TFT_WHITE);
            SRrect(205 + ((1 % 3) * 60), 110, 47, 41, 10);
            clr16(theme);
            SRrect(205 + ((1 % 3) * 60), 110, 47, 41, 10);
            clr16(TFT_WHITE);
            text(String(dt[1]), 289 - (String(dt[1]).length()*fontwidth), 123 );
            break;

          case 3:
            dt[2] += increment;
            dt[2] = constrain(dt[2], 0, 59);
            clr16(TFT_WHITE);
            SRrect(205 + ((2 % 3) * 60), 110 , 47, 41, 10);
            clr16(theme);
            SRrect(205 + ((2 % 3) * 60), 110 , 47, 41, 10);
            clr16(TFT_WHITE);
            text(String(dt[2]), 349 - (String(dt[2]).length()*fontwidth), 123 );
            break;

          case 4:
            dt[3] += increment;
            dt[3] = constrain(dt[3], 1, 31);
            clr16(TFT_WHITE);
            SRrect(205 + ((3 % 3) * 60), 208, 47, 41, 10);
            clr16(theme);
            SRrect(205 + ((3 % 3) * 60), 208, 47, 41, 10);
            clr16(TFT_WHITE);
            text(String(dt[3]), 229 - (String(dt[3]).length()*fontwidth), 221 );
            break;

          case 5:
            dt[4] += increment;
            dt[4] = constrain(dt[4], 1, 12);
            clr16(TFT_WHITE);
            SRrect(205 + ((4 % 3) * 60), 208, 47, 41, 10);
            clr16(theme);
            SRrect(205 + ((4 % 3) * 60), 208, 47, 41, 10);
            clr16(TFT_WHITE);
            text(String(dt[4]), 289 - (String(dt[4]).length()*fontwidth), 221 );
            break;

          case 6:
            dt[5] += increment;
            dt[5] = constrain(dt[5], 1, 1000);
            clr16(TFT_WHITE);
            SRrect(205 + ((5 % 3) * 60), 208, 47, 41, 10);
            clr16(theme);
            SRrect(205 + ((5 % 3) * 60), 208, 47, 41, 10);
            clr16(TFT_WHITE);
            text(String(dt[5]), 349 - (String(dt[5]).length()*fontwidth), 221 );
            break;
        }
      }
      if (chkin(385, 156, 47, 41) == 1) {
        if (millis() - dattimetimer > 600) {
          String temp;
          temp = ',' +  String(passcode) + ',' + '1' + ',' + String(dt[0]) + ',' + String(dt[1]) + ',' + String(dt[2]) + ',' + String(dt[3]) + ',' + String(dt[4]) + ',' + String(dt[5]) + ',';
          Serial2.println(temp);
          dattimetimer = millis();
        }
      }
      break;

    case 2:
      if (chkin(240, 130, 146, 30) == 1) {
        setlanguage(1);
      }
      if (chkin(240, 190, 146, 30) == 1) {
        setlanguage(2);
      }
      break;

    case 3:
      clr16(TFT_WHITE);
      Tclr(theme);
      Font(1);
      if (chkin(239, 110, 30, 30) == 1) {
        SRrect(230, 151, 47, 39, 10);
        pumpSettings.parm1 += 1;
        pumpSettings.parm1 = constrain(pumpSettings.parm1, 1, 60);
        text(String(pumpSettings.parm1), 229 + 24 - (String(pumpSettings.parm1).length()*fontwidth), 162);
      }
      if (chkin(239, 201, 30, 30) == 1) {
        SRrect(230, 151, 47, 39, 10);
        pumpSettings.parm1 -= 1;
        pumpSettings.parm1 = constrain(pumpSettings.parm1, 1, 60);
        text(String(pumpSettings.parm1), 229 + 24 - (String(pumpSettings.parm1).length()*fontwidth), 162);
      }
      if (chkin(357, 110, 30, 30) == 1) {
        SRrect(348, 151, 47, 39, 10);
        pumpSettings.parm2 += 1;
        pumpSettings.parm2 = constrain(pumpSettings.parm2, 1, 59);
        text(String(pumpSettings.parm2), 347 + 24 - (String(pumpSettings.parm2).length()*fontwidth), 162);
      }
      if (chkin(357, 201, 30, 30) == 1) {
        SRrect(348, 151, 47, 39, 10);
        pumpSettings.parm2 -= 1;
        pumpSettings.parm2 = constrain(pumpSettings.parm2, 1, 59);
        text(String(pumpSettings.parm2), 347 + 24 - (String(pumpSettings.parm2).length()*fontwidth), 162);
      }
      break;

    case 4:
      if (Permission == 0) {
        if (chkin(210, 120, 206, 30) == 1) {
          clr16(theme);
          Tclr(TFT_WHITE);
          SRrect(210, 120, 206, 30, 10);
          text(saveReset.heading1, 190 + 123 - (saveReset.heading1.length()*fontwidth), 126);
          delay(200);
          clr16(TFT_WHITE);
          SRrect(210, 120, 206, 30, 10);
          Tclr(theme);
          clr16(theme);
          Rrect(210, 120, 206, 30, 10);
          text(saveReset.heading1, 190 + 123 - (saveReset.heading1.length()*fontwidth), 126);
          permission(1);
        }
        if (chkin(210, 180, 206, 30) == 1) {
          clr16(theme);
          Tclr(TFT_WHITE);
          SRrect(210, 180, 206, 30, 10);
          text(saveReset.heading1, 190 + 123 - (saveReset.heading1.length()*fontwidth), 126);
          delay(200);
          clr16(TFT_WHITE);
          SRrect(210, 180, 206, 30, 10);
          Tclr(theme);
          clr16(theme);
          Rrect(210, 180, 206, 30, 10);
          text(saveReset.heading1, 190 + 123 - (saveReset.heading1.length()*fontwidth), 186);
          permission(2);
        }
      }
      else {
        if (chkin(190 + 31, 180, 61, 30) == 1) {
          Font(1);
          clr16(theme);
          Tclr(TFT_WHITE);
          SRrect(190 + 31, 180, 61, 30, 10);
          text(no, 190 + 61 - (no.length()*fontwidth), 186);
          delay(100);
          resetSave();
          Permission = 0;
        }
        if (chkin(190 + 154, 180, 61, 30) == 1) {
          Font(1);
          clr16(theme);
          Tclr(TFT_WHITE);
          SRrect(190 + 154, 180, 61, 30, 10);
          text(yes0, 190 + 184 - (yes0.length()*fontwidth), 186);
          delay(100);
          switch (Permission) {
            case 1:
              ledsub1.selected = DefalutTimerSelection;
              ledsub2.parm1 = 32767;
              ledsub2.parm2 = defalutLedIntensity;
              servosub1.parm1 = DefaultRiseValue;
              servosub2.parm1 = DefaultFallValue;
              servosub3.parm1 = DefaultServoSpeed;
              servosub3.parm2 = DefaultServoDirection;
              lang.parm1 = Defaultlanguage;
              pumpSettings.parm1 = defaultPumpOn;
              pumpSettings.parm2 = DefaultPumpOff;
              saveSettings();
              break;

            case 2:
              saveSettings();
              break;
          }
          resetSave();
          Permission = 0;
        }
      }
      break;
  }
}
//========================================================================================================//
int input() {
  int state[4] = {0, 0, 0, 0};

  state[0] = digitalRead(yp);
  state[1] = digitalRead(xm);
  state[2] = digitalRead(ym);
  state[3] = digitalRead(xp);

  pinMode(yp, INPUT_PULLUP);
  pinMode(ym, INPUT_PULLUP);
  pinMode(xp, OUTPUT);
  pinMode(xm, OUTPUT);

  digitalWrite(xm, HIGH);
  digitalWrite(xp, LOW);
  delayMicroseconds(20);
  rawY = 4095 - analogRead(ym);

  pinMode(xp, INPUT_PULLUP);
  pinMode(xm, INPUT_PULLUP);
  pinMode(yp, OUTPUT);
  pinMode(ym, OUTPUT);
  digitalWrite(ym, LOW);
  digitalWrite(yp, HIGH);
  delayMicroseconds(20);
  rawX = 4095 - analogRead(xp);

  pinMode(yp, OUTPUT);
  pinMode(ym, OUTPUT);
  pinMode(xp, OUTPUT);
  pinMode(xm, OUTPUT);

  digitalWrite(yp, state[0]);
  digitalWrite(xm, state[1]);
  digitalWrite(ym, state[2]);
  digitalWrite(xp, state[3]);
  if ((rawX <= 5) || (rawY <= 5)) {
    return 0;
  }
  else {
    //x = ((rawX - calibrationMatrix[0][0]) * XcalibrationFactor) + 9;
    //y = ((rawY - calibrationMatrix[0][1]) * YcalibrationFactor) + 9;
    //if(cx == 1){
    x = map(rawX, calibrationMatrix[0][0], calibrationMatrix[1][0], 9, 469);
    y = map(rawY, calibrationMatrix[0][1], calibrationMatrix[2][1], 9, 309);
    //    }
    //    else{
    //      x =(1.5 * map(rawX, calibrationMatrix[0][0], calibrationMatrix[1][0], 9, 309));
    //    y = (1.333333* map(rawY, calibrationMatrix[0][1], calibrationMatrix[3][1], 9, 229));
    //    }
    //Serial.print("X : "); Serial.print(x); Serial.print('\t');
    //Serial.print("Y : "); Serial.println(y);// Serial.print('\t');
    //    Serial.print("RAW X : "); Serial.print(rawX); Serial.print('\t');
    //    Serial.print("RAW Y : "); Serial.println(rawY);
    return 1;
  }
}

void drawbox(int x1, int y1, int O) {
  //x1 = x1 * cx;
  //y1 = y1 * cy;
  if (O == 0) {
    clr16(TFT_BLACK);
  }
  else {
    clr16(TFT_WHITE);
  }
  tft.drawRect(x1, y1,  19,  19, color);
  tft.drawFastHLine(x1  , y1 + 9 ,  19, color);
  tft.drawFastVLine((x1 + 9) , y1 ,  19, color);

}

void calibrateInput() {
  scr16(TFT_BLACK);
  clr16(theme);
  Font(2);
  Tclr(TFT_WHITE);
  text(calibrationMSG, 0, ((tft.height() / 2) - (tft.fontHeight(GFXFF) / 2)));
  text(calibrationMSG2, ((tft.width() / 2) - (calibrationMSG2.length() / 2) * 14), ((tft.height() / 2) + (tft.fontHeight(GFXFF) / 2)));
  int rep = 0;
  Tclr(TFT_RED);
  for (int i = 0; i <= 3; i++) {
    clr16(TFT_BLACK);
    Srect(100, 210, 400, 250);
    switch (i) {
      case 0:
        drawbox(0, 0, 1);
        text(calibrationMSG3, ((tft.width() / 2) - (calibrationMSG3.length() / 2) * 14), 240 );
        break;

      case 1:
        drawbox(0, 0, 0);
        if (cx == 1) {
          drawbox(459, 0, 1);
        }
        else {
          drawbox(299, 0, 1);
        }
        text(calibrationMSG4, ((tft.width() / 2) - (calibrationMSG4.length() / 2) * 14), 240 );

        break;

      case 2:
        if (cx == 1) {
          drawbox(459, 0, 0);
          drawbox(0, 299, 1);
        }
        else {
          drawbox(299, 0, 0);
          drawbox(0, 219, 1);
        }
        text(calibrationMSG5, ((tft.width() / 2) - (calibrationMSG5.length() / 2) * 14), 240);
        break;

      case 3:
        if (cx == 1) {
          drawbox(0, 299, 0);
          drawbox(459, 299, 1);
        }
        else {
          drawbox(0, 219, 0);
          drawbox(299, 219, 1);
        }
        text(calibrationMSG6, ((tft.width() / 2) - (calibrationMSG6.length() / 2) * 14), 240);
        break;

    }
    xbuf = 0;
    ybuf = 0;
    avgx = 0;
    avgy = 0;
    rep = 0;
    uint16_t dist = 10000;

    while (rep < 10) {
      if (input() == 1) {
        if (i != 0) {
          dist = pow((pow(calibrationMatrix[i - 1][0] - rawX, 2) + pow(calibrationMatrix[i - 1][1] - rawY, 2)), 0.5);
          Serial.println();
          Serial.print("DISTANCE : "); Serial.println(dist);
        }
        if (dist >= 700) {
          xbuf += rawX;
          ybuf += rawY;
          rep += 1;
          delay(20);
        }
      }
    }
    avgx = xbuf / 10;
    avgy = ybuf / 10;
    Serial.print("AVG X: "); Serial.print(avgx); Serial.print('\t');
    Serial.print("AVG Y: "); Serial.println(avgy);
    calibrationMatrix[i][0] = avgx;
    calibrationMatrix[i][1] = avgy;
  }
  XcalibrationFactor = float((469 - 9) * cx) / ((calibrationMatrix[1][0] - calibrationMatrix[0][0]));
  YcalibrationFactor = float((309 - 9) * cy) / ((calibrationMatrix[2][1] - calibrationMatrix[0][1]));

  Serial.print(XcalibrationFactor, 6); Serial.print('\t');
  Serial.println(YcalibrationFactor, 6);

  clr16(TFT_BLACK);
  Srect(0, 0, 479, 319);
  text("DONE", 200, ((tft.height() / 2) + (tft.fontHeight(GFXFF) / 2)));
  delay(2000);
}

int chkin(int x1, int y1, int x2, int y2) {
  if (input() == 1) {
    if ( ( x > x1) && ( x < (x1 + x2))) {
      if ((y > y1) && (y < (y1 + y2))) {
        return 1;
      }
    }
  }
  //  String temp = "X1 :" + String(x1) + " Y1 :" + String(y1) + " X2 :" + String(x2) + " Y2 :" + String(y2);
  //  Serial.print("Required Range: "); Serial.println(temp);
  //  temp = " X: " + String(x) + " Y: " + String(y);
  //  Serial.print("Current touched at: "); Serial.println(temp);
  return 0;
}

int submenu() {
  for (int i = 1 ; i <= runningsetting.count; i++) {
    if (chkin(48, 44 + (33 * i), 134, 30) == 1) {
      Permission = 0;
      Serial.print("Selected submenu : "); Serial.println(i + 1);
      return i;
    }
  }
  return -1;
}
