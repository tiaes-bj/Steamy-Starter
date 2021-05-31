#include <HCSR04.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define led_green 12

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
HCSR04 hc(7,8);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{   
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
 pinMode(led_green , OUTPUT); 
 }

void loop()
{ 
 int distance =  hc.dist();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("La distance est:");
 lcd.setCursor(0,1);
 lcd.print(distance);
 lcd.print(" cm.");
 
 int delay_value = map(distance, 0 , 30 , 0 , 1000);
 digitalWrite(led_green,HIGH);
 delay(delay_value);
distance =  hc.dist();
 delay_value = map(distance, 0 , 30 , 0 , 1000);
 digitalWrite(led_green,LOW);
 delay(delay_value);

}
