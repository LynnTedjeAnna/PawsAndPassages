#include <Arduino.h>
#include "buttonHandler.cpp"
#include "joystickHandler.cpp"
#include "ledHandler.cpp"

// Define pin constants
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define Joy_BT 8
#define Led 11
#define Joy_X A0
#define Joy_Y A1

// Arrays for button and joystick pins
int buttons[] = {A, B, C, D, E, F, Joy_BT};

// Create instances of the handlers
ButtonHandler buttonHandler(buttons);
JoystickHandler joystickHandler(Joy_X, Joy_Y);
LedHandler ledHandler(Led);

void setup() {
	Serial.begin(9600);

	pinMode(10, OUTPUT);
	digitalWrite(10, LOW);

	// Setup
	buttonHandler.setupButtons();
	joystickHandler.setupJoystick();
	ledHandler.setupLed();
}

void loop() {
	// Check button presses
	buttonHandler.checkButtonPress();

	// Read joystick values
	joystickHandler.readJoystickValues();

	// Write console output
	ledHandler.writeLedValues();
}

//message aparte classen maken (readmessage)
//eerst opvangen dan doorsturen naar de rest voor ontvangen van berichten

//extras treugsturen, vier ledjes of meer