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

  * [Stress Detection using Deep Learning and IoT](https://www.ijresm.com/Vol.2_2019/Vol2_Iss8_August19/IJRESM_V2_I8_14.pdf)
    * These people cite the above paper just detect stress via CNNs for facial expression; no reported accuracy though

