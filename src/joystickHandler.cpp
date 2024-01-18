#include "joystickHandler.h"

JoystickHandler::JoystickHandler(int joy_x, int joy_y, MessageHandler messageHandler) {
    Joy_X = joy_x;
    Joy_Y = joy_y;
    joyThreshold = 100;
    joystickMessageHandler = messageHandler;
}

void JoystickHandler::setupJoystick() {
    pinMode(Joy_X, INPUT);
    pinMode(Joy_Y, INPUT);
}

JoyResult JoystickHandler::getJoyPosition() {
    int joyX = analogRead(Joy_X) - 345;
    int joyY = analogRead(Joy_Y) - 327;

    if (joyX < -joyThreshold) { // user pushes left
        return Left;
    }
    if (joyX > joyThreshold) { // user pushes right
        return Right;
    }
    if (joyY > joyThreshold) { // user pushes up
        return Up;
    }
    if (joyY < -joyThreshold) { // user pushes down
        return Down;
    }

    // If no condition is met, a default value is returned
    return Neutral;
}
