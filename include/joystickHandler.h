#ifndef JOYSTICK_HANDLER_H
#define JOYSTICK_HANDLER_H

#include <Arduino.h>
#include "messageHandler.h"

class JoystickHandler {
public:
    JoystickHandler(int joy_x, int joy_y, MessageHandler messageHandler);
    void setupJoystick();
    void readJoystickValues();

private:
    int Joy_X;
    int Joy_Y;
    int joyThreshold;
    MessageHandler joystickMessageHandler;
};

#endif