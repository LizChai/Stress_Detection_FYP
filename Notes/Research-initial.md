# Initial research

## Research 04/03/21

* [Nonlinear Heart Rate Variability features for real-life stress detect](https://search.proquest.com/docview/915691046?accountid=12528&pq-origsite=primo)
  * Heart Rate Variability: non-invasive measure reflecting the variation over time of the period between consecutive heartbeats (RR intervals)
    * proven reliable marker of ANS activity
  * Stress is a risk for CVD; influences balance of ANS
    * stressors can include: cognitive (mental arithmetic), psychomotor (mirror tracing), challenges and physical, university exams
  * Poincare Plot: graphical rep of corr bw successive RR intervals
  * Approximate Entropy
  * Paper goes through technical details of HRV analysis (in Kubios, free software) for stress in university students (rest/stress)
  * Study suggests that nonlinear HRV analysis using short term ECG recording could be effective in automatically detecting IRL stress conditions

* [Multimodal behavioural analysis for non-invasive stress detection](https://www.sciencedirect.com/science/article/pii/S0957417412007816)
  * Measure acute stress in humans using technology (computer-machine interactions patterns and behaviours); touch intensity/duration, movement and acceleration affected
  * Study effects of stress on eight behavioural, physical and cognitive features
  * Non-invasive process of estimating stress
  * Objective to overcome some of the main drawbacks of communicating online (i.e. lack of contextual info: body language/gestures)

## Research 05/03/21

* [Smart Wristband-Based Stress Detection Framework for Older Adults with Cortisol as Stress Biomarker](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=9349773)
  * Stress detection model for older adults using system of sensors on watches
    * Uses EDA, BVP, IBI and ST from EDA, PPG and ST sensors
      * EDA: electrodermal activity
      * PPG: photoplethysmogram
      * BVP: blood volume pulse
      * ST: skin temperature
  * Stress reference is salivary cortisol
  * Small dataset of 40 adults
  * Data collected during TST (Trier Social Stress Test)
    * Stress in social setting
    * 27 features extracted from 4 methods to distinguish between stress and not stressed
  * Future research into consumer end device with voice capability so user can inquire about vitals and stress levels via smartphones or smart speakers

* [Allostatic load and biological anthropology](https://onlinelibrary.wiley.com/doi/epdf/10.1002/ajpa.23146)
  * Allostatic load: wear and tear after prolonged allostatic activity (i.e. stress responses)
    * results in deterioration of several key body systems including CVS, immune, neuroendocrine and metabolic system
  * Stress response physiology:
  ![Stress](https://onlinelibrary.wiley.com/reader/content/168c72daf49/10.1002/ajpa.23146/format/pdf/OEBPS/pages/bg3.png)
    * Stress varies in frequency, intensity and duration: predators, infection, chemicals (toxins, caffeine), environmental factors (temperature), psychosocial
    * Psychosocial: social and psychological variations like social interations, personal relationships, politics, memories, workplace expectations, cultural norms, conceived by never realised threats
    * Perceived stress activate hypothalamus (coordinates multiple synergistic neuroendocrine axes to limit stressor-related damage)
    * Hypothalamic-pituitary-adrenal (HPA) axis' first response is to release corticotropin-releasing hormone (CRH) from hypothamalus into anterior pituitary, which stimulates release of adrenocorticotropin-releasing hormone (ACTH) from anterior pituitary into systemic circulation
    * ACTH induces release of mineralcorticoids and glucocorticoids into system circulation from adrenal cortices.
      * Mineralcorticoids (aldosterone and deoxycorticosterone) regulate blood plasma volume and electrolyte balance > modulate blood pressure; promote release of liver glycogen deposits and decrease numbers of circulating eosinophil numbers
      * Glucocorticoids (cortisol and cortisone) increase gluconeogenesis, lipolysis and BP > prepare body for physical exertion
    * HPA axis and hypothalamus activate sympathetic-adrenal-medullary (SAM) axis, which releases catecholamines (epinephrine and norepinephrine) from adrenal medulla > promote increased blood pressure and heart rate, release of free fatty acids and decreased blood flow to currently nonessential systems (skins, gastrointestinal, kidneys), readying organism for resolution of stressor
      * Catecholamines also enhance emotional memory formation through action on amygdala > learning extreme threats and allowing future anticipatory allostatic repsonses to similar stressors
    * Posterior pituitary, thyroid, somatotropic axes are also activated during allostatic stress response
    * Testoterone, oxytocian, luteinizing hormone (LH) and prolactin vary in their responses
      * Acute stress may increase production, while chronic stress reduces testosterone and inhibits reproduction
  * Ideally successful allostatic responses control or eliminate current stressors and physiological activity returns to baseline
    * Overtime damage acculumates, producing allostatic load, dysregulation > CVD and metabolic diseases, tertiary outcomes > CVD, hypertension, and diabetes
  ![Outcomes](https://onlinelibrary.wiley.com/reader/content/168c72daf49/10.1002/ajpa.23146/format/pdf/OEBPS/pages/bg5.png)

* [Stressed or stressed out: What is the difference?](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC1197275/)
  * Good article on allostatic stress

* [Machine learning for internet of things data analysis: a survey](https://www.sciencedirect.com/science/article/pii/S235286481730247X#bib44)
  * Survey on IoT + ML applications
  
* [Machine Learning and IoT for prediction and detection of stress](https://ieeexplore.ieee.org/document/8000018)
  * Acute stress > HR monitor > ESP microcontroller > cloud > ML (SVM) > result > displayed via application

* [Stress Detection using Deep Learning and IoT](https://www.ijresm.com/Vol.2_2019/Vol2_Iss8_August19/IJRESM_V2_I8_14.pdf)
  * These people cite the above paper just detect stress via CNNs for facial expression; no reported accuracy though
  
## Research 07/03/21

* [A non-contact health monitoring model based on the Internet of things](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=6234771)
  * Non-contact health monitoring: facial expressions, posture and voice changes
  * IoT: connect tech to tech, tech to people and tech and people to the internet
  * Facial expression recognition: pre-processing > Gabor wavelet for position of eyes, mouth and face > extract features > expression feature vector > map vector to PAD classification space > classify expresion
    * PAD: Pleasure-Arousal-Dominance 3D emotion model
      * more info on PAD

* [Prediction and Detection of Stress using IoT and Supervised Learning Approach](http://sersc.org/journals/index.php/IJAST/article/view/20409/10343)
  * Paper by final year student and supervisor
  * Stress detection
    * Heart rate monitor + NodeMCU (ESP8266) > Cloud server > graph/ML Algo > prediction > generate report

* [Continuous Stress Detection Using Wearable Sensors in Real Life: Algorithmic Programming Contest Case Study](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6515276/)
  * Data from algorithmic programming summer camp via smart wrist-worn wearable devices
    * 9 days from 21 participants; lectures, contents, free time
  * Early stress detection research performed in laboratory settings
  * Current research in conducted in real life settings
    * [Comparison table](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6515276/table/sensors-19-01849-t001/?report=objectonly)
  * Types of monitoring/sensors
    * EDA: electrodermal activity
    * HR: heart activity
    * accelerometer
    * EDA and HR combo has best performance, proposed accuracy of above 95%
    * EEG: electroencephalogram; accuracy of 89%
  * Types of ML algos
    * LDA: Linear Discriminant Analysis
    * SVM: Support Vector Machine
    * kNN: k-Nearest Neighbours
    * Fuzzy logic
  * Classes of stress: relaxed, stressed (can also have neutral)
  * Office settings easily monitored by EDA, ECG and accelerometer
  * Traffic settings has DriveDB database (ECG, EDA, EMG and respiratory sensor) from 24 drivers in Boston
  * University campus settings most similar to unrestricted daily life; harder to conrol - probably worse classification performance
    * Most accurate to daily life and routine
    * Can employ activity recognition to increase knowledge context and improve recognition of stress
  * Devices must be correctly installed, charged
    * Obtrusive devices may lead to extra stress in participants
    * Risk of: limited battery, incorrect placement, loosely worn, unconstrained movement of subjects, issues with ground truth collection
    * Noise > DSP (filters i.e. Kalman, Butterworth LPF, median, Wiener and wavelet decomposition, interpolation, removing artifacts like LMS, regression, PCA)
  * Increase stress by multimodal measurement
    * Difficulty of synchronisation via timestamps
  * Surveys to collect ground truth data:
    * Perceived Stress Scale
    * Stress Self-Rating Scale
    * NASA-TLX
    * The State-Trait Anxiety Invetory
    * Self Assessment Manikin
    * Negative Affect Schedule
    * taken periodically throughout the day; could be automated via phone app/pop-up surveys
  * Their study:
    * System:
      * PPG: plethysmography (volumetric changes of organs are measure from the skin illuminated by light emitted from a pulse oximeter PPG)
        * PPG sensors used to measure heart acitivity by measuring blood flow during heart's pumping actions
        * Heart activity signal composed of different peaks and valleys, use RR interval (IBI: interbeat interval)
      * EDA aka GSR (galvanic skin response): change of electrical properties of skin
        * Under emotional arousal and stress, body sweats and skin conductance increases
        * One of the best and widely used discriminative signal along with HR for measuring stress [Source](https://pubmed.ncbi.nlm.nih.gov/22921417/)
        * mean amplitude, SD, min and max avlues, RMS and delay between stimulus and response, number of peaks, peak heigh, rising time, recovery time and position of min and max features are used to measure stress [Source](https://pubmed.ncbi.nlm.nih.gov/30825538/)

* [Stress detection in daily life scenarios using smart phones and wearable sensors: A survey](https://pubmed.ncbi.nlm.nih.gov/30825538/)
  * Survey of stress detection with smart watches and phones
  * Describes different stress data collection methods and analysis methods

* Smart watches that do HR and EDA
  * [Fitbit Sense](https://www.fitbit.com/global/us/products/smartwatches/sense)
  * [Empatica E4 wristband](https://www.empatica.com/research/e4/)

* [Stress Detection using Smartwatches with Machine Learning: A Survey](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=9155568)
  * Survey of stress data types and ML algos
  * Combo of sensor data together is more accurate (i.e. ST, BVP (blood volume pulse) and HR)
  * Window size also affects accuracy, optimal as 120s

* [Posture and Movement Classification: The Comparison of Tri-Axial Accelerometer Numbers and Anatomical Placement](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4023813/)
  * Study on accelerometer placement and where best to place them
  * Less sensors better for patient compliance
  * For 1 sensor, thigh placement was best to identify static vs dynamic movements

* [Aware Mental Stress Detection Using Physiological Sensors](https://link.springer.com/content/pdf/10.1007%2F978-3-642-29336-8_16.pdf)
  * Study determined using an accelerometer placed on the hip increased classification accuracy
    * This is because HR maybe higher when standing then sitting vs mental stress - so must classify activity

* [Human activities & posture recognition: innovative algorithm for highly accurate detection rate](https://mro.massey.ac.nz/bitstream/handle/10179/4339/02_whole.pdf?sequence=1&isAllowed=y)
  * Considers viability and ethical uses of sensors for posture
  * Algorithm for posture detection

* [A review on wearable photoplethysmography sensors and their potential future applications in health care](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6426305/)
  * Use of PPG sensors for health
  * Placement on wrist is best
  * How PPG works

* [Automatic Stress Detection in Working Environments from Smartphones’ Accelerometer Data: A First Step](https://arxiv.org/pdf/1510.04221.pdf)
  * Workplace stress setting
  * Self-reported perceived stress levels during working hours (3 times)
  * Data from single accelerometer (smart phone), accuracy of 71%
  * Smart phone less intrusive than most sensors
  * Describes feature extraction techniques
  * Includes a little comparison on other related work

