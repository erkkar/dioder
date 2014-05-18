const int outR = 9;
const int outG = 11;
const int outB = 10;

unsigned long period = 0;
byte r, g, b;
byte strobe = 0;
 
void setup() {
  Serial.begin(9600); 
  r = 0;
  g = 0;
  b = 0;
  strobe = 0;
}
 
void loop() {    
  if (Serial.available() >= 4) {
    r = Serial.read();
    g = Serial.read();
    b = Serial.read();
    strobe = Serial.read();
  }
  setColor(r, g, b);
  // Strobe
  if (strobe > 0) {
    period = float(strobe) / 255 * 1000;
    delay(period / 2);
    black();
    delay(period / 2);
  }
}

void setColor(byte _r, byte _g, byte _b) {
  analogWrite(outR, _r);
  analogWrite(outG, _g);
  analogWrite(outB, _b);
}

void black() {
  setColor(0, 0, 0);
}
