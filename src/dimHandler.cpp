#include "dimHandler.h"

DimHandler::DimHandler(int pin, String key, int delay) {
    Pin = pin;
    Delay = delay;
    Key = key;
}

void DimHandler::setupPin(){
    pinMode(Pin, OUTPUT);
    digitalWrite(Pin, LOW);
}

String DimHandler::getKey() {
    return Key;
}

void DimHandler::turnOn() {
    digitalWrite(Pin, HIGH);
    Start = millis();
}

void DimHandler::update() {
    if (millis() - Start > Delay) {
        digitalWrite(Pin, LOW);
    } else {
        // het stukje "(float)" is toegevoegd door een tech student
        // reden: het delen van getallen kan op twee manieren gedaan worden namelijk: integer division en floating point division
        // we hebben floating point division nodig omdat we nummers tussen de 0 en de 1 nodig hebben.
        // Dit zou niet mogelijk zijn in integer division.
        analogWrite(Pin, (1.0 - (float)(millis() - Start) / Delay) * 255);
    }
}