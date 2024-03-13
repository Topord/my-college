#include "DHT.h"
#include <LiquidCrystal.h>
#define D 9
const int rs = 12, en = 13, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(D,DHT11);

void setup(){
  lcd.begin(16,2);
  dht.begin();
}

void loop(){
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("tem: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("hum: ");
  lcd.print(h);
  lcd.print(" %RH");
  delay(2000);
}
