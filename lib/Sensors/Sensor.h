#pragma once

class Sensor
{
    public:
        virtual int Attach(int, int) = 0;
        virtual int GetReading() = 0;
};