# Apr 19 2021 - Week 7 Meeting

## Progress Update

* Connected to hardware via UART to get readings from GSR
  * Got readings from the GSR
  * Tried to live record data, however was unable to display it
    * Just recorded data and plotted afterwards
    * Wet fingers = 0
    * Stress =  Lower value
    * No Stress = around 512
  * Outputs an analogue reading between 0-1023 for 10-bit ADC
  * Did PSS and Stroop test
    * PSS: 24
    * Stroop test
    * Both dropped my GSR reading a bit
* Got I2C kind of working on ESP32
  * HR Monitor works on Arduino, using template code
  * Sends some rounds of data
  * Fix was that it needed at least 500ms delay
  * Got it working with ESP32 for a few tries, then an slave holds clock low after the 9th bit (after ACK bit) as it is doing something (i.e. preparing data) and never releases it

## To do

* Hardware
  * Look at wifi module
* Data
  * Plot data from GSR (in real-time)?
  * Start creating and implementing ML architecture

* How do the sensors actually work
* What do the numbers mean (i.e. linking to other people's work, validation (wet fingers, stress, etc))
  * Do a control + happy + stress test to record data
  * Then apply to everyday recorded data
* Machine Learning
  * Stress features/metrics in GSR
  * Sampling rates