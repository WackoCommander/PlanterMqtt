
class PlantMqttEntity : public Plant
{
    public:
        PlantMqttEntity(PubSubClient* client, Plant);
        void SendSensorValues();        
}