#include "buttonHandler.h"

ButtonHandler::ButtonHandler(int buttonPins[]) {
	for (int i = 0; i < BUTTON_COUNT; i++) {
		buttons[i] = buttonPins[i];
	}
}

void ButtonHandler::setupButtons() {
	for (int i = 0; i < BUTTON_COUNT; i++) {
		pinMode(buttons[i], INPUT_PULLUP);
		buttonPressed[i] = false;
	}
}

void ButtonHandler::checkButtonPress() {
	for (int i = 0; i < BUTTON_COUNT; i++) {

		if (digitalRead(buttons[i]) == LOW && !buttonPressed[i]) {
			String message = "#" + String(i) + "%";
			Serial.println(message);
			buttonPressed[i] = true;
			delay(10);
		} else if (digitalRead(buttons[i]) == HIGH) {
			buttonPressed[i] = false;
		}
	}
}