const int buttonPin = 2;
const int ledPin =  6;

volatile int buttonState = 0;

void setup() {
  Serial.begin(9600);
  // Initialise the inbuilt LED
  pinMode(LED_BUILTIN, OUTPUT);
  // Initialise the LED pin
  pinMode(ledPin, OUTPUT);
  // Initialise the pushbutton pin
  pinMode(buttonPin, INPUT);
  // Attach an interrupt
  attachInterrupt(digitalPinToInterrupt(buttonPin), pin_ISR, CHANGE);
}

void loop() {
  // Flash inbuilt LED
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Onboard LED on");
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Onboard LED off");
  delay(1000);
}

void pin_ISR() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);
  Serial.println("Button Press");
}
