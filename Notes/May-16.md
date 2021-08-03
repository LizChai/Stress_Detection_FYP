# May 16 2021 - Progress Update

## Progress Update

* Hardware
  * Use oscilloscope to validate readings from GSR sensor
  * Back calculated GSR Resistance from (theoretical) analogue reading

* Data
  * Implemented code for preprocessing and feature extraction
  * Found peak GSR signal and used max amplitude and average GSR as features
  * Tried machine learning on kNN
    * Uniform weight resulted in 7/9 (tested on training data)
    * Distance weight resulted in 9/9 (tested on training data)
    * Definitely need more data

## To do

* Hardware
  * Look at wifi module
  * Potentially try out different HR sensor

* Data
  * Run against LDA, see if kNN performs better
  * Consider penalisation (LOO, validating on other data), how well a model works/make sure it doesn't overfit despite more parameters
    * Is it a better model?
    * LOO: is it another subject, unseen data
  * Try moving window a label, instead of whole time period
  * Create other ML models
  * Create spreadsheet + survey to record stress
  * Record more data
* Progress Report and Design Specification
  * Write stuff that goes in the Final Report
