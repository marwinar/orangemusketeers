// button press > 2s
int previousState = -1;
unsigned long curTime;

int detectSignal(int input1, int input2) {
  curTime = millis();

  if (input1 != previousState) {
    previousState = input1;
    return input1 == HIGH ? ACTIVE : INACTIVE;
  }

}

