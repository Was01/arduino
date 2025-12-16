
# define led_verde 9
# define led_vermelho 8


void setup()
{
 
  Serial.begin(9600);
  Serial.println("Arduino Uno");
  pinMode(led_verde,OUTPUT);
  pinMode(led_vermelho,OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
   
    int num;
    while (Serial.available() > 0)
    {
      num = Serial.read();
      num=int(num);
      if(num%2==0){
        Serial.println("par");
        digitalWrite(led_verde,HIGH);
        digitalWrite(led_vermelho,LOW);
        
      }
      else{
        Serial.println("impar");
        digitalWrite(led_vermelho,HIGH);
        digitalWrite(led_verde,LOW);
      }
    }
  }
}
