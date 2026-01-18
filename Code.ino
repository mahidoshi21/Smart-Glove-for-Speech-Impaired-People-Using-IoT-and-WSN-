
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int THRESHOLD_S1 = 880;
const int THRESHOLD_S2 = 720;
const int THRESHOLD_S3 = 730;
const int THRESHOLD_S4 = 750;
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SIGN LANGUAGE");
  pinMode(13, OUTPUT);
}
void loop() {
  int s1 = analogRead(A0);
  int s2 = analogRead(A1);
  int s3 = analogRead(A2);
  int s4 = analogRead(A3);
  Serial.print("S1: "); Serial.println(s1);
  Serial.print("S2: "); Serial.println(s2);
  Serial.print("S3: "); Serial.println(s3);
  Serial.print("S4: "); Serial.println(s4);
  if (s1 < THRESHOLD_S1) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("DRINK WATER");
    Serial.println("DRINK WATER");
  } 
  else if (s2 < THRESHOLD_S2) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("WASHROOM");
    Serial.println("WASHROOM");
  } 
  else if (s3 < THRESHOLD_S3) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("FOOD");
    Serial.println("FOOD");
  } 
  else if (s4 < THRESHOLD_S4) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("HELP");
    Serial.println("HELP");
  } 
  else {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("NOTHING");
  }
  delay(500);
}  
 
 


 
