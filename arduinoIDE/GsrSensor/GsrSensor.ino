const int GSR=A4;
const int NUM_SAMPLES = 32;
int sensorValue=0;
int gsr_average=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  long sum=0;
  for(int i=0;i<NUM_SAMPLES;i++) //Average the measurements to remove the glitch
  {
  sensorValue=analogRead(GSR);
  sum += sensorValue;
  //delay(10);
  }
  gsr_average = sum/NUM_SAMPLES;
  Serial.println(gsr_average);
  delay(1000);
}
