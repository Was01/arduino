int adc=0;
int pwm=0;

void setup() {
 Serial.begin(9600);
  pinMode(A0,INPUT);

}

void loop()
{
  adc=analogRead(A0);
  pwm=map(adc,0,1023,0,255);
  Serial.print(adc);
  Serial.print(" | ");
  Serial.println(pwm);
  delay(600);
}
