# Mar 11 2021 - Progress Update and Notes

* [Miro Mindmap](https://miro.com/app/board/o9J_lP_cemU=/)

* Setup python environment
  * cd C:\Users\ieliz\Documents\2021\FYP\Stress_Detection_FYP
  * python -m venv fyp_dev

## Research Notes

* Found really good paper with code
  * Automatic Stress Detection in Working Environments from Smartphones’ Accelerometer Data: A First Step
  * Provided code generates a model for generic, personal and calibration data; trains and predicts
  * Still need to preprocess the data to a similar input format if I wanted to use the code
  * Seems straight forward to 'train a model', may be more difficult to collate and clean data input

## Progress

* Read about different scenarios: daily life, lab, office and traffic situations
  * Will probably focus on office/daily life settings
* Idea: for monitoring acute stress in daily life > HR (PPG/ECG?) + EDA > ESP32 microcontroller > cloud > ML > result > displayed via application
  * Can cut out cloud and use wifi locally to computer if too complicated
    * Or use sensors that go to straight into a computer
* Thought about collecting 'actually stressed' data
  * Periodic surveys during the day
    * Questionnaire, record type of activity and perceived stress
  * Create phone app? Google forms?
    * Could use pressure sensors on phone screen to detect stress too
  * Ask about/record subject's activities? i.e. sitting, moving, more detailed?
    * Sleeping, laying down, sitting (studying, eating, drinking), light movement(walk/chores/work), medium(fast walk/bike), heavy(gym/running), eating, small screen usage, large screen usage, caffeinated drink consumption, smoking, alcohol consumption
* Found more articles + surveys with really cool and interesting applications
* Found lots of potentially useful open source datasets (some used multiple times in different papers)
  * Mainly traffic, office or lab setting, nothing in the daily life setting
  * Notable datasets: [SWELL dataset](https://www.kaggle.com/qiriro/swell-heart-rate-variability-hrv) and [WESAD (Wearable Stress and Affect Detection) Data Set](https://archive.ics.uci.edu/ml/datasets/WESAD+%28Wearable+Stress+and+Affect+Detection%29) (office setting)
* Found paper that uses WESAD and SWELL that has CODE!!!
  * [The Effect of Person-Specific Biometrics in Improving Generic Stress Predictive Models](https://arxiv.org/abs/1910.01770)
  * Had a look at the code, ML seems pretty straight forward
  * They essentially transfer learn from a trained model on 'generic' data (i.e. all the subjects)
  * Hard part is recording, cleaning and inputting data
  * Train more on specific patient data > better accuracy; less data required
  * Could look to train on existing datasets and modify/retrain for my recorded data
* Went to Researching scholarly literature session
  * Was average; nothing I hadn't already found out for myself
* Ordered components
  * ESP microcontroller + LiPo battery + PPG + GSR sensor from DigiKey

## To Do

1. Try to write/reuse/run code for ML (i.e from papers with code and datasets)
1. More researching Algorithms
    * Look at papers with code that use HRV and EDA datasets
    * Seen examples of simple Random Forest
1. Write down concrete idea by next week (for Monday meeting)
    * Mindmap/Roadmap
      * i.e. Try make own smart-watch with hardware for data
      * If hardware doesn't work
        * Use pre-existing open source dataset and come up with new cool algo
        * Collect data other methods:
          * In laboratory setting (ECG)
          * Smart watch (Mi Band), Phone data
          * Pressure detection when filling out survey
1. Play with hardware when it arrives
    * Read datasheets
    * Plan pin mapping of sensors to microcontroller
1. Set up software environment/architecture for microcontroller
1. Set up software architecture/framework for data analysis
  
## Questions for Yan (for meeting)

1. Expectations for Assessment due in Week 4 (Risk Assessment, Requirements Analysis) (I will need to refresh myself on what is needed)
    * How dangerous are LiPos in a wearable (Risk Assessment)?
    * Ethics of collecting stress data from myself/friends
    * Guidance/tips
1. Is my Roadmap okay?
1. Lab access?
