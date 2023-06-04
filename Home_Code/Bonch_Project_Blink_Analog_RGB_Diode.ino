long cm;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(9, i);
    analogWrite(10, i);
    delay(2);
  }
  delay(1000);
  for (int i = 255; i >= 0; i--) {
    analogWrite(9, i);
    analogWrite(10, i);
    delay(2);
  }
  delay(1000);
  for (int i = 0; i <= 255; i++) {
    analogWrite(10, i);
    analogWrite(11, i);
    delay(2);
  }
  delay(1000);
  for (int i = 255; i >= 0; i--) {
    analogWrite(10, i);
    analogWrite(11, i);
    delay(2);
  }
  delay(1000);
  for (int i = 0; i <= 255; i++) {
    analogWrite(11, i);
    analogWrite(9, i);
  }
  delay(1000);
  for (int i = 255; i >= 0; i--) {
    analogWrite(11, i);
    analogWrite(9, i);
  }
  delay(1000);
}
