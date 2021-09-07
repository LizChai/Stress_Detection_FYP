# Aug 23 2021 - Week 5 Weekly Meeting

## Progress Update

* Ordered a LiPo
* Wrote code to record and send data over WiFi via MQTT
  * Installed MQTT broker; Eclipse Mosquitto
  * Installed PubSubClient Arduino library
  * Installed MQTT library for python
  * <img src=".\Pics\wireless_setup.png" alt="image" width="500"/>
* Wrote code to live predict stress state using pre-trained model and filtering
  * Integrated sensor readings with machine learning script for prediction
  * <img src=".\Pics\live_prediction.png" alt="image" width="200"/>
* Continued data collection (HR + GSR)
* Wrote up experimental procedure
  1. Flash ESP32 with code to record data and send info over MQTT
  1. Put watch on, ensure there are HR and GSR readings
  1. Set up MQTT Broker
  1. Run python code to receive info from broker
  1. Update python code to correspond to the desired recording length
  1. Run python code to start recording
      * Script should record data automatically
      * Data is automatically written to file
  1. Every 5-15 minutes, or if a new task is started
      * Jot down time start/end and stress felt from 1-10
      * 5 being the boundary between not stressed and stressed
  1. After the recording is finished, open the recorded data csv and enter in the stress levels
      * This will be used to train the model
  * Q: Was there anything in particular you wanted to see/where looking for?
* Brainstored FYP project name
  * Ideas
    * Low-cost IoT Wearable for Stress Detection
    * Low-cost Wearable IoT Device for Stress Detection
  * Q: Thoughts?
* Added a switch into circuit to turn on//off microcontroller and sensors
  * <img src=".\Pics\final_circuit_5.jpg" alt="image" width="200"/>
* Integrated HR data into model
  * Retrained with training data
  * ~85% accuracy on test data (k-nearest neighbours)
  * <img src=".\Pics\training_acc_1.png" alt="image" width="400"/>
* Fabricated container for sensors, microcontroller and LiPo
  * Q: Any policy on going into uni to pick them up?
  * <img src=".\Pics\case.png" alt="image" width="200"/> <img src=".\Pics\lid.png" alt="image" width="200"/>

* Q: Are you happy with my project thus far, and do you think it is enough?
  * I.e. Should I keep adding stuff, making ML better, extra functionality, outputs/feedback?
  * Or just start working on final assessments?

## Todo

* Record more data
  * Do CV
* Live plotting / red-green indicator / graphical representation
  * What are you predicting on/for
    * Relationship between GSR + HR and stress
    * How do you know this is correct?
      * Test on someone else
      * Accuracy
      * Figure out the model: decision boundary
        * What specific values HR/GSR are being used in model; weights/decision boundaries
* Train other machine learning models
  * Decision Tree, SVM
* Update Project Journal
* Start Final Assessments - Presentation, video, report, poster, (SPARK Night, Self-Assessed Rubric)
  * Brainstorm selling points of FYP
    * Incorporates aspects of whole ECSE degree: electronics/HW (microcontrollers/sensors), SW, design, data (collection, signal processing, machine learning), telecommunication, power
    * Novel, low-cost, wearable
    * Stress detection
    * Related to breakthrough technologies required to achieve SDGs by 2030; [Global Health](https://50breakthroughs.org/37/details/bt/)

## Report - Wed 23rd Oct Week 12

* Literature Review
  * Q: Do I re-include my literature review from the initial Requirements Analysis, or just the extra research I did?
* System Overview
  * Hardware, software, data
  * Schematics, diagrams, flow charts
* Detailed Discussion (of system) + methodoly
  * Reasoning for adopting particular methodolgy
  * Difficulties encountered
    * ESP32 I2C timeout
    * Hardware robustness
      * GSR Sensor wire snapped twice
      * HR Sensor glass cracked
    * Objectively labelling 'stress' data
  * Q: What else do I include here?
* Experimental results
  * Comparison of mi band vs heart rate sensor?
  * Prediction results for each ML model for live data from me + housemate?
  * Q: What else do I include here?
* Conclusion
  * Address requirements + design + proposal met
  * Incorporates aspects of whole ECSE degree: electronics/HW (microcontrollers/sensors), SW, design, data (collection, signal processing, machine learning), telecommunication, power
* Future Work
* Q: When do you want me to complete a draft by for proof reading? Week 10

## Video - Wed 23rd Oct Week 12

* Max 15 minutes
* Executive Summary/Elevator pitch (2-3 minutes)
  * Most important aspects of the project (aims, final outcomes)
    * Context and scope of project, outline approaches, give most important findings, state main outcomes and conclusions
  * Requirements + design met
* Technical details on hardware
  * Videos/pictures of demonstration of prototypes (breadboard, veroboard) and final design
* Details on software
  * Interfacing with sensors
    * Libraries, code workflow
  * Signal processing
  * Communication
    * WiFi, MQTT
* Details on machine learning
  * Data processing + filtering
  * Models used in training and prediction
  * Accuracy results
  * Screen capture of live stress prediction
* Conclusion
  * Future studies/implementations
Presentation
* Hardware (why, what)
  * Portability, low-cost, accessible
* Software
* Data collection + processing (how)
  * Tested on other people
  * Why this model/why data
* Experimentation
  * Stress vs other emotions
  * Tested on other people
  * Why GSR and HR
* Q: What other questions could they ask?

## Poster - Wed 13th Oct Week 11

* Sections:
  * Aim/Big picture (2-3 sentences)
    * Stress detection, health monitoring
    * Novel, low-cost, wearable
  * Hardware/electronics
    * Annotated pictures/diagrams
  * Software/signal processing/wireless comms
    * FlowChart/layout + description
  * Data collection+training+prediction
    * Description of methods, i.e. how data was collected, how models were trained and then how predictions made
  * Result
    * Live prediction on incoming HR and GSR data via watch
    * Future study is using this as feedback to recognise stressors, increasing productivity and reducing stress in long-term
* Q: Is this layout acceptable?
* Q: Is it just a summary of each section (i.e. breakdown of final outcome)? Or is any scientificacademic in particular?
  * i.e. Aim, Background, Problem, Process, Methods, Result, Conclusion, Future Study
* Q: When do you want me to complete a draft by for proofing? Week 9?
