#include "lightSensorHandler.h"

LightsensorHandler::LightsensorHandler(int l_sensor, MessageHandler messageHandler) {
    L_Sensor = l_sensor;
    lightSensorMessageHandler = messageHandler;
}

void LightsensorHandler::setupLightsensor() {
    pinMode(L_Sensor, INPUT);
}

void LightsensorHandler::readLightsensorValues() {
    int l_sensor = analogRead(L_Sensor);
    l_sensor = map( 5, 700, 0, 100, l_sensor);
    lightSensorMessageHandler.sendMessage("LS:" + String(l_sensor));
}