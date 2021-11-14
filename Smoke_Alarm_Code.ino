// www.asyoni.com

// Kode Smoke Detector

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int buzzerPin = 8;
int smokePin = A0;
int sensorThres = 100; // Silahkan disesuaikan 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(smokePin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  
  int analogSensor = analogRead(smokePin);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  lcd.print("  Smoke Alarm   ");
  if (analogSensor > sensorThres)
  {
    lcd.setCursor(0, 2);
    lcd.print(" Smoke Detected ");
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    lcd.setCursor(0, 2);
    lcd.print(".....Normal.....");
    digitalWrite(buzzerPin, LOW);
  }
  
}
