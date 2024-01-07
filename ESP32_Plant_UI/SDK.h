//====================================================================================================//

void taskHandeler() {
  receiveSTMdata();
  sendSTMdata(0);
  //=======================================================================

  if (millis() - scheduler[0] >= 1000) {
    //    Serial.println();
    //    Serial.print("No of loops executed: ");
    //    Serial.println(op);
    op = 0;
    if (menuindex[0] <= 1) {
      updateHS();
    }
    scheduler[0] = millis();
  }

  //=======================================================================

  for (int i = 0; i <= 4; i++) {
    if (chkin(0, (64 * i), 64, 64) == 1) {
      Serial.print("Option selected: ");
      if ((menuindex[0] == 1) && (i != 0)) {
        if (i == 4) {
          setmenu(0);
        }
        else {
          setmenu(i + 1);
        }
      }
      else {
        if (i == 0) {
          setmenu(i + 1);
        }
      }

    }
  }

  //=======================================================================
  handlesubmenu();
  managePump();
  manageLED();
  delay(touchDebounce);
}

//====================================================================================================//

void handlesubmenu() {
  switch (menuindex[0]) {
    case 2:
      touchled();
      break;

    case 3:
      touchServo();
      break;

    case 4:
      touchSettings();
      break;
  }
}

//====================================================================================================//

void setmenu(int mn) {
  int temp = menuindex[0];
  menuindex[0] = mn;
  Permission  = 0;
  switch (mn) {
    case 0:
      Serial.println(home0);
      homescreen();

      break;

    case 1:
      Serial.println("SIDE SCREEN");
      sidescreen();

      break;

    case 2:
      Serial.println(led_setting0);
      ledsetting();
      break;

    case 3:
      Serial.println(servoSettings.setting1);
      servosettings();

      break;

    case 4:
      Serial.println(Settings.setting1);
      settings();
      break;
  }
  menuindex[1] = temp;
  Serial.print("Menu selected: "); Serial.print(menuindex[0]); Serial.print(" Previous menu: "); Serial.print(menuindex[1]);
  Serial.print(" Drawn menu: "); Serial.println(menuindex[2]);
}

//====================================================================================================//

void manageLED() {
  if ((datetime.parm1 != 0) && (datetime.parm2 != 0) && (datetime.parm3 != 0) && (datetime.parm4 != 0)) {
    int timestp = ((ledsub1.parm5 * 60) + ledsub1.parm6);
    int currenttime = (datetime.parm1 * 60) + datetime.parm2;
    int selectedValue = 0;
    switch (ledsub1.selected) {
      case 1:
        selectedValue = ledsub1.parm1;
        break;

      case 2:
        selectedValue = ledsub1.parm1;
        break;

      case 3:
        selectedValue = ledsub1.parm1;
        break;

      case 4:
        selectedValue = ledsub1.parm1;
        break;

    }
//    Serial.print("TIMESTAMP : ");Serial.print(timestp);Serial.print(" Current time: ");Serial.print(currenttime);
//    Serial.print("TIMESTAMP + SELECTED VALUE: ");Serial.println(timestp + selectedValue);
    if ((timestp + selectedValue) > 1439) {
      if ((currenttime >= timestp) || (currenttime <= (timestp + selectedValue - 1439))) {
        ledstat = ledsub2.parm2;
      }
      else {
        ledstat = 0;
      }
    }
    else {
      if ((currenttime >= timestp) && (currenttime <= (timestp + selectedValue))) {
        ledstat = ledsub2.parm2;
      }
      else {
        ledstat = 0;
      }
    }
  }
}

//====================================================================================================//

void managePump() {
  if (millis() - pumptimer < pumpSettings.parm1) {
    pump = 1;
  }
  else {
    if (millis() - pumptimer <= ((pumpSettings.parm1) + (60 * pumpSettings.parm2))) {
      pump = 0;
      pumptimer = millis();
    }
  }
}

//====================================================================================================//

void writeFile(fs::FS & fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\r\n", path);

  fs::File file;
  file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("- failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("- file written");
  } else {
    Serial.println("- frite failed");
  }
}

//====================================================================================================//


void saveSettings() {
  String temp;
  temp = ',' + String(ledsub1.selected) + ',' + String(ledsub2.parm1) + ',' + String(ledsub2.parm2) + ',' + String(servosub1.parm1) + ',' + String(servosub2.parm1) + ',' + String(servosub3.parm1) + ',' + String(servosub3.parm2) + ',' + String(lang.parm1) + ',' + String(pumpSettings.parm1) + ',' + String(pumpSettings.parm2) + ',' + String(ledsub1.parm5) + ',' + String(ledsub1.parm6) + ',';
  Serial.println();
  Serial.println(temp);
  writeFile(SPIFFS, filename.c_str(), temp.c_str());
  delay(10);

}

//====================================================================================================//

void loadSettings() {
  String temp;
  int index[20];
  Serial.println();
  Serial.print("Reading file: ");
  Serial.println( filename);
  fs::File file;
  file = SPIFFS.open(filename);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return;
  }

  Serial.println("- read from file:");
  while (file.available()) {
    temp.concat(char(file.read()));
  }
  //Serial.println(temp);
  int j = 0;
  for (int i = 0; i < temp.length(); i++) {
    if (temp[i] == ',') {
      index[j] = i;
      j++;
    }
  }
  for (int i = 0; i < 9; i++) {
    //Serial.println(temp.substring(index[i]+1,index[i+1]));
  }
  ledsub1.selected = temp.substring(index[0] + 1, index[1]).toInt();
  ledsub2.parm1 = temp.substring(index[1] + 1, index[2]).toInt();
  ledsub2.parm2 = temp.substring(index[2] + 1, index[3]).toInt();
  servosub1.parm1 = temp.substring(index[3] + 1, index[4]).toInt();
  servosub2.parm1 = temp.substring(index[4] + 1, index[5]).toInt();
  servosub3.parm1 = temp.substring(index[5] + 1, index[6]).toInt();
  servosub3.parm2 = temp.substring(index[6] + 1, index[7]).toInt();
  lang.parm1 = temp.substring(index[7] + 1, index[8]).toInt();
  pumpSettings.parm1 = temp.substring(index[8] + 1, index[9]).toInt();
  pumpSettings.parm2 = (temp.substring(index[9] + 1, index[10])).toInt();
  ledsub1.parm5 = (temp.substring(index[10] + 1, index[11])).toInt();
  ledsub1.parm6 = (temp.substring(index[11] + 1, index[12])).toInt();
  temp = ',' + String(ledsub1.selected) + ',' + String(ledsub2.parm1) + ',' + String(ledsub2.parm2) + ',' + String(servosub1.parm1) + ',' + String(servosub2.parm1) + ',' + String(servosub3.parm1) + ',' + String(servosub3.parm2) + ',' + String(lang.parm1) + ',' + String(pumpSettings.parm1) + ',' + String(pumpSettings.parm2) + ',' + String(ledsub1.parm5) + ',' + String(ledsub1.parm6) + ',';
  Serial.println();
  Serial.print("Loading Settings: ");
  Serial.println(temp);
  file.close();
  delay(10);
}

//====================================================================================================//
