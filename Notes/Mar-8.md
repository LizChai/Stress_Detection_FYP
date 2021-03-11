# Mar 8 2021 - Week 2 Meeting

## Progress Update

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

## Meeting with Yan

* Mind-map the options I have
* Come up with decision by next week
* Order components
  * Hardware
    * Smart watch (accelerometer, HR, sleep) + phone accelerometer
    * Build own smart watch
      * 'HD' will be getting hardware to work with generic ML algo
    * Buy smart watch ($$$$$)
    * Laboratory settings; ECGs, lots of wires everywhere
    * No hardware at all; just use online datasets
      * 'HD' will be innovative/cool ML algorithm
  * Software
    * From hardware
    * Use online datasets
  * Algo
    * Depends on hardware
      * Most likely ML algo, like SVM, decision trees
  * Data collection
    * Daily life settings: Surveys
      * Self-assessment of stress
      * Activity being performed (context data)
      * Phone screen input pressure
    * Frequency of surveying