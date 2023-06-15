#include <LiquidCrystal.h>
const int rs = 4, en = 5, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

uint32_t       i;
int            h, m, s;    

void setup() {
  Serial.begin(9600);
  lcd.begin(20, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hi, user)");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Work time: ");
  i=millis();
  Serial.println(i);
  i /= 1000;
  s = i % 60;
  m = i / 60 % 60;
  h = i / 60 / 60 % 24;
  if (h >= 10) {
    lcd.print(h);
  } else {
    lcd.print(0);
    lcd.print(h); 
  }
  lcd.print(':');
  if (m >= 10) {
    lcd.print(m);
  } else {
    lcd.print(0);
    lcd.print(m); 
  }
  lcd.print(":");
  if (s >= 10) {
    lcd.print(s);
  } else {
    lcd.print(0);
    lcd.print(s); 
  }
    //Serial.print(h);
    //Serial.print(":");
    //Serial.print(m);
    //Serial.print(":");
    //Serial.println(s);
}
