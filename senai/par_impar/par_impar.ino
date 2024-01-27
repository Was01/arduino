

void setup()
{
 
  Serial.begin(9600);
  Serial.println("Arduino Uno");
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
      }
      else{
        Serial.println("ímpar");
      }
    }
  }
}
