#include <Wire.h>
#define I2C_SDA 23
#define I2C_SCL 22

void setup() {
  Serial.begin(115200);
  Serial.println("\nHeart rate sensor:");
  Wire.begin(I2C_SDA, I2C_SCL);
  //Wire.begin();
  Wire.setClock(100000);
  Wire.setTimeOut(2000);

}

void loop() {
  uint8_t count = Wire.requestFrom(0x50, 1);     // request 1 bytes from slave device

  if (count == 1){
    unsigned char c = Wire.read();  // receive heart rate value (a byte)
    Serial.println(c, DEC);         // print heart rate value
  }
  
  else { //error
    int error = Wire.lastError();
    Serial.printf("Error %d\n", error);
    //Serial.printf("Request from sensor failed =%d(%s)\n",error, Wire.getErrorText(error));
    if (error == 3){      // BUS IS BUSY, WAIT 2.5s before sending more commands
      delay(2500);
    }
    else if (error == 1){ // SENSOR IS NOT RESPONDING, REQUIRES POWERCYCLE
      //delay(1000); 
    }
    Wire.begin(); // Begin here to allow sensor to reboot properly
  }
  
  delay(5000); //read data every x000ms
}
