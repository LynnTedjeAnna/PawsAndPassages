#include <Arduino.h>
#include "buttonHandler.h"
#include "joystickHandler.h"
#include "dimHandler.h"
#include "messageHandler.h"

// Define pin constants
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

// Arrays for button and joystick pins
int buttons[] = {A, B, C, D, E, F, Joy_BT};

// Create instances of the handlers
MessageHandler messageHandler('#', '%');
ButtonHandler buttonHandler(buttons, messageHandler);
JoystickHandler joystickHandler(Joy_X, Joy_Y, messageHandler);
DimHandler vibrator(Vib, "T");

void setup() {
	Serial.begin(9600);

    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);

    pinMode(L_Sensor, INPUT);

	// Setup
	buttonHandler.setupButtons();
	joystickHandler.setupJoystick();
	vibrator.setupPin();
}

void loop() {
    String message = messageHandler.receiveMessage();

	// Check button presses
	buttonHandler.checkButtonPress();

	// Read joystick values
	joystickHandler.readJoystickValues();

	// Write console output
    if (vibrator.getKey() == message) {
        vibrator.turnOn();
    }
    vibrator.update();

    Serial.println(analogRead(L_Sensor));
}

//extras treugsturen, vier ledjes of meer

//licht sersor,
// actuatoren servo of ledje laten pulsen (moet er echt bij)
//actuatoren!!
//paramaters
//led aan kies je welke het is met cijfer. vanaf applicatie.
//trill vibrator toevoegen kan in arduino/joystick