#ifndef JOYSTICK_HANDLER_H
#define JOYSTICK_HANDLER_H

#include <Arduino.h>

class JoystickHandler {
    public:
    // Constructor: Takes an array of joystick pins as an argument
    JoystickHandler(int joy_x, int joy_y);

    // Public member function to set up the joystick
    void setupJoystick();

    // Public member function to read joystick values and generate messages
    void readJoystickValues();

    private:
    // Private member variables
    int Joy_X;
    int Joy_Y;
    int joyThreshold;   // Threshold value for joystick movement
};

#endif