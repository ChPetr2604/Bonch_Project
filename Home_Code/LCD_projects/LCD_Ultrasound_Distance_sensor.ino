#include <LiquidCrystal.h>
const int rs = 4, en = 5, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float duration, cm;

void setup() {
  Serial.begin(9600);
  lcd.begin(20, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hi, user)");
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  digitalWrite(9, LOW); 
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  duration = pulseIn(8, HIGH);
  cm = duration / 58;
  lcd.print(cm);
  Serial.println(cm);
  delay(1000);
  lcd.clear();
}
