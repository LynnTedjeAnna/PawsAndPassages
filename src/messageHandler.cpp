#include "messageHandler.h"

MessageHandler::MessageHandler(char start, char stop) {
    Start = start;
    Stop = stop;
}

void MessageHandler::sendMessage(String message) {
    message = Start + message + Stop;
    Serial.println(message);
}

String MessageHandler::receiveMessage() {
    if (Serial.available()) {
        Serial.readStringUntil('#');
        return Serial.readStringUntil('%');
    }
    //have to return string, even when returning nothing
    return "";
}
