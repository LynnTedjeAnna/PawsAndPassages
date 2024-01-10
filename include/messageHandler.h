#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <Arduino.h>

class MessageHandler
{
    public:
    MessageHandler(char start = '#', char stop = '%');

    void sendMessage(String message);
    String receiveMessage();

    private:
    char Start;
    char Stop;
};
#endif