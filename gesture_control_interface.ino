#include <LCD-I2C.h>
#include <Wire.h>
#include <Servo.h>  

LCD_I2C lcd(0x27, 16, 2); 
int ledPins[] = {8, 9, 10, 11, 12}; 
char incomingData[16]; // Buffer for serial input
int lastFingerStates[5] = {0, 0, 0, 0, 0}; 
int lastFingersUp = -1; 
int lastFingersDown = -1;
Servo myServo;  

void setup() {
  Serial.begin(9600);
  Wire.begin();   
  lcd.begin(&Wire);   
  lcd.display();
  lcd.backlight();
  lcd.clear();
  delay(200);        

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); 
  }

  lcd.setCursor(0, 0);
  lcd.print("Waiting for data");

  myServo.attach(13);  
}

void loop() {
  if (Serial.available() > 0) {
    int len = Serial.readBytesUntil('\n', incomingData, sizeof(incomingData) - 1);
    incomingData[len] = '\0'; 

    int fingersUp = 0;
    int fingersState[5];

    for (int i = 0; i < 5; i++) {
      if (incomingData[i * 2] == '1') { 
        fingersState[i] = 1;
        fingersUp++;
      } else {
        fingersState[i] = 0;
      }
    }

    int fingersDown = 5 - fingersUp;

    for (int i = 0; i < 5; i++) {
      if (fingersState[i] != lastFingerStates[i]) {
        digitalWrite(ledPins[i], fingersState[i] ? HIGH : LOW);
        lastFingerStates[i] = fingersState[i];
      }
    }

    if (fingersUp != lastFingersUp || fingersDown != lastFingersDown) {
      lcd.setCursor(0, 0);
      lcd.print("Fingers up: ");
      lcd.print(fingersUp);
      lcd.print("   "); 
      lcd.setCursor(0, 1);
      lcd.print("Fingers down: ");
      lcd.print(fingersDown);
      lcd.print("   ");

      int servoAngle = map(fingersUp, 0, 5, 0, 180);  
      myServo.write(servoAngle); 

      lastFingersUp = fingersUp;
      lastFingersDown = fingersDown;
    }
  }
}
