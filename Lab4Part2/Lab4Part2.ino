SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

int ledPin = D5; //defining variables
int ButtonPin = D7;

byte lastButtonState = LOW; //define as a byte variable and sets their initial values as low(meaning initally its not being pressed)
byte ledState = LOW;

unsigned long debounceDuration = 50; // millis , debouncing adds a delay between button presses to make sure no glitches, the time sets the amount of time for the delay
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) { //This line checks if the debounce duration has passed since the button state last changed. It is there to ensure that button state changes are not registered too quickly.
    byte ButtonState = digitalRead(ButtonPin); // This line reads the current state of the button. It is there to get the current state of the button.
    if (ButtonState != lastButtonState) {
      lastTimeButtonStateChanged = millis(); //This line updates the time that the state of the button changed. It is there to ensure that debounceDuration is adhered to between button presses
      lastButtonState = ButtonState;
      if (ButtonState == LOW) {
        ledState = (ledState == HIGH) ? LOW: HIGH; //This line toggles the state of the LED. It is there to ensure that the LED is turned on if it was previously off, and turned off if it was previously on.
        digitalWrite(ledPin, ledState); //This line updates the state of the LED. It is there to turn the LED on or off based on the current state of the LED
      }
    }
  }
}