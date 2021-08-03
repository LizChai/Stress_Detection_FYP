# Aug 03 2021 - Week 2 Development Notes

## GSR Sensor

* Unplugged and replugged all the wires
* Now works as expected

## HR Sensor (Grove/PAH)

* Address of 0x50
* Requires ~2.7kOhm pullup resistors
* Works on Arduino
  * Kinda works on ESP32 (timing issues, requires a powercycle every so often)
* Does not fully work on ESP32 as ESP32 implementation of Wire is different to Arduino
  * [ESP32 Wire](https://github.com/espressif/arduino-esp32/blob/master/libraries/Wire/src/Wire.cpp)
  * [Arduino Wire](https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/Wire/src/Wire.cpp)
* Summary of why I2C does not work properly
  * Timeout (Error 3), Oscilloscope shows SDA line goes low
    * Error 3: i2c SCL period exceeded maximum supported 13.1ms
    * Fatal; as slave stretches SCL line (to pause comms while sampling) longer than the ESP32 can handle (which is only ~13.1ms)
    * The supported 13.1ms is an ESP SCL STRETCHING LIMITATION due to HARDWARE
  * ESP sees clock line is busy (slave holds low for stretching) and aborts Wire command (current READ transaction is aborted)
  * However, slave is still recording data and tries to output a value (even though ESP32 master has aborted)
  * Slave tries to communicate value, as ESP32 master tries to begin a new transaction
  * Bus collision (Slave driving SDA, waiting for master to cycle SCL, however master waiting for SDA to clear)
  * Oscilloscope shows SCL goes low and device goes unavailable Device (Error 1) or bus is bussy (Error 5)
    * Error 1: i2c hardware error, interrupt not available
    * Error 5: Either previous transaction aborted, or Other MASTER device is using BUS. SDA and/or SCL is not HIGH.
  * Sensor then needs a power cycle
* Useful resources into why ESP I2C is buggy
  * [I2C Stability using Feather and sensor](https://github.com/espressif/arduino-esp32/issues/3701)
  * [Can't maintain I2C connections heart rate sensor](https://www.gitmemory.com/issue/espressif/arduino-esp32/2751/489630472)
  * [ESP32 I2c does not honour repeated start](https://github.com/espressif/arduino-esp32/issues/4729)
* Use OriginalHeartrateSensor.ino
  * For Arduino, comment out #defines and change Wire.begin() line
    * Does not require all the error checking; as does not time out on Arduino

## HR Sensor (MAX3010x)

* Address of 0x57
* Doesn't require pullups on SDA and SCL
* Both chips are 30102
  * Even though one of the chips are labelled 30100, its a 30102
  * Since is why MAX30100 libraries didn't work, when I tried on last Thursday
  * Needed to use a different MAX3010x library (SparkFun_MAX3010x_Sensor_Library)
* Chip with broken glass has low and inconsistent readings
* Chip labelled 30100 works decently, but very sensitive
  * Requires filtering and better sampling
  * [Filtering of MAX3010x](https://morf.lv/implementing-pulse-oximeter-using-max30100)
* Works on Arduino and ESP32
* Use MAX3010x.ino
  * But data filtering/sampling needs to be improved

## Useful I2C Scanner

* Used to check that both HR sensor types were correctly wired up

## Todo

* Grove HR
  * Use transistor to powercycle sensor OR
    * Play around with timings (clock freq, delays/sleeps, timeouts)
      * 2.5s delay, timeouts after a few readings (10-20s)
      * 5s delay, timeouts after 1-1.5 minutes
  * Make sure to ignore 0 or 1 readings
* Veroboard/make everything neat
  * Solder ESP32
  * Draw out wiring diagram (shorter tracks as possible for I2C circuit)
  * Plan out casing
* Wifi
* Record data
