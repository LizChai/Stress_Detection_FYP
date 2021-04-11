# Development Notes

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
  * Used for Heart Rate monitor: 8-bit address: 0xA0
  * Communication between master and multiple slave devices
  * Only 2 wires are used for comms
    * Use preset/unique ID
    * SCL (Serial Clock Line) and SDA (Serial Data)
    * Lines (bus) are 'open-drain' so require pull-up resistors
    * Devices are active low
  * Messaging
    * Start, Device (Slave) Address (7-bit + R/W), Acknowledgement, Internal Register Address, A, Data, A, Stop
    * Need to know Slave Address and Internal Reg Address
  * Auto-generated SDA/SCL GPIO Pins were wrong
    * Use menuconfig to change (in i2c_self_test)
    * CONFIG_I2C_MASTER_SCL=22
    * CONFIG_I2C_MASTER_SDA=23
