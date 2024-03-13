int sensorPin = A0;    //电压:0--5V; 0--1023; 即1刻度 ==>  0.04V
int sensorValue;
float voltage ;
void setup() {
  Serial.begin(9600);
}


void loop() {                       //   5/1023=v/s;   v=5s/1023

float voltage ;
  
  sensorValue = analogRead(sensorPin);   //读取电压值，0-->1023
  voltage = sensorValue/204.6;

  Serial.println(voltage);
  delay(100);
}
