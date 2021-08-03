#define SDA_PORT PORTD
#define SDA_PIN 14
#define SCL_PORT PORTD
#define SCL_PIN 32
#include <SlowSoftI2CMaster.h>

SlowSoftI2CMaster si = SlowSoftI2CMaster(SDA_PIN, SCL_PIN, false);

 
void setup() {
    Serial.begin(115200);
    Serial.println("heart rate sensor:");
    if (!si.i2c_init()) // initialize I2C module
            Serial.println("I2C init failed");
}
void loop() {
    si.i2c_start((0xA0 >> 1)|I2C_READ); // read
    byte val1 = si.i2c_read(true); // read one byte and send NAK afterwards
    si.i2c_stop(); //stop communication
    Serial.println(val1, DEC);
    delay(500);
}
