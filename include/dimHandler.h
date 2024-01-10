#ifndef DIM_HANDLER_H
#define DIM_HANDLER_H

#include <Arduino.h>

class DimHandler {
    public:
    DimHandler(int pin, String key, int delay = 5000);

    void setupPin();
    String getKey();
    void turnOn();
    void update();

    private:
    int Pin;
    unsigned long Start = 0;
    unsigned  long Delay;
    String Key;
};
#endif