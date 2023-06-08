#include <Morse.h>
#include <iarduino_OLED.h> 
iarduino_OLED myOLED(0x3C);

Morse morse(8, 24, 1);

extern uint8_t MediumFont[]; 

float duration, cm;
int dr;

void setup() {
  myOLED.begin();                                        
  myOLED.setFont(MediumFont);
  Serial.begin(9600);
  pinMode(12, OUTPUT);                    // Echolot connection OUTPUT
  pinMode(11, INPUT);                     // Echolot connection INPUT
  pinMode(6, OUTPUT);                     // LED Green connection OUTPUT
  pinMode(7, OUTPUT);                     // LED Red connection OUTPUT
  pinMode(3, OUTPUT);                     // Piezo Speaker connection OUTPUT
  pinMode(8, OUTPUT);                     // Laser module S-6 connection OUTPUT
}

void loop() {
  digitalWrite(12, LOW);
  delayMicroseconds(5);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  duration = pulseIn(11, HIGH);
  cm = (duration / 2) / 29.1;
  Serial.println(round(cm));
  myOLED.setCursor(0,39);
  myOLED.print("Dist: ");
  myOLED.print(cm);
  if (cm <= 10){
    digitalWrite(7, HIGH);
    analogWrite(6, LOW);
    dr = analogRead(A0) * 100;
    tone(3, analogRead(A0));
  }else{
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    noTone(3);
  }
}
