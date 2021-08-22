const int transistor = 2;

void setup()
{
  pinMode (transistor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite (transistor, HIGH);
  Serial.println("ON");
  delay(1000);
  digitalWrite (transistor, LOW);
  Serial.println("OFF");
  delay(1000);
}
