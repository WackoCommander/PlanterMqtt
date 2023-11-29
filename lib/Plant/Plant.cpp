#include "Plant.h"


Plant::Plant(std::string name)
: name_(name)
{
}

int Plant::AttachSensors(int soil_sensor_pin_power, int soil_sensor_pin_reading, int temp_humidity_pin)
{
    Serial.println("Attaching soil moisture sensor..");
    if(!sensor_soil_moisture_.Attach(soil_sensor_pin_power, soil_sensor_pin_reading))
    {
        Serial.println("Attachment to soil moisture sensor successful...");
        // return 0;
    }

    Serial.println("Attaching temperature and humidity sensor...");
    dht_ = new DHT(temp_humidity_pin, DHT11);
    Serial.println("Attachment to temperatuer and humidity sensor successful...");
    // GetTemperature();
    return 0;
}

int Plant::GetSoilMoisture()
{
    
    moisture_ = sensor_soil_moisture_.GetReading();
    std::string msg = "Moisture: " + std::to_string(moisture_);
    return moisture_;
}

int Plant::GetTemperature()
{
    digitalWrite(13,HIGH);
    delay(10);
    temperature_ = dht_->readTemperature();
    std::string msg = "Temperature: " + std::to_string(temperature_);
    Serial.println(msg.c_str());
    return temperature_;
    digitalWrite(13, LOW);
}

std::string Plant::GetName()
{
    return name_;
}
