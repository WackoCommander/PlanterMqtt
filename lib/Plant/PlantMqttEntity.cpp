#include "PlantMqttEntity.h"
#include <ArduinoJson.h>

PlantMqttEntity::PlantMqttEntity(PubSubClient& client, Plant& plant)
: plant_(plant), client_(client) 
{
    // creating topics
    topic_ = plant_.GetName();
    // topics_.push_back(std::make_pair(plant_.GetName()+"/moisture", 0));
}

void PlantMqttEntity::SendSensorValues()
{
//    // sending a fake reading
//     char buffer[256];
//     DynamicJsonDocument doc(1024);
//     doc["moisture"] = 99;
//     size_t n = serializeJson(doc, buffer);
//     Serial.println("Sending fake data...");
//     client_.publish(topic_.c_str(), buffer,n);
    Serial.println("Sending fake data...");
    Serial.println(topic_.c_str());
    client_.publish(topic_.c_str(), "21");
}