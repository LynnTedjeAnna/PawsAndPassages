#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <Arduino.h>
#include "messageHandler.h"

#define BUTTON_COUNT 7


class ButtonHandler {
public:
	// Constructor
	ButtonHandler(int buttonPins[], MessageHandler messageHandler);

	// Public member function to set up the buttons
	void setupButtons();

	// Public member function to check for button presses and generate messages
	void checkButtonPress();

	private:
	// Private member variables
	int buttons[BUTTON_COUNT];         // Array to store button pins
	bool buttonPressed[BUTTON_COUNT];  // Array to track button press state
    MessageHandler buttonMessageHandler;
};

#endif