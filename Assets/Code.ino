// Including the libraries
#include <PubSubClient.h>
#include<WiFi.h>
#include<Arduino.h>


// Credentials for WiFi and MQTT
const char *SSID = ".............";   //WiFi SSID
const char *PWD = "..............";   //WiFi Password
const char *mqtt_user = "........";   //Home Assistant Username
const char *mqtt_pass = "........";   //Home Assistant Password
const char *ip = "...............";   // IP address of Home Assistant 
const int port = 1883;                //default port for mqtt


// Declare publish and subscribe topics
const char *pubtopic = "test1";   // Topic to publish to
const char *subtopic = "test2";   // Topic to subscribe to


// callback -> to print the subscribed message topic -> called everytime the sub-topic is updated
void callback(char*, byte*, unsigned int); // Only instantiation. Actual function is written later


// Setting up the WiFi client and PubSubClient
WiFiClient wificlient;
PubSubClient mqttclient(ip, port, callback, wificlient);


//Connecting to WiFI network
void connectToWiFi()
{
  Serial.print("Connecting to ");
  WiFi.begin(SSID, PWD);
  Serial.println(SSID);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected!!");
}


// The actual callback function for printing the subscribed topic payload
void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.println();
  Serial.print("Subscribed Topic - ");
  Serial.println(topic);
  Serial.print("Message -");
  for(int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if((char)payload[0] == 'H')
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
  }
}


//Setting up MQTT connection
void setupMQTT()
{
  if(mqttclient.connect("NodeMCU-32S", mqtt_user, mqtt_pass))
  {
    Serial.println("Connected to MQTT Broker");
    mqttclient.subscribe(subtopic);
  }
}


// Our good old setup function
void setup()
{
  Serial.begin(115200);
  connectToWiFi();
  setupMQTT();
  pinMode(LED_BUILTIN, OUTPUT);
}


// Our good old loop function
void loop()
{
  mqttclient.loop();

  mqttclient.publish(pubtopic, "Hello There!");
  delay(2000);
}
