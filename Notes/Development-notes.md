# Hardware/software Development Notes

## Mar 29 2021

* Activate Jupyter Notebook environment:
  * Open Powershell
  * cd to FYP\Stress_Detection_FYP
  * Run Scripts\activate
  * Run jupyter lab

* Run GSR Sensor
  * ADC1 example
  * cd to hello_world folder
  * idf.py build
  * idf.py flash monitor (to see in VSC Terminal)
  * In Jupyter lab, \python_scripts\graph_testing

* ADC Set up (for GSR Sensor)
  * >> idf.py set-target esp32
  * adc_unit_t = ADC_UNIT_1
    * SAR ADC 1
  * adc_atten_t = ADC_ATTEN_DB
  * adc_channel_t channel = ADC_CHANNEL_0;     //GPIO36 if ADC1 (A4)

## Apr 09 2021

* GSR Sensor Notes
  * Sensor reads out voltage (between 0-1023 analogue) as Serial_Port_Reading
  * Usually used with an Arduino which has a 10-bit ADC (0-1023)
  * Human Resistance = (1024+2*Serial_Port_Reading)*10000/(512-Serial_Port_Reading)
* Need to read circuit diagram to figure out what the actual output is

## Apr 11 2021

* I2C Communication
  * Used for Heart Rate monitor: 8-bit address: 0xA0 (do not use), 7-bit address: 0x50
  * Communication between master and multiple slave devices
  * Only 2 wires are used for comms
    * Use preset/unique ID
    * SCL (Serial Clock Line) and SDA (Serial Data)
    * Lines (bus) are 'open-drain' so require pull-up resistors
    * Devices are active low
  * Messaging
    * Start, Device (Slave) Address (7-bit + R/W), Acknowledgement, Internal Register Address, A, Data, A, Stop
    * Need to know Slave Address
  * Auto-generated SDA/SCL GPIO Pins were wrong
    * Use menuconfig to change (in i2c_self_test)
    * CONFIG_I2C_MASTER_SCL=22
    * CONFIG_I2C_MASTER_SDA=23

## Apr 18 2021

* Grove HR Sensor
  * Needs at least 500ms delay
  * Got it working with ESP32 for a few tries, then an slave holds clock low after the 9th bit (after ACK bit) as it is doing something (i.e. preparing data) and never releases it
    * If a slave cannot receive or transmit another complete byte of data until it has performed some other function, for example servicing an internal interrupt, it can hold the clock line SCL LOW to force the master into a wait state
    * CPU is processing I2C interrupt to evaluate either the address or process data received from Master, or to prepare next data when Master is reading from the Slave
    * The time the clock is pulled low depends on time the CPU takes to process the interrupt and hence is dependent on CPU speed and not I2C clock speed

## Apr 19 2021

* GSR Sensor
  * Recorded 15mins of data
  * Recorded stroop test data (5 mins of data)
    * Test 1 (with text colours matching word): 14.1715 seconds
    * Test 2 (with text colours not matching word): 16.526 seconds
  * Recorded [PSS](https://www.bemindfulonline.com/test-your-stress) value: 24 (5 mins of data)

## Apr 22 2021

* GSR Sensor
  * Recorded Assessment Centre (for Grad role)

## Apr 26 2021

* HR monitor
  * Tried different timings
    * Fix was that it needed at least 500ms (allowed for more readings, but still not 100% fixed)
    * Got it working with ESP32 for a few tries, then an slave holds clock low after the 9th bit (after ACK bit) as it is doing something (i.e. preparing data) and never releases it
    * Tried different GPIO Pins and wires, breadboard
* GSR Sensor
  * Circuit consists of input A and input B into a differential amplifier: 2*(V2-V1)
  * Input A consists a voltage divider with a variable resistor to a unity gain amplifier and has output of V1
  * Input B consists a voltage divider with the GSR Sensor (resistance) to a unity gain amplifier and has output of V2
  * Output of circuit is a voltage, which is read into a 10 bit ADC (0-1023)
  * Variable resistor is set so that when no resistance in Input B (no finger/GSR response), the ADC output is 512
  * To double check what is happening, could use an oscilloscope to measure voltages in the circuit

## May 01 2021

* HR Monitor
  * Tried Arduino IDE
    * Reports 0 HR until I place my finger in front of it - then it stops working
    * Same behaviour as before, where the SCL gets pulled low forever and does not recover
  * [Description of issue](https://www.gitmemory.com/issue/espressif/arduino-esp32/2751/489630472)
    * The "gross" timeout is telling you that the slave stretched SCL (paused communications while sampling) longer than the ESP32 can handle (approximately 13.1ms). It is a fatal error.
    * The cascade of errors is because the ESP32 aborted the READ transaction when it timed out. But the Sensor is still in read mode. It is trying to output the sensor value, but the ESP32 is trying to begin a new transaction. The bus is in use (Slave is driving SDA, waiting for the Master(ESP32) to cycle the SCL Clock. Except, the ESP32 is waiting for the Bus to Clear (SCL & SDA high).
    * Other forums [1](https://github.com/espressif/arduino-esp32/issues/834) [2](https://github.com/espressif/arduino-esp32/issues/2261)
  * [Logs] (C:\Users\ieliz\Documents\2021\FYP\Stress_Detection_FYP\arduinoIDE\debugging_020521_1.txt)
  * Tried fix to various ESP32 I2C Libraries by [stickbreaker](https://github.com/stickbreaker/arduino-esp32/tree/master/cores/esp32)
    * ESP32 I2C HAL is based on polling, which may not work with our hardware [Source](https://github.com/espressif/arduino-esp32/issues/1071#issuecomment-381319506)
    * Installed library, still no luck - located [here](C:\Users\ieliz\AppData\Local\Arduino15\packages)
  * Tried physical pull up resistors (2.7k)
    * The inbuilt ESP32 pullups are not strong enough [Source](https://github.com/espressif/arduino-esp32/issues/741#issuecomment-337461933)
  * Tried [SlowSoftI2C Library](https://github.com/felias-fogg/SlowSoftI2CMaster) (alternative to Wire)
    * Generic AMD version of [SoftI2C Library](https://github.com/felias-fogg/SoftI2CMaster)
      * Ports for SoftI2C related to [Port Registers](https://www.arduino.cc/en/Reference/PortManipulation)
    * Does not time out
    * However only reads 255 all the time
    * Potentially dueto timing (slow library)

## May 03 2021

* GSR Readings + Literature
  * Literature Review Source 6:
    * Skin conductance increases with stress; skin resistance reduces with stress
    * ADC reading being measured by my GSR sensor as a voltage, which reduces with stress
      * This output voltage is proportional to skin resistance
      * Need to check this with oscilloscope/multimeter
    * Sampling frequency can range from 0.033Hz (2 samples/min) to 2kHz (2000 samples/sec)
      * Sampling frequency of 0.5-1 sample per second seems reasonable
        * 0.5Hz - 1Hz