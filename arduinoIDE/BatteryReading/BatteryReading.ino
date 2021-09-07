#define VBATPIN 35
float vbat = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogSetWidth(10);
}

void loop() {
  vbat = analogRead(VBATPIN);
  vbat = vbat*2*3.3/1024;     // value is divided by 2, so multiply back, then scale to voltage (3.3V/1024)
  Serial.print("Battery voltage: ");
  Serial.println(vbat);
  delay(1000);
}
