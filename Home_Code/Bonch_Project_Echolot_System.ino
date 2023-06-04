bool signal;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, INPUT);
  tone(10, 36000);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  signal = digitalRead(11);
  Serial.println(signal);
  if (!signal){
    analogWrite(5, 50);
    digitalWrite(2, HIGH);
    digitalWrite(7, HIGH);
  }else{
    analogWrite(5, 0);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
  }
  delay(50);
}
