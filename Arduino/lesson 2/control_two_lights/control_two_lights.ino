/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 7;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int Pin = 13;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void light1()
{
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(1023-sensorValue);
  digitalWrite(ledPin, LOW);
  delay(1023-sensorValue);
 }
 
void light2()
{
  sensorValue = analogRead(sensorPin);
  digitalWrite(Pin, HIGH);
  delay(sensorValue);
  digitalWrite(Pin, LOW);
  delay(sensorValue);
 }
void loop() {
  if(sensorValue > 800){
    light1();
    }
  else if(sensorValue == 0){
    light2();
    }
  else if(0<sensorValue<800){
    light1();
    light2(); 
    }
}
