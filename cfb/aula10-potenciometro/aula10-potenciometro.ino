# define an0 A0
void setup()
{
  pinMode(an0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(an0));
  delay(200);
}
