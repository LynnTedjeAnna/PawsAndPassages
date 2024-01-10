#ifndef LIGHTSENSORHANDLER_H
#define LIGHTSENSORHANDLER_H

#include <Arduino.h>
#include "messageHandler.h"

class LightsensorHandler{
public:
    LightsensorHandler(int l_sensor, MessageHandler messageHandler);
    void setupLightsensor();
    void readLightsensorValues();

private:
    int L_Sensor;
    MessageHandler lightSensorMessageHandler;
};

#endif