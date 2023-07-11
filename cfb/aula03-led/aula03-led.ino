int pled=2;



        
    
void setup()
{
  pinMode(pled,OUTPUT);
  digitalWrite(pled,LOW);
}

void loop()
{
  digitalWrite(pled,!digitalRead(pled));
  delay(500);
}
