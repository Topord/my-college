#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <SimpleDHT.h>
#include <dht.h>
#include <LiquidCrystal.h>
#define DHTPIN A5
LiquidCrystal lcd(13, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHT11);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp:  Humidity:");
  dht.begin();
}
void loop() {
   float t = dht.readTemperature();
   float h = dht.readHumidity();
  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.setCursor(7,1);
  lcd.print(h); 
  delay(1000); 
}
