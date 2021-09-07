# Aug 19 2021 - Week 4 Development Notes

## Development Notes

* [MQTT](https://learn.sparkfun.com/tutorials/introduction-to-mqtt/all)
  * MQTT: Messaging Queuing Telemtetry Transport
    * Publish/subscribe messaging protocol that works on top of TCP/IP protocol
    * Faster than HTTP requests for IoT devices as MQTT messages are small (~2bytes), whereas HTTP requires headers
    * MQTT automatically distributes information to interested clients when received by a server; HTTP requires a POST from each each client
    * Terminology:
      * Broker: server that distributes the info to interested clients connected to server
      * Client: device that connects to broker to send or receive info
      * Topic: name that message is about; clients publish, subscribe or both
      * Publish: clients that sned info to the broker to distribute to interested clients based on topic name
      * Subscribe: clients tell broker which topics they're interested in; when a client subscribes to a topic, any message published to broker is distribued to subscribers of that topic; clients can also unsubscribe to stop receiving messages from broker about topic
      * QoS: quality of service; each connection can specifiy quality of service to broker with an integer value ranging from 0-2; does not affect handling of TCP data transmissions, only between MQTT clients
        * 0: at most once; or once and only once without requiring an acknolwedgement of delivery; fire and forget
        * 1: at least once; message is sent multiple times until an ack is received; acknowledged delivery
        * 2: exactly once; sender and receiver clients use a two level handshake to ensure only one copy of message is received; assured delivery

* Setting up MQTT
  * Installed MQTT broker; Eclipse Mosquitto
    * open source message broker using MQTT protocol; lightweight, suitable for low power single board computers to full
    * start broker with "mosquitto -c mosquitto_conf.conf -v" on computer
  * Installed PubSubClient Arduino library
    * Wrote PubSub code in Arduino IDE to set up client, connect to WiFi, connect to broker and publish data to topic
  * Installed MQTT library for python
    * Wrote code in python to set up client, connect to broker and subscribe to topic

## Progress Update

* Fixed HR filtering and data sampling in software
* Ordered a LiPo
* Wrote code to record and send data over WiFi via MQTT
  * Installed MQTT broker; Eclipse Mosquitto
    * open source message broker using MQTT protocol; lightweight, suitable for low power single board computers to full
    * start broker with "mosquitto -c mosquitto_conf.conf -v" on computer
  * Installed PubSubClient Arduino library
    * Wrote PubSub code in Arduino IDE to set up client, connect to WiFi, connect to broker and publish data to topic
  * Installed MQTT library for python
    * Wrote code in python to set up client, connect to broker and subscribe to topic
* Wrote code to live predict stress state using pre-trained model and filtering
  * Integrate sensor readings with machine learning script for prediction
* Started data collection
  * Me when demonstrating vs resting - record times
  * Recorded 1hr of data on someone else
* Wrote up experimental procedure
* Brainstored FYP project name
  * Think of cool parts; HW, Data, SW
  * What is novel?
    * Stress Monitoring; low-cost, wearable, IoT
  * Ideas
    * Low-cost IoT Wearable for Stress Detection
    * Low-cost Wearable IoT Device for Stress Detection

## Experimental procedure

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

## Todo

* Record more data
* Integrate HR data into model
* Train other machine learning models
* Fabricate container for sensors, microcontroller and LiPo
* Start Final Assessments
  * Brainstorm selling points of FYP
    * Incorporates aspects of whole ECSE degree: electronics/HW (microcontrollers/sensors), SW, design, data (collection, signal processing, machine learning), telecommunication, power
    * Novel, low-cost, wearable
    * Stress detection
    * Related to breakthrough technologies required to achieve SDGs by 2030; [Global Health](https://50breakthroughs.org/37/details/bt/)
