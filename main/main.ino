#include <FIR.h>
#define FILTERTAPS 5
FIR fir;

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

  float coef[FILTERTAPS] = { 0.021, 0.096, 0.146, 0.096, 0.021};
  fir.setCoefficients(coef);

    //declare gain coefficient to scale the output back to normal
  float gain = 0.38; // set to 1 and input unity to see what this needs to be
  fir.setGain(gain);
}

void loop() {
  // read the state of the pushbutton value:
  // wired differently than yesterday
  input1 = digitalRead(button2Pin);
  input2 = digitalRead(buttonPin);
  float output = 0; // output as a 0, but that doesn't really matter

  output = fir.process(input1);    // here we call the fir routine with the input. The value 'fir' spits out is stored in the output variable.
  
//  Serial.print(input1);
//  Serial.print(",");
//  Serial.print(input2);
//  Serial.print(",");
//  Serial.println(output);
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


