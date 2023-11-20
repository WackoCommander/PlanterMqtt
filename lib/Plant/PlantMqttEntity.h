#pragma once

#include "Plant.h"
#include <PubSubClient.h>
#include <vector>
class PlantMqttEntity 
{
    public:
        PlantMqttEntity(PubSubClient& client, Plant& plant);
        void SendSensorValues();        
    private:
        Plant &plant_;
        PubSubClient &client_;
        std::string topic_;
        // std::vector<std::pair<std::string,int>> topics_;
};