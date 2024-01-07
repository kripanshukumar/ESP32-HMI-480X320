void intializeServo() {
  myservo.attach(servoPin);
  myservo.writeMicroseconds(rest);
}

void runServo() {
  servofeedback = analogRead(servofeedbackpin) / 4;
  if (menu != 3) {
    if (servostat == 1) {
      if (abs(servofeedback - upperThreshold) >= 2) {
        myservo.writeMicroseconds(rest + (velocity * dir)) ;
      }
    }
    else {
      if (abs(servofeedback - lowerThreshold) >= 2) {
        myservo.writeMicroseconds(rest - (velocity * dir));
      }
    }
  }
}

void stopServo() {
  Serial.println("Servo Stopped");
  myservo.writeMicroseconds(rest);
}

void riseServo() {
  Serial.println(servofeedback - upperThreshold);
  if (abs(servofeedback - upperThreshold) >= 2) {
    Serial.print("Servo Rising: ");
    Serial.println(rest + (velocity * dir));
    myservo.writeMicroseconds(rest + (velocity * dir)) ;
  }
}

void fallServo() {
  Serial.println(servofeedback - lowerThreshold);
  if (abs(servofeedback - lowerThreshold) >= 2) {
    Serial.print("Servo Falling: ");
    Serial.println(rest - (velocity * dir));
    myservo.writeMicroseconds(rest - (velocity * dir));
  }
}
