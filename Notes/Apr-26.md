# Apr 26 2021 - Week 8 Meeting
## Progress Update

* Got I2C kind of working on ESP32
  * HR Monitor works on Arduino, using template code
  * Sends some rounds of data
  * Fix was that it needed at least 500ms delay
  * Got it working with ESP32 for a few tries, then an slave holds clock low after the 9th bit (after ACK bit) as it is doing something (i.e. preparing data) and never releases it

## To do

* I2C - slave holding bus low
  * Try chuck in random STOP signals
  * Play with timing - Read documentation on ESP I2C setup/config
  * Try different GPIO Pins and wires, breadboard - Tried this
  * Try Arduino IDE
  * Talk to Jose
* Hardware
  * Look at wifi module
* Data
  * Plot data from GSR (in real-time)?
  * Start creating and implementing ML architecture

* **** MUST DO ****
* How do the sensors actually work
* What do the numbers mean (i.e. linking to other people's work, validation (wet fingers, stress, etc))
  * Do a control + happy + stress test to record data
  * Then apply to everyday recorded data
* Machine Learning
  * Stress features/metrics in GSR
  * Sampling rates
