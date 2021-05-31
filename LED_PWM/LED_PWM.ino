#define led_red 11

void setup(){
  //set leds as output
  pinMode(led_red , OUTPUT);
   
}

void loop(){
  for(int i=256;i>-1;i-=25)
{
  analogWrite(led_red,i);
   delay(1000);
  //wait 1000 ms
}
 
for(int i=0;i<256;i+=25)
{
  analogWrite(led_red,i);
   delay(1000);
  //wait 1000 ms
}

 }
