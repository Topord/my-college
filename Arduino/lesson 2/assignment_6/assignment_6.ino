const int ledPin = 3; 
const int buttonPin = 2;
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;
int b = 100; 
void setup()
{
  pinMode(ledPin, OUTPUT);//定义小灯接口为输出接口
  pinMode(buttonPin, INPUT);
}


void loop() {
  int flag = 0;
  int buttonState = 0;
  int a = 254;
  int ctl = 1;
  int c = 2;
  buttonState = digitalRead(buttonPin);
  
   delay(1500);
      digitalWrite(ledPin, HIGH);  //S
      delay(1500);
      digitalWrite(ledPin, LOW);
      delay(1500);
      digitalWrite(ledPin, HIGH);
      delay(1500);
      digitalWrite(ledPin, LOW);
      delay(1500);
      digitalWrite(ledPin, HIGH);
      delay(1500);
      digitalWrite(ledPin, LOW);
      delay(1500);
      digitalWrite(ledPin, HIGH);  //O
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
      digitalWrite(ledPin, HIGH);  //S
      delay(1500);
      digitalWrite(ledPin, LOW);
      delay(1500);
      digitalWrite(ledPin, HIGH);
      delay(1500);                                         //2.5
      digitalWrite(ledPin, LOW);
      delay(1500);
      digitalWrite(ledPin, HIGH);
      delay(1500);
      digitalWrite(ledPin, LOW);
      delay(2500);

      while(c > 0){
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
                break;
              }
            }
    
      }
      c = c - 1;
     }
  delay(1500);
  while(b > 0){
      // read the value from the sensor:
      sensorValue = analogRead(sensorPin);
      // turn the ledPin on
      digitalWrite(ledPin, HIGH);
      // stop the program for <sensorVlue> milliseconds:
      delay(sensorValue);
      // turn the ledPin off:
      digitalWrite(ledPin, LOW);
      // stop the program for for <sensorValue> milliseconds:
      delay(sensorValue);

  }
  


   /* buttonState = digitalRead(buttonPin);
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == LOW) {
      // turn LED on:
      digitalWrite(ledPin, HIGH);
    } else {
      // turn LED off:
      digitalWrite(ledPin, LOW);
    }
*/
}
