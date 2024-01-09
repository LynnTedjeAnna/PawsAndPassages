#include "ledHandler.h"

LedHandler::LedHandler(int led, int delay) {
    Led = led;
    Delay = delay;
}

void LedHandler::setupLed(){
    pinMode(Led, OUTPUT);
    digitalWrite(Led, LOW);
}

void LedHandler::writeLedValues(){
    if (Serial.available() >= 3) {
        Serial.readStringUntil('#');
        String message = Serial.readStringUntil('%');
        
        if (message == "T") {
            digitalWrite(Led, HIGH);
            Start = millis();
        }
    }

    if (millis() - Start > Delay)
    {
        digitalWrite(Led, LOW);
    }
}