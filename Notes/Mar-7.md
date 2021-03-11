# Mar 7 2021 - Notes

## Notes

* More progress!
* Found out about different scenarios: daily life, lab, office and traffic situtations
* Found really cool and interesting applications
  * A lot of stuff has already been done in this area
* Idea: for monitoring acute stress in daily life > HR (PPG/ECG?) + EDA > ESP32 microcontroller > cloud > ML > result > displayed via application
* Can cut out cloud and use wifi locally to computer if too complicated
  * Or use sensors that go to straight into a computer
* Need for accelerometer?
  * Research says good to distinguish activities
  * Annoying as will probably need to be placed on hip/waist; pocket?
  * Use phone accelerometer?
* Devices already out there
  * Fitbit Sense smartwatch monitors (optical) HR, accelerometer, ST, Sp02 and EDA and does analysis ($299.95 USD)
  * Empatica E4 gathers PPG, accelerometer, EDA, ST data for researchers to do analysis ($1690 USD but academic discount)
  * Both have Cloud usage and user applications/dashboards
* Obviously would be easier in a clinical setting, but daily life use case is more interesting + useful
* How to collect 'actually stressed' data?
  * Periodic surveys during the day?
    * questionnaire, record type of activity and perceived stress
  * Create phone app? google forms?
    * Could use pressure sensors on phone screen to detect stress too
  * Ask about/record subject's activities? i.e. sitting, moving, more detailed?
    * Sleeping, laying down, sitting (studying, eating, drinking), light movement(walk/chores/work), medium(fast walk/bike), heavy(gym/running), eating, small screen usage, large screen usage, caffeinated drink consumption, smoking, alcohol consumption
  * Do I need to feedback and determine and relate what activity/factor cause stress?
    * Thing to do later potentially once/if I get things working

## Open Source datasets

