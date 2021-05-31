//assign buzzer as pin 9
#define buzzer 9
 
void setup()
{
  //set buzzer as output
  pinMode(buzzer, OUTPUT);
}
 
void loop()
{ //turn on buzzer(set logic level high)
  digitalWrite(buzzer, HIGH);
  //wait 1s
  delay(1000);
  //turn off buzzer(set logic level low)
  digitalWrite(buzzer, LOW);
  //wait 1s
  delay(1000);
}
