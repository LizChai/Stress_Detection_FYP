# May 03 2021 - Week 9 Meeting

## Progress Update

* HR Monitor
  * Tried various different things
    * Tried Arduino IDE
      * Reports 0 HR until I place my finger in front of it - then it stops working
      * Same behaviour as before, where the SCL gets pulled low forever and does not recover
    * [Description of issue](https://www.gitmemory.com/issue/espressif/arduino-esp32/2751/489630472)
      * The "gross" timeout is telling you that the slave stretched SCL (paused communications while sampling) longer than the ESP32 can handle (approximately 13.1ms). It is a fatal error.
      * The cascade of errors is because the ESP32 aborted the READ transaction when it timed out. But the Sensor is still in read mode. It is trying to output the sensor value, but the ESP32 is trying to begin a new transaction. The bus is in use (Slave is driving SDA, waiting for the Master(ESP32) to cycle the SCL Clock. Except, the ESP32 is waiting for the Bus to Clear (SCL & SDA high).
      * Other forums [1](https://github.com/espressif/arduino-esp32/issues/834) [2](https://github.com/espressif/arduino-esp32/issues/2261)
    * [Logs] (C:\Users\ieliz\Documents\2021\FYP\Stress_Detection_FYP\arduinoIDE\debugging_020521_1.txt)
    * Tried fix to various ESP32 I2C Libraries by [stickbreaker](https://github.com/stickbreaker/arduino-esp32/tree/master/cores/esp32)
    * Tried physical pull up resistors (2.7k)
    * Tried [SlowSoftI2C Library](https://github.com/felias-fogg/SlowSoftI2CMaster) (alternative to Wire)

* ML
  * Refer to Machine learning notes

## To do

* I2C - slave holding bus low
  * Try chuck in random STOP signals
  * Play with timing - Read documentation on ESP I2C setup/config
  * Talk to Jose
* Hardware
  * Look at wifi module
* Data
  * Plot data from GSR (in real-time)?
  * Start creating and implementing ML architecture

* --- MUST DO ---
* What do the numbers mean (i.e. linking to other people's work, validation (wet fingers, stress, etc))
  * Do a control + happy + stress test to record data
  * Then apply to everyday recorded data
* Machine Learning
  * Stress features/metrics in GSR
  * Sampling rates
* Figure out what features to extract (i.e. amplitude)
* Give moving window a label from 1-10 based on how stressed
* Use that for Machine Learning - labels: training and testing

## Questions

* Expectations for Design Specification and Progress Report
  * None
* Write stuff that goes in the Final Report
* Submit Final Report
  * Markers only read Final report, and only if there are issues, they go back to see what happened
