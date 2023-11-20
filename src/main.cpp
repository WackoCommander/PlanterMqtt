/// Header Files
#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiS3.h>
#include "WifiCreds.h"
#include "MqttCreds.h"
#include "Plant.h"
#include <tuple>

/// Global variables
WiFiClient wifi_client;
PubSubClient client(wifi_client);

/// Function prototypes
int ConnectWifi(std::string wifi_ssid, std::string wifi_password);
int ConnectMqtt(std::string id, std::string mqtt_server, int mqtt_port, std::string mqtt_user, std::string mqtt_password);
int CheckTimeOut(int);

/// List of Plants 
std::vector<std::tuple<std::string, int, int>> plant_ids = {std::make_tuple("test_plant",2,3)};


void setup() {
    Serial.begin(9600);
    // Connect to WiFi.
    if (!ConnectWifi(WIFI_SSID, WIFI_PASSWRD))
    {
      Serial.println("Connection to WiFi successful...");
    } 
    else
    {
      Serial.println("Connection to WiFi timed out...");
    }

    // Connect to Mqtt Server.
    if (!ConnectMqtt("Plant Hub", MQTT_SERVER, MQTT_PORT, MQTT_USER, MQTT_PASSWRD))
    {
      Serial.println("Connection to MQTT server successful...");
    } 
    else
    {
      Serial.println("Connection to MQTT server timed out...");
    }
    
    // Create Plant objects and Connect to Mqtt server    
    std::vector<Plant> plants;
    for (auto plant_id : plant_ids)
    {
      plants.push_back(Plant(std::get<0>(plant_id)));
      plants.back().AttachSensors(std::get<1>(plant_id), std::get<2>(plant_id));
    }    
    client.publish("test_plant","test");
}

void loop() {
}

int ConnectWifi(std::string wifi_ssid, std::string wifi_password) 
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWRD);
  Serial.println("Connecting to WiFi...");
  constexpr int time_max = 5000;
  long time_elapsed = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
     if(CheckTimeOut(time_elapsed))
     {
      return 1;
     } 
     time_elapsed = time_elapsed + 500;
  }
  return 0;
}

int ConnectMqtt(std::string id, std::string mqtt_server, int mqtt_port, std::string mqtt_user, std::string mqtt_password)
{
  client.setServer(mqtt_server.c_str(), mqtt_port);
  Serial.println("Connecting to MQTT server...");
  int time_elapsed = 0;
  while (!client.connect(id.c_str(), mqtt_user.c_str(), mqtt_password.c_str()))
  {
    if (CheckTimeOut(time_elapsed))
    {
      return 1;
    }
    time_elapsed = time_elapsed + 500;
  }
  return 0;
}

int CheckTimeOut(int time_elapsed)
{
  delay(500);
  // Serial.print(".");
  if (time_elapsed > 5000)
  {
    return 1;
  }
  return 0;
}