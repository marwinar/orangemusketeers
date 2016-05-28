// button press > 2s
int previousInput1 = -1;
unsigned long curTime;
int diff = 0;
int count = 0;
int flickCount = 0;

int detectSignal(int input1, int input2) {
 
  diff = input1 - previousInput1;
  previousInput1 = input1;
  count++;

  if (diff == 1) {
    // start counting
    count = 0;
    Serial.println("flick?");
    return ACTIVE;
  }

  if (diff == -1) {
    if (count > 2 && count < 15) {
      Serial.print("flick!! ");
      flickCount++;
      if (flickCount == 2) {
        Serial.println("***********Yay, start moving!*************");
        flickCount = 0;
      }
      Serial.println(flickCount);
      return INACTIVE;     
    } else {
      flickCount = 0;
      Serial.println("nope, sorry..");      
    }
    count = 0;
  }
}

