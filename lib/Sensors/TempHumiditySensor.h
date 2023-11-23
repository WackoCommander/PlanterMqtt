#pragma once

class TempHumiditySensor
{
    public:
        TempHumiditySensor();
        int Attach(int, int);
        int GetReading();
    private:
        bool attached_;
        int pin_power_;
        int pin_reading_;
};