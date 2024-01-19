#include <Arduino.h>
#include "buttonHandler.h"
#include "joystickHandler.h"
#include "dimHandler.h"
#include "messageHandler.h"
#include "lightSensorHandler.h"

#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define Joy_BT 8
#define Vib 11
#define Joy_X A0
#define Joy_Y A1
#define L_Sensor A2
#define LED_Yellow A3
#define LED_White A5

// Arrays for button and joystick pins
int buttons[] = {A, B, C, D, E, F, Joy_BT};

// Create instances of the handlers
MessageHandler messageHandler('#', '%');
ButtonHandler buttonHandler(buttons, messageHandler);
JoystickHandler joystickHandler(Joy_X, Joy_Y, messageHandler);
DimHandler vibrator(Vib, "T");
DimHandler yellow(LED_Yellow, "Y");
DimHandler white(LED_White, "W");
LightsensorHandler lightsensorHandler (L_Sensor, messageHandler);

void setup() {
	Serial.begin(9600);

    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(A4, OUTPUT);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(A4, LOW);

    pinMode(L_Sensor, INPUT);

	// Setup
	buttonHandler.setupButtons();
	joystickHandler.setupJoystick();
	vibrator.setupPin();
    lightsensorHandler.setupLightsensor();
}

void loop() {
    String message = messageHandler.receiveMessage();

	// Check button presses
	buttonHandler.checkButtonPress();

	// Read joystick values
	//joystickHandler.readJoystickValues();

	//get position joystick values
	joystickHandler.getJoyPosition();

	JoyResult result = joystickHandler.getJoyPosition();
	String messageToSend = "";
	if (result == Left) {
		messageToSend = "L";
	} else if (result == Right) {
		messageToSend = "R";
	}
	if (messageToSend != "") {
		messageHandler.sendMessage(messageToSend);
		messageToSend = "";
	}
	messageToSend = "";
	if (result == Up) {
		messageToSend = "U";
	} else if (result == Down) {
		messageToSend = "D";
	}
	if (messageToSend != "") {
		messageHandler.sendMessage(messageToSend);
	}

	// Write console output
	if (vibrator.getKey() == message) {
		vibrator.turnOn();
	}
	else if (yellow.getKey() == message) {
		yellow.turnOn();
	}
	else if (white.getKey() == message) {
		white.turnOn();
	}
	else if (message != "") {
		// send error message
		messageHandler.sendMessage("E");
	}
	vibrator.update();
	yellow.update();
	white.update();

    //Read Lightsensor values
    //lightsensorHandler.readLightsensorValues();

	// due to timing issues delay is added to allow vibrator to work
	delayMicroseconds(10);
}