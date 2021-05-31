
#include <HCSR04.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


HCSR04 hc(7,8);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{   
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
 }

void loop()
{ 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("La distance est:");
  lcd.setCursor(0,1);
  lcd.print(hc.dist());
  lcd.print(" cm.");
  delay(1000);
}
