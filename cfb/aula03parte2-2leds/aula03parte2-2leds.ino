int led_vermelho=2;
int led_verde=3;


        
    
void setup()
{
  pinMode(led_vermelho,OUTPUT);
  pinMode(led_verde,OUTPUT);
}

void loop()
{
  digitalWrite(led_vermelho,HIGH);
  digitalWrite(led_verde,LOW);
  delay(200);
  digitalWrite(led_vermelho,LOW);
  digitalWrite(led_verde,HIGH);
  
  delay(200);

}
