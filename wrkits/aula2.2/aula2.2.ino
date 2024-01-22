
#define led 7

int atual_ms=0;
int ultimo_ms=0;

void setup() 
{
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);

}

void loop()
{
  atual_ms=millis();
  if((atual_ms-ultimo_ms)==500)
  {
    ultimo_ms=atual_ms;
    digitalWrite(led,!digitalRead(led));
    Serial.println(millis());
    
  }

}
