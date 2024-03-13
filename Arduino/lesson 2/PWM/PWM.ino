const int ledPin = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int a = 254;
  int ctl = 1;
  while(a > 0){
    analogWrite(ledPin, a);
    delay(100);
    if(ctl == 1){
      a = a - 10;
      if(a == 4){
        ctl = -1*ctl;
        delay(100);
        }
    }
    if(ctl == -1){
      a = a + 10;
      if(a == 254){
        ctl = -1*ctl;
        delay(100);
      }
    }

  }

}
