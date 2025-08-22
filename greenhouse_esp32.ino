#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN A2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int soilA0 = A5;
int buzz = 13;
int sensorThres = 400;

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(soilA0, INPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
   dht.begin();
}
void loop() {
   int analogSensor = analogRead(soilA0);
     float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
     Serial.print("Pin A0: ");
  Serial.println(analogSensor);
    lcd.setCursor(0, 0);
  lcd.print("moisture     ");
  lcd.println(analogSensor);
  delay(2000);
    lcd.setCursor(1,0);
  lcd.print("Humidity:  ");
  lcd.println(humidity);
  lcd.setCursor(0,1);
  lcd.print("Temp:     ");
  lcd.println(temperature);
  delay(2000);
  if(analogSensor>200)
  {
    digitalWrite(buzz,HIGH);
   delay(2000);
  }
  else
  {
    digitalWrite(buzz,LOW);
  }
}
