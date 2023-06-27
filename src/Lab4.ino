SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

void setup()
{
  pinMode(D5, OUTPUT);
  pinMode(D7, INPUT);
}

void loop()
{
  bool value = digitalRead(D7);
  if (value == true)
  {
    digitalWrite(D5, HIGH);
  }
  else
  {
    digitalWrite(D5, LOW);
  }
}