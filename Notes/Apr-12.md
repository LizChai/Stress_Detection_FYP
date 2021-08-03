# Apr 12 2021 - Week 6 Meeting

## Progress Update

* Connected to hardware via UART to get readings from GSR
  * Got readings from the GSR
  * Tried to live record data, however was unable to display it
    * Just recorded data and plotted afterwards
    * Wet fingers = 0
    * Stress =  Lower value
    * No Stress = around 512
  * Outputs an analogue reading between 0-1023 for 10-bit ADC
* Learnt about I2C and how to set it up on the microcontroller
  * HR Monitor works on Arduino, using template code
  * Doesn't current work on ESP32 (bus busy - not initialising comms properly)
* Machine learning techniques
  * SVM
  * Decision trees
  * kNN
  * Why: all three are used commonly in literature for stress detection, with high accuracy

## To do

* Hardware
  * Look at getting HR sensor working (I2C)
  * Look at wifi module
* Data
  * Plot data from GSR (in real-time)?
  * Start creating and implementing ML architecture

* How do the sensors actually work
* What do the numbers mean (i.e. linking to other people's work, validation (wet fingers, stress, etc)