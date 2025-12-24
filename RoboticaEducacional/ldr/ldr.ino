// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop()
{
  int ldr=analogRead(A0);
  Serial.println(ldr);
  delay(500);
  if(ldr<=300)
  {
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
}
