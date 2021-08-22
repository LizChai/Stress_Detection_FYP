# Aug 10 2021 - Week 3 Development Notes

## Progress

* Fixing HR filtering and data sampling in software
  * Includes DC Removal by approximate running average value
    * Works like windowed average, but each new value that is added only influences the mean by a percentage (bias towards newest value)
    * Bit shift x << 15 which multiplies by 32768
    * Use fixed point maths to calculate deviation of new value from previously stored value of current running average
    * Then divide deviation by 16 (x >> 4)
    * Add this deviation back to stored value
    * This means each new value can affect the mean by roughly one sixteenth (6.25% influence on current mean)
    * Bit shift current running average >> 15
  * Includes Low Pass Filter by FIR (with set coefficients)
  * Then finds a positive zero crossing (rising edge), which is a heart beat

## To do

* Potentially try fix current library's filtering/data sampling
* or try other libraries
* or implement own HR filtering/data sampling

* Enable Wifi
  * Source a LiPo
* Integrate sensor readings with machine learning script
* Record data
  * Me when demonstrating vs resting - record times
  * Write up experimental procedure
* Train other machine learning models
* Make the numbers mean something!!!
* Fabricate container for sensors, microcontroller and LiPo
* Start Final Assessments
