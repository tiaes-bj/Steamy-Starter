
#define potentiometre A1

#define led_green 12

void setup(){
 pinMode(led_green , OUTPUT);  
}

void loop(){
int pot_value=analogRead(potentiometre ); // Incoming analog signal read and appointed    //sensor

int delay_value = map(pot_value, 0 , 1023 , 0 , 2000);

digitalWrite(led_green,HIGH);
delay(delay_value);
digitalWrite(led_green,LOW);
delay(delay_value);

}