* Transforming data, spectral analysis, PCA/LDA
* [Stress data for arachnophobia](https://physionet.org/content/ecg-spider-clip/1.0.0/)
  * Clinical/lab setting data
  * EDA, ECG, respiration; trigger (resting/stressful clip)
* [DriveDB: Stress data for driving/traffic](https://physionet.org/content/drivedb/1.0.0/)
  * Drive/traffic setting data
  * ECG, EMG, GST; stress ratings not available
* [Multilevel Monitoring of Activity and Sleep in Healthy People](https://physionet.org/content/mmash/1.0.0/)
  * RR, Sleep, questionnaire, saliva, categorised activities (sleeping, laying down, sitting (studying, eating, drinking), light movement(walk/chores/work), medium(fast walk/bike), heavy(gym/running), eating, small screen usage, large screen usage, caffeinated drink consumption, smoking, alcohol consumption), accelerometer
* [Non-EEG Dataset for Assessment of Neurological Status](https://physionet.org/content/noneeg/1.0.0/)
  * Laboratory setting data, timed stages of relaxation and stress (physical, emotional, cognitive)
  * EDA, ST, acceleration, HR and arterial O2 levels
* [WESAD (Wearable Stress and Affect Detection) Data Set](https://archive.ics.uci.edu/ml/datasets/WESAD+%28Wearable+Stress+and+Affect+Detection%29)
  * Lab setting data, for different stresses
  * BVP, ECG, EDA, EMG, respiration, ST, accelerometer (Empatica E4, RespiBAN)
  * Self-survey data
* [SWELL dataset](https://www.kaggle.com/qiriro/swell-heart-rate-variability-hrv)
  * Office work setting data
  * Stressors such as unexpected emails, pressure to complete work on time
  * Computer logging, facial expression, body posture, ECG for HRV, EDA
  * Task load, mental effort, emotion and perceived stress

## Electronics

1. PPG sensor:
    * [Grove PAH8001EI-2G DigiKey](https://www.digikey.com.au/product-detail/en/seeed-technology-co-ltd/101020082/1597-1463-ND/5487427) - $31.70
      * Wearable
    * [MAX30101 Core Elecronics](https://core-electronics.com.au/sparkfun-pulse-oximeter-and-heart-rate-sensor-max30101-max32664-qwiic.html)
      * Has in-built DSP
    * [MAX30100 Core Electronics](https://core-electronics.com.au/m5stack-mini-heart-rate-unit-pulse-oximeter-max30100.html)
      * Not wearable
    * [MAX30102 (MAXREFDES117# Mouser](https://au.mouser.com/ProductDetail/Maxim-Integrated/MAXREFDES117?qs=L5CenAjuTY7RgAB22JU8Sw%3D%3D)
    * [Generic HR Sensor Aus Electronics](https://www.auselectronicsdirect.com.au/heart-rate-pulse-sensor-module-for-arduino-project?gclid=CjwKCAiAkJKCBhAyEiwAKQBCkmBLZ_jjQmHdimJHdcw6lD6z9lMDoBQcsUFcQZ5Yq9hnMBF1zVrJphoCKC0QAvD_BwE)
    * [BH1790GLC Element14](https://au.element14.com/rohm/bh1790glc-evk-001/eval-brd-optical-pulse-monitor/dp/2748654?st=bh1790)
1. GSR sensor:
    * [Grove GSR DigiKey](https://www.digikey.com.au/product-detail/en/seeed-technology-co.,-ltd/101020052/1597-1295-ND/5488086) - $14.38
1. Microcontoller
    * [ESP32-S2-SAOLA-1R DigiKey](https://www.digikey.com.au/product-detail/en/espressif-systems/ESP32-S2-SAOLA-1R/1965-ESP32-S2-SAOLA-1R-ND/11613138) - $11.63
    * [M5Stack ESP32 Basic Core IoT Dev Kit DigiKey](https://www.digikey.com.au/product-detail/en/m5stack-technology-co-ltd/K001/2221-K001-ND/10492140) - $40.61
    * [M5Stack ESP32 Basic Core IoT Dev Kit Core Electronics](https://core-electronics.com.au/m5stack-esp32-basic-core-iot-development-kit.html) - $45.50
    * [Arduino Nano 33 IoT](https://www.digikey.com.au/product-detail/en/arduino/ABX00027/1050-ABX00027-ND/10239968) - $31.31
      * None of these are battery powered
1. Microcontroller with JST battery management
    * [ESP32 - Huzzah32 Feather DigiKey](https://www.digikey.com.au/product-detail/en/adafruit-industries-llc/3405/1528-2181-ND/7244967) - $28
1. LiPo Battery
    * [LiPo (Rechargeable, 1.1Ah) DigiKey](https://www.digikey.com/en/products/detail/tinycircuits/ASR00008/8680974) - $10

## Progress

1. Started reading articles for Literature Review
    * Found a few interesting articles with applications which I would like to try/use as a base/idea
      * i.e. Acute stress > HR monitor + skin galvanic data (+camera facial expressions) > ESP microcontroller > cloud > ML (SVM) > result > displayed via application/LED
      * Must consider exercise in algo and may also be able to detect overtraining in athletes
      * Thoughts:
        * Excited about IoT and edge computing with the stress detection algo
        * Stress detection algo seems okay to figure out/manage
          * Existing algos are quite basic, need to do more research in this area if its worth trying to make a more complicated/better one?
          * Or look to get a 'HD' elsewhere? i.e. application?
        * Can only use facial expression camera data if participant is in front of computer/sitting > student studying application or business office-worker application
        * Some people collected stress data from participants in a Hackathon, what are the ethics?
    * Read about types of stress and how they occur physiologically
1. Research Algorithm (this depends on what sensor data I collect) - found some good sources (i.e. surveys)
    * Decision Trees/SVM/PCA/classical ML for HR and skin galvanic sensors
    * CNNs for facial expression data
    * Train ensemble neural network using classical ML (sensor data) output and CNN (facial expressions) for higher accuracy?
1. Found Open Source dataset (if applicable)
    * Transforming data, spectral analysis, PCA/LDA
1. Reflect + figure out what I want to do in life, so I know where I can focus on the project; something along the lines of:
    * Medical application + Data + ML + IoT sensors/hardware
    * Edge or cloud computing

## To Do

1. Read more papers
    * Types of stress (i.e. acute)
    * How to test for and record stress data (i.e. stroop test)
    * Stuff already out there with a similar application (there are lots)
1. More researching Algorithms (this depends on what sensor data I collect)
1. Come up with a concrete idea by next week
    * Idea
    * Architecture, hardware, software
