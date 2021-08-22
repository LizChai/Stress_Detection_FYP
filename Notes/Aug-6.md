# Aug 06 2021 - Week 2 Progress Update

* I've managed to get all the hardware (GSR and HR) working with the ESP32!!!

* Not sure what was wrong with the GSR, but I rechecked all the connections and wiring, and it works fine now (hopefully stays that way). I used some duct tape to ensure everything is sturdy and robust now.

* The Grove HR Sensor I initially bought has timing issues (due to the ESP32 I2C Wire library not supporting continuous transmissions and/or that ESP32 I2C has a hardware timeout on transmissions after 13.1ms; as well as the fact that the STM32 included in the sensor uses Slave stretching to send data, which causes the timeouts). I can make the ESP32 recover, however every time the bus timeouts, the sensor needs a powercycle. I spent yesterday trying to use GPIO and transistors in a circuit to power cycle the sensor via a pull-down switch; however I can't get enough current draw to do so.
  * I've drawn out the diagram which I used to powercycle the sensor; however I feel like power cycling a sensor every time it stops working isn't the best way to go about reading continuous data. Especially as it takes a few readings to report accurate values and a few seconds to power cycle. I feel like the MAX sensor is the way to go; since no dodgy power cycling is required; just some good ol' signal processing. I only have measly transistors at home, so if I use a MOSFET instead; the circuit and current draw will be better. This power cycling circuit is not required if I just use the Arduino with the Grove sensor; but I think using only ESP32 + wifi is an achievable goal.
  * Not sure if you care about details, but found out the reason for the timing issues via reading through the a lot of the Github/forums of the ESP32 Wire library which wasn't in the documentation for the uC.
    * [Link 1](https://github.com/espressif/arduino-esp32/issues/4729)
    * [Link 2](https://github.com/espressif/arduino-esp32/issues/3701)

* The MAX30102 sensors that we borrowed now work with the ESP32 (it has its own library, which sorts out these timing issues). Even though the chip was labelled MAX3010; it was actually a MAX30102 (so I was using the old library and hence it wasn't working). I'm thinking of using this HR sensor instead. It's very sensitive; so will require a lot of software data/signal processing.
  * The component number printed on the sensor circuit board was incorrect; so I was looking at the wrong datasheets, documentation and running the wrong libraries last Thursday - hence why it didn't work. The sensor with the broken glass reports wildly inaccurate readings (probably due to light intensity inconsistencies), however the other one works.

* Looking to come up with a veroboard wiring schematic and solder the sensors and uC together over the weekend so that I have a more convenient package to use for data collection.

* Next week, I'm planning to get signal processing done for the HR sensor to collect good data and write a main script that runs both the GSR and HR at the same time to collect data.
