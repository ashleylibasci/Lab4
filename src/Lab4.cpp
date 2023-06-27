/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/ashleylibasci/IoTFolderLabs/Lab4/src/Lab4.ino"
void setup();
void loop();
#line 1 "/Users/ashleylibasci/IoTFolderLabs/Lab4/src/Lab4.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

void setup() {
pinMode(D5, OUTPUT);
pinMode(D7, INPUT);
}

void loop() { 
  bool value = digitalRead(D7);
if (value == true) {
  digitalWrite(D5, HIGH);
} else {
  digitalWrite(D5, LOW);
}
}