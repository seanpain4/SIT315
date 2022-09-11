int buttonState = 0;
int lastButtonState = 0;

void setup()
{
  pinMode(4, INPUT);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(4);
  // compare the button state
  if (buttonState != lastButtonState) {
    // if changed, we change output
    if (buttonState == HIGH) {
      Serial.println("on");
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      Serial.println("off");
      digitalWrite(LED_BUILTIN, LOW);
    }
    delay(5); // wait 5ms
  }
  // save current state to compare
  lastButtonState = buttonState;
}