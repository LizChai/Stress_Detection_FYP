// Define WiFi Library and network settings
bool wifi_status = true;
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "TP-LINK_9E63";
const char* password = "97475811";
const char* id = "ESP32Client";
const char* topic = "data_reading";

IPAddress broker(192,168,1,125);
WiFiClient espClient;
PubSubClient client(espClient); // Setup MQTT Client

// Define Heart Rate Sensor Libraries and Variables
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
MAX30105 particleSensor;
const byte HR_RATE_SIZE = 8; //Increase this for more averaging. 4 is good.
byte hr[HR_RATE_SIZE]; //Array of heart rates
byte hrSpot = 0;
long hrLastBeat = 0; //Time at which the last beat occurred
float hrBeatsPerMinute;
int hrBeatAvg;

// Define GSR Sensor Variables
const int GSR=A4;
const int GSR_RATE_SIZE = 32;
int gsr[GSR_RATE_SIZE];
byte gsrSpot = 0;
int gsrAvg;

int ticks = 0;

// Define battery management
#define VBATPIN 35

// Connect to WiFi function
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(id)) {
      client.subscribe(topic);
      Serial.println("connected");
      Serial.print("Publishing to: ");
      Serial.println(topic);
      Serial.println('\n');

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup(){
  Serial.begin(115200);
  
  Serial.println("Initializing...");

  if (wifi_status){
    setup_wifi();
    client.setServer(broker, 1883);
  }
  
  analogSetWidth(10); // Set ADC Width

  // Initialize HR sensor
  byte ledBrightness = 0xFF; //Options: 0=Off to 255=50mA
  byte sampleAverage = 8; //Options: 1, 2, 4, 8, 16, 32
  byte ledMode = 1; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
  int sampleRate = 100; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
  int pulseWidth = 411; //Options: 69, 118, 215, 411
  int adcRange = 4096; //Options: 2048, 4096, 8192, 16384
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30102 was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");

  particleSensor.setup(); //Configure sensor with settings

}

void loop(){
  ticks++;

  // HR Readings
  long irValue = particleSensor.getIR();
  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - hrLastBeat;
    hrLastBeat = millis();
    hrBeatsPerMinute = 60 / (delta / 1000.0);

    if (hrBeatsPerMinute < 255 && hrBeatsPerMinute > 40)
    {
      hr[hrSpot++] = (byte)hrBeatsPerMinute; //Store this reading in the array
      hrSpot %= HR_RATE_SIZE; //Wrap variable

      //Take average of readings
      hrBeatAvg = 0;
      for (byte x = 0 ; x < HR_RATE_SIZE ; x++)
        hrBeatAvg += hr[x];
      hrBeatAvg /= HR_RATE_SIZE;
    }
  }
  if (irValue < 50000) Serial.println(" No finger");

  // GSR Readings
  int gsrVal = analogRead(GSR);
  gsr[gsrSpot++] = gsrVal;
  gsrSpot %= GSR_RATE_SIZE;
  
  //Take average of readings
  gsrAvg = 0;
  for (int y = 0 ; y < GSR_RATE_SIZE ; y++)
    gsrAvg += gsr[y];
  gsrAvg /= GSR_RATE_SIZE;

  if (wifi_status){
      if (!client.connected()) {
        reconnect();
      }
      client.loop();
  }

  // Battery readings
  float vbat = analogRead(VBATPIN);
  vbat = vbat*2*3.3*1.1/1024*100;     // value is divided by 2, then scale to voltage (3.3V*1.1/1024), and multiply by 100 to keep precision
  
  // Print readings
  if (ticks%50==0){ // 50 ticks = 1s
    String results = String("BPM=" + String(hrBeatAvg) + ", GSR=" + String(gsrAvg) + ", BATT=" + String(vbat));
    Serial.println(results);
    
//    Serial.print("BPM=");
//    Serial.print(hrBeatsPerMinute);
//    Serial.print("BPM=");
//    Serial.print(hrBeatAvg);
//    Serial.print(", GSR=");
//    Serial.println(gsrAvg);


    if (wifi_status){  
      
      client.publish(topic, results.c_str());
    }
  }
}
