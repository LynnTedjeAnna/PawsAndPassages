#include "lightSensorHandler.h"

LightsensorHandler::LightsensorHandler(int l_sensor,  MessageHandler messageHandler) {
    L_Sensor = l_sensor;
    Low = 3;
    Mid = 65;
    lightSensorMessageHandler = messageHandler;
}

void LightsensorHandler::setupLightsensor() {
    pinMode(L_Sensor, INPUT);
}

void LightsensorHandler::readLightsensorValues() {
    int l_sensor = analogRead(L_Sensor);
    l_sensor = map(l_sensor, 12, 1000, 0, 100);
    //lightSensorMessageHandler.sendMessage("LS:" + String(l_sensor));

    if (l_sensor < Low) {
        lightSensorMessageHandler.sendMessage("L");
    }
    else if (l_sensor > Low && l_sensor < Mid) {
        lightSensorMessageHandler.sendMessage("M");
    }
    else if (l_sensor > Mid) {
        lightSensorMessageHandler.sendMessage("H");
    }
}