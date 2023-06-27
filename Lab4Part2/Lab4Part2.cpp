/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/ashleylibasci/IoTFolderLabs/Lab4/Lab4Part2/Lab4Part2.ino"
void setup();
void loop();
#line 1 "/Users/ashleylibasci/IoTFolderLabs/Lab4/Lab4Part2/Lab4Part2.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

int ledPin = D5;
int ButtonPin = D7;

byte lastButtonState = LOW;
byte ledState = LOW;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte ButtonState = digitalRead(ButtonPin);
    if (ButtonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = ButtonState;
      if (ButtonState == LOW) {
        ledState = (ledState == HIGH) ? LOW: HIGH;
        digitalWrite(ledPin, ledState);
      }
    }
  }
}