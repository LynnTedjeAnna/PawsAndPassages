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

void JoystickHandler::readJoystickValues() {
    int joyX = analogRead(Joy_X) - 345;
    int joyY = analogRead(Joy_Y) - 327;

    String message = "";
    if (joyX > joyThreshold) {
        message = "R";
    } else if (joyX < -joyThreshold) {
        message = "L";
    }
    if (message.length()) {
        joystickMessageHandler.sendMessage(message);
        message = "";
    }

    if (joyY > joyThreshold) {
        message = "U";
    } else if (joyY < -joyThreshold) {
        message = "D";
    }
    if (message.length()) {
        joystickMessageHandler.sendMessage(message);
        message = "";
    }
}