long duration, cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  digitalWrite(12, LOW);
  delayMicroseconds(5);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  duration = pulseIn(11, HIGH);
  cm = (duration / 2) / 29.1;
  if (cm <= 10){
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    tone(3, 2000);
  }else{
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    noTone(3);
  }
  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.");
  delay(250);
}
