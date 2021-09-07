# Sep 2 2021 - Week 6 Progress

## Progress/Development

* Researched more and reviewed literature about HRV and GSR data features
  * Makes more sense to use normalised HR values and GSR values (mean, std)
    * Use raw HRV data for heart variation: mean, std and RMSSD (root mean square of successive differences)
      * oscillations of healthy heart rate are complex and constantly changing; where the cardiovascular system rapidly adjusts to sudden physical and psychological challenges to homeostasis
      * higher HRV = stress + sympathetic system
      * lower HRV = parasympathetic system
    * Use normalised HR data: mean, std for general HR characteristics
    * Use normalised GSR data: mean, std for SCL (skin conductance levels) and mean/std/rate of peaks of GSR for SCR (skin conductance responses)
      * More responses = more stress
      * Higher means + larger std = more variation
* Stopped using max and min peaks because I was min-max normalising and this resultant features didn't make sense
  * I.e. finding the max of a min-max peak normalised model resulted in the max values being 1
* Decided on and integrated new parameters into models:
  * Heart Rate Variability
    * HR HRV average value (HRV) - Raw data
    * HR HRV standard deviation (Variation of HRV) - Raw data
    * HR HRV RMSSD  (Changes in HRV) - Raw data
  * Heart rate
    * HR average value - Normalised data
    * HR standard devation - Normalised data
    * Difference between HR Max and HR Min - Raw data
      * Measures variability in amplitude
  * Galvanic Skin Response
    * GSR average value (Skin Conductance Level) - Normalised data
    * GSR standard deviation (Skin Conductance Level variability) - Normalised data
    * GSR peaks (Skin Conductance Responses) - Normalised data
    * GSR peaks over time (Skin Conductance Responses per second) - Normalised data
    * GSR peaks mean (Skin Conductance Response average) - Normalised data
    * GSR peak std (Skin Conductance Response variability) - Normalised data

* This resulted in more logical data/results
  * Training Data
    * <img src=".\Pics\training_data_HR_1.png" alt="image" width="300"/> <img src=".\Pics\training_data_HRV_1.png" alt="image" width="300"/> <img src=".\Pics\training_data_GSR_1.png" alt="image" width="300"/>
      * Can see that data is non-linear and hard to just pick a threshold (decision tree may not perform well)
  * PCA <img src=".\Pics\PCA.png" alt="image" width="300"/>
  * LDA <img src=".\Pics\LDA.png" alt="image" width="300"/>
    * Can kind of see clusters forming > tried KNN or SVM

* Tried different models of Logistic regression, KNN, SVM, Decision trees and k-means
  * Example Decision Tree result <img src=".\Pics\decision_tree.png" alt="image" width="300"/>
  * Example K-means result <img src=".\Pics\knn6.png" alt="image" width="300"/>
  * Labels are difficult and time-consuming so tried unsupervised model (kmeans)

* Trained/tested data using cross validation folds
  * Didn't really help that much
* Updated Project Journal
* Tested predicting live (see .txt attachment for outputs)
* Added code to monitor battery voltage
* Added discussions on hardware and data to final report

## Results

| Model | Data | Parameters | Accuracy (%) |
| ----------- | ----------- | ----------- | ----------- |
| Logistic | No preprocessing | N/A | 65 |
| KNN | No preprocessing | k=10, metric=uniform | 52 |
| KNN | No preprocessing | k=[2,3,4,5,6,10] metric=[distance, uniform] | Similar results |
| Logistic | Min-Max normalised, LPF (min, max, ave, HR & GSR) | N/A | 59 |
| KNN | Min-Max normalised, LPF (min, max, ave, HR & GSR) | k=10 | 76 |
| KNN | Min-Max normalised, LPF (min, max, ave, HR & GSR) | k=[2,3,4,5,6,10] metric=[distance, uniform] | Similar results |
| Logistic | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | N/A | 67 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=2, metric=uniform | 79 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=2, metric=distance | 76 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=3, metric=uniform | 76 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=3, metric=distance | 79 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=5, metric=uniform | 72 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=5, metric=distance | 79 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=10, metric=uniform | 61 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=10, metric=distance | 79 |
| SVM | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | N/A | 56 |
| Decision Tree | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | no max_depth | 61 |
| Decision Tree | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | max_depth=4 | 59 |
| kmeans | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=2 | 57 |
| kmeans | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, num_peaks, rate_peaks, peak_mean*, peak_std) | k=6 | 74 |
| Logistic | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | N/A | 61 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | k=3, metric=distance | 79 |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | k=5, metric=distance | 87 (best model) |
| KNN | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | k=10, metric=distance | 79 |
| SVM | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | N/A | same as unpruned |
| Decision Tree | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | no max_depth | same as unpruned |
| Decision Tree | HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | max_depth=4 | same as unpruned |
| kmeans| HR (mean, std, diff), HRV (mean, std, RMSSD), GSR (mean, std, rate_peaks, peak_mean, peak_std) | k=6 | 38 (worse) |

* Note: * indicates that I was incorrectly using the raw GSR peak values for the mean and standard deviation
  * This gets updated later to normalised GSR values

* Best model was then used to test on live data
  * Result <img src=".\Pics\knn_best.png" alt="image" width="300"/>

## Todo

* Record/test more data
  * Get recording from housemate
* Live plotting / red-green indicator / graphical representation for stress
  * Display HR, HRV and GSR values
  * Add battery monitoring
* Update Project Journal
* Continue Final Assessments - Presentation, video, report, poster
  * (SPARK Night, Self-Assessed Rubric)
