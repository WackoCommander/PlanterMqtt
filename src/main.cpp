#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiS3.h>
#include "WifiCreds.h"
#include "MqttCreds.h"

WiFiClient wifi_client;
PubSubClient client(wifi_client);

void setup() {
    Serial.begin(9600);
    WiFi.begin(WIFI_SSID, WIFI_PASSWRD);
    Serial.println("Connecting to Wifi...");
    if (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected...");
    client.setServer(MQTT_SERVER, MQTT_PORT);
    Serial.println("Connecting to Mqtt server...");

  while (!client.connected()) {
    Serial.print(".");

    if (client.connect("test", MQTT_USER, MQTT_PASSWRD)) {

      Serial.println("Connected to MQTT");
    } else {
      Serial.println("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {

}


