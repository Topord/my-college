int ledPin = 7; //定义数字10 接口

void setup()
{
pinMode(ledPin, OUTPUT);//定义小灯接口为输出接口
}

void loop() {
  while(1){
    digitalWrite(ledPin, HIGH);  //S
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);  //O
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
    digitalWrite(ledPin, HIGH);  //S
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1500);
    
    }
}
