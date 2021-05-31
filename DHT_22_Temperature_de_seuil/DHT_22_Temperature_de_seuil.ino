
#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define led_green 12
#define led_red 11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DHT 22 test!...");
  dht.begin();
  delay(2000);
  lcd.clear();
  pinMode(led_green , OUTPUT);
  pinMode(led_red , OUTPUT);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);  
}
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Le capteur a un problème.");
  lcd.setCursor(0,1);
  lcd.print("probleme.");
  return;
  }
 if (t<40 ){
   lcd.setCursor(0,0);
   lcd.print(F("Temperature "));
   lcd.print(t);
   lcd.setCursor(0,1);
   lcd.print(F("inferieur a 40"));
   digitalWrite(led_green, HIGH);
   digitalWrite(led_red, LOW);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print(F("Temperature "));
    lcd.print(t);
    lcd.setCursor(0,1);
    lcd.print(F("superieur a 40"));
    digitalWrite(led_green,LOW);
    digitalWrite(led_red,HIGH);
  }
}
