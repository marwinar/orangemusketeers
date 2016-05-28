#include <FiniteStateMachine.h>

const int buttonPin = 2;     // the number of the pushbutton pin
const int button2Pin = 3;
const int ledPin =  13;      // the number of the LED pin
const int interval = 15;

int input1 = 0;         // variable for reading the pushbutton status
int input2 = 0;
const int ACTIVE = 0, INACTIVE = 1;
unsigned long lastChanged;
int minInterval = 1000; // minimal time in milliseconds
boolean waitedLongEnough = false;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(button2Pin, INPUT);
  lastChanged = millis();
}

void loop() {
  // read the state of the pushbutton value:
  input1 = digitalRead(buttonPin);
  input2 = digitalRead(button2Pin);
  Serial.print(input1);
  Serial.print(",");
  Serial.println(input2);
  int signal = detectSignal(input1, input2);

  if (signal == ACTIVE) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  delay(interval);
}


