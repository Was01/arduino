#define led_vermelho 7
#define led_verde 6

void setup()
{
 pinMode(led_vermelho,OUTPUT);
  pinMode(led_verde,OUTPUT);
  Serial.begin(9600);

  digitalWrite(led_vermelho,LOW);
  digitalWrite(led_verde,LOW);
}


void loop()
{
  if (Serial.available() > 0)
  {
    String numero = "";
    char num;
    int n;
    int divisor,primo=1;
    
    while (Serial.available() > 0)
    {
      num = Serial.read();
      if (num != '\r' && num != '\n' && isAscii(num))
      {
        numero.concat(num);
      }
      delay(2);
    }
    Serial.print("\nNumero: ");
    Serial.println(numero);
    Serial.flush();
    n=numero.toInt();
    for(divisor=2;divisor<n;divisor++){
      if(n%divisor==0)
        primo=0;
    }
    if(primo==1 && n!=1){
      Serial.print("Numero primo");
      digitalWrite(led_vermelho,LOW);
       digitalWrite(led_verde,HIGH);
    }
    else{
        Serial.print("Nao e numero primo");
         digitalWrite(led_vermelho,HIGH);
       digitalWrite(led_verde,LOW);
      }
  }
}
