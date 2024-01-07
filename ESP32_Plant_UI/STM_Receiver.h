void receiveSTMdata() {
  String temporary;
  int rcv = 0;
  int commaindex[30];
  int j = 0;
  if (Serial2.available()) {
    temporary = Serial2.readStringUntil('\n');
    rcv = 1;
  }
  if (rcv == 1) {
    //    Serial.println();
    //    Serial.print("DATA RECEIVER FROM STM32: ");
    Serial.println(temporary);
    for (int i = 0; i < temporary.length(); i++) {
      if (temporary[i] == ',') {
        commaindex[j] = i;
        j++;
      }
    }
    if ( j == 14) {
      if (temporary.substring(commaindex[0] + 1, commaindex[1]).toInt() == passcode) {
        //Serial.println("PASSCODE IS CORRECT");
        datetime.parm1 = temporary.substring(commaindex[1] + 1, commaindex[2]).toInt();
        datetime.parm2 = temporary.substring(commaindex[2] + 1, commaindex[3]).toInt();
        datetime.parm3 = temporary.substring(commaindex[3] + 1, commaindex[4]).toInt();
        datetime.parm4 = temporary.substring(commaindex[4] + 1, commaindex[5]).toInt();
        datetime.parm5 = temporary.substring(commaindex[5] + 1, commaindex[6]).toInt();
        datetime.parm6 = temporary.substring(commaindex[6] + 1, commaindex[7]).toInt();
        conc = temporary.substring(commaindex[7] + 1, commaindex[8]).toFloat();
        pump = temporary.substring(commaindex[8] + 1, commaindex[9]).toInt();
        ph = temporary.substring(commaindex[9] + 1, commaindex[10]).toInt();
        temperature = temporary.substring(commaindex[10] + 1, commaindex[11]).toInt();
        waterlevel = temporary.substring(commaindex[11] + 1, commaindex[12]).toInt();
        servoFeedback = temporary.substring(commaindex[12] + 1, commaindex[13]).toInt();
        //        Serial.print("Feedback = ");
        //        Serial.println(servoFeedback);
        trcv = millis();
      }
    }
  }
  else {
    if (millis() - trcv > 1000) {
      Serial.println();
      Serial.println("POOR CONNECTION WITH STM32");
      digitalWrite(LED, HIGH);
    }
    else {
      digitalWrite(LED, LOW);
    }
  }
}

void sendSTMdata(int lsk) {
  String temp;
  if (millis() - stmdatatimer >= 500) {
    switch (lsk) {
      case 0:
        //Serial.println("CASE 0");
        temp = ',' + String(passcode) + ',' + '0' + ',' + String(pump) + ',' + String(ledstat) + ',' + String(servosub1.parm1) + ',' + String(servosub2.parm1) + ',' + String(servosub3.parm1) + ',' + String(servosub3.parm2) +','+String(menuindex[0])+ ',' + String(ledsub2.parm1) +",\n";
        //Serial.println(temp);
        Serial2.println(temp);
        break;

      case 6:
        Serial.println("CASE 1");
        temp = ',' +  String(passcode) + ',' + '1' + ',' + String(dt[0]) + ',' + String(dt[1]) + ',' + String(dt[2]) + ',' + String(dt[3]) + ',' + String(dt[4]) + ',' + String(dt[5]) + ',';
        Serial.println(temp);
        break;

      case 2:
        Serial.println("CASE 2");
        temp = ',' + String(passcode) + ",2,1,";
        Serial2.println(temp);
        break;

      case 3:
        Serial.println("CASE 3");
        temp = ',' + String(passcode) + ",2,0,";
        Serial2.println(temp);
        break;

      case 4:
        Serial.println("CASE 4");
        temp = ',' + String(passcode) + ",3,1,";
        Serial2.println(temp);
        break;

      case 5:
        Serial.println("CASE 5");
        temp = ',' + String(passcode) + ",3,0,";
        Serial2.println(temp);
        break;

    }
    stmdatatimer = millis();
  }
}
