# Mosquitto MQTT on Home Assistant
### Integrating Mosquitto MQTT with Home Assistant to create a local MQTT broker, and a basic code to demonstrate it's working.  
<br/>  
  
***Overview :***  
In this repository, we will be seeing how to install [Mosquitto MQTT](https://mosquitto.org/) broker on Home Assistant. In case you need help with installing Home Assistant on Virtual Box, refer to this [repository](https://github.com/Bharadwaj-R/Home-Assistant-on-Windows) where it was explained in detail.  
<br/>  
  
***Prerequisites :***  
- Home Assistant (Setup either on virtual box or Raspberry Pi)  

<br/>  
  
### About MQTT and Mosquitto
MQTT Protocol is a light weight *Publish and Subscribe* based IoT communication protocol, that provides for two way communcation between the IoT devices. You can learn more about MQTT [here](https://mqtt.org/). There are many MQTT broker providers on the cloud ([hivemq](https://www.hivemq.com/public-mqtt-broker/), [EMQ](https://www.emqx.com/en/mqtt/public-mqtt5-broker), [Adafruit IO](https://io.adafruit.com/)), but they all come with certain drawbacks - be it less secure, or a limitation on the number of topics that can be created at a time. But Mosquitto MQTT provides for a local MQTT broker on our hardware, the main advantage of which is that we can take things into our control.  
<br/>  

### Installing Mosquitto on Home Assistant  
Mosquitto is available as a direct add-on on Home Assistant, and hence, installing it is just a matter of few clicks. Follow the below steps to get started on the installation process.  
- Boot up your Home Assistant OS in the Virtual Box.
- Once the OS starts up, head over to `homeassistant.local:8123/` on your web browser and login with your credentials.
- Head over to the `Add-Ons` in `Settings` and then select `Add-On Store`.
- Search for `Mosquitto Broker`.
- Install the Add-On and turn on the `Start on Boot` and `Watchdog` options. Start the Mosquitto Broker.
- Once successfully installed, a pop-up should appear asking you to configure a new device that has been detected. If not, just head over to the `Devices and Services` sub-section in Settings.
- Follow the on-screen instructions to setup MQTT successfully.
- Once a new device is added, you can see the `Mosquitto Borker` in devices section.  
  
<br/>  

***Testing the MQTT Broker :***  
Once you see the Mosquitto on the Devices and Services section, the installation is successful, and we are ready to test the connection. We will test the connection in two different ways to check the working of Mosquitto on Home Assistant.  
<br/>  

### Testing Mosquitto on Home Assistant Web Dashboard  
- Head over to the `Devices and Services` sub-section in Settings and select the `Configure` option over Mosquitto.
- Type in the topic name that you want to publish to. 
- Type in the same topic name in the subscribe topic too, and click on `Start Listening`.
- Now type any message (eg. "Hello World") in the payload section and click on publish.
- The same messsage will appear on the subscribe window just below. This ensures that MQTT broker is live and running.  

***Note: Make sure you select the same QoS for both Publish and Subscribe.***  
<br/>   
  
### Testing Mosquitto using ESP32  
Using ESP32, we can publish to a given topic. Listening to the message can be done in the same way as mentioned before.  
- Download the code from [here]().
- Setup the Pub-Sub-Client library in Arduini IDE by following this [article]([https://www.arduino.cc/reference/en/libraries/pubsubclient/](http://www.steves-internet-guide.com/using-arduino-pubsub-mqtt-client/)).
- Make necessary changes to the code (like IP address of device, HASS username and password, publish and subscribe topics, etc.)
- WiFi for both ESP32 and the device running Home Assistant should be connected on the same WiFi network.
- Upload the code to ESP32 using Arduino IDE and check the connection status in the Serial Monitor.   

If everything is setup correctly, you should be able to listen to MQTT messages from the ESP in the Home Assistant dashboard, and vice versa.
<br/>  
  
***And that's it!***   
You've successfully installed the Mosquitto MQTT broker on Home Assistant. Now that you have setup the MQTT broker, do you want to make it more flashy, and create your own dashboard and run routines in a GUI? Well, changing the code is always possible, but do you want it to be more simplified? Then [*Node-RED*](https://nodered.org/) is the way to go. Follow my other repository on [Node-RED installation on Home Assistant](https://github.com/Bharadwaj-R/Node-RED-and-Home-Assistant) to get started. 
