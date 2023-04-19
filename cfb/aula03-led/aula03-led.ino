int pled=2;



        
    
void setup()
{
  pinMode(pled,OUTPUT);
}

void loop()
{
  digitalWrite(pled,HIGH);
  delay(8000);
  digitalWrite(pled,LOW);
  delay(5000);

}
