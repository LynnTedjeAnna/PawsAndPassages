#ifndef JOYSTICK_HANDLER_H
#define JOYSTICK_HANDLER_H

#include <Arduino.h>
#include "messageHandler.h"


enum JoyResult {
    Neutral,
    Left,
    Right,
    Up,
    Down
};

class JoystickHandler {
public:
    JoystickHandler(int joy_x, int joy_y, MessageHandler messageHandler);
    void setupJoystick();
    void readJoystickValues();
    JoyResult getJoyPosition();

private:
    int Joy_X;
    int Joy_Y;
    int joyThreshold;
    MessageHandler joystickMessageHandler;
};

#endif