const int outR = 9;
const int outG = 11;
const int outB = 10;
 
void setup() {
  Serial.begin(9600); 
 
  analogWrite(outR, 0);
  analogWrite(outG, 0);
  analogWrite(outB, 0);
}
 
void loop() {  
  
  if (Serial.available() == 3) {
    analogWrite(outR, Serial.read());
    analogWrite(outG, Serial.read());
    analogWrite(outB, Serial.read());
  }
}
