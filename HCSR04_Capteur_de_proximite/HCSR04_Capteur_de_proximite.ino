#include <HCSR04.h>
#define led_red 11
#define buzzer 9  
HCSR04 hc(7,8);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{   
 pinMode(led_red , OUTPUT); 
 pinMode(buzzer , OUTPUT); 
 }
void loop()
{ 
 if (hc.dist()<10) {
  digitalWrite(led_red,HIGH);
  tone(buzzer, 1000, 10);
 }
 else {
  digitalWrite(led_red,LOW);
  digitalWrite(buzzer,LOW);
 } 
}
