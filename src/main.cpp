#include <Arduino.h>
// #include <PubSubClient.h>
// #include <ArduinoJson.h>
// #include <WiFiNINA.h>
// #include <ESP8266WiFi.h>
#include <WiFi.h>
// #include <WiFiNINA_Generic.h>
const char* WIFI_SSID = "Hydrapeak";
const char* WIFI_PASSWRD = "Rectal5-Patchy-Everybody";



// WiFiClient wifi_client;
// PubSubClient client(wifi_client);

void setup() {
    Serial.begin(9600);
    WiFi.begin(WIFI_SSID, WIFI_PASSWRD);
    Serial.print("Connecting to Wifi...");
    if (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.print("Connected...");
}

void loop() {

}


