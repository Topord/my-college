int ledPin = 13; // 设定控制 LED 的数字 IO 脚
char w ; 
char st1[19];
int sensorPin = A0; 
int sensorValue;         //表示接收的值

void setup()
{
pinMode(ledPin, OUTPUT) ; // 设定数字 IO 口 的模式， OUTPUT 为输出
Serial.begin(38400) ; 
}

void loop()
{
  float num = 0.00;
  sensorValue = analogRead(sensorPin);
  num = sensorValue*100.00/1023.00;
    
if (Serial.available()>0)  // 如果
  {
    w=Serial.read();
    st1[0]=0xf8;
    st1[1]=0x04;
    st1[2]=0x80;   //port-D
    st1[3]=num;
    st1[4]=0x88;   //port-C
    st1[5]=51;
    st1[6]=0x90;   //port-B
    st1[7]=39;
    st1[8]=0x98;   //button
    st1[9]=1;
    st1[10]=0xa0;   //port-A
    st1[11]=15; 
    st1[12]=0xa8;   //light
    st1[13]=15; 
    st1[14]=0xb0;   //sound
    st1[15]=15; 
    st1[16]=0xb8;   //slider
    st1[17]=15;     
    if(w==1)
  //Serial.print(0xF8);
      Serial.print(st1);
  } 
}
