#define led_green 12

void setup(){
  //set leds as output
  pinMode(led_green , OUTPUT);
   
}

void loop(){
  digitalWrite(led_green, HIGH);
  delay(500);
  //wait 500 ms

  digitalWrite(led_green,LOW);
  delay(500);
  //wait 500 ms 
}
