/**
 * @file .ino
 *
 * Read encode.
 *
 * @author  S.Sarawut
 * @date    2223/05/31
 */
 
#define PIN_ENCODE_A 23
#define PIN_ENCODE_B 22

volatile int counter;

void readEncoder(){
  static int lastA = 0;
  int currentA = digitalRead(PIN_ENCODE_A);
  int currentB = digitalRead(PIN_ENCODE_B);
  
  if ((lastA == LOW) && (currentA == HIGH)) {
    if (currentB == LOW) counter++; else counter--;
  }
  
  lastA = currentA;
}

void setup() {
  pinMode (PIN_ENCODE_A, INPUT);
  pinMode (PIN_ENCODE_B, INPUT); 
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODE_A), readEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODE_B), readEncoder, CHANGE);
  
  Serial.begin (115200);
  delay(10);
}

void loop() {
  double convertCounter2length = counter / 200;
  
  Serial.println(" - Distance : " + String(convertCounter2length));
}
