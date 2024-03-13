
char invalue;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  int i = 0;
  if(Serial.available()>0){
    invalue=Serial.read();
    i = invalue;
  }
  while(i > 0){
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000); 
    i = i - 1;
  }
  i = 0;
}
