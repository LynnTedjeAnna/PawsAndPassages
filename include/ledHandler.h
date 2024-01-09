#ifndef LED_HANDLER_H
#define LED_HANDLER_H

#include <Arduino.h>

class LedHandler {
    public:
    // Constructor: Takes an array of joystick pins as an argument
    LedHandler(int led, int delay = 250);

    // Public member function to set up the joystick
    void setupLed();

    // Public member function to read joystick values and generate messages
    void writeLedValues();

    private:
    // Private member variables
    int Led;
    int Start = 0;
    int Delay;
};
#endif