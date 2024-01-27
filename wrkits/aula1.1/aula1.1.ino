
/* Arduino para iniciantes Aula01 
  Autor: Washington Fernandes de Barros
  Data: 31/12/2023
*/

//--Função de Congiguração

void setup() 
{
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(5,INPUT_PULLUP);
 

}

void loop() 
{
  if(!digitalRead(5))
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(500);
   
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    delay(500);
  }
  else
  {
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
  }
  

}
