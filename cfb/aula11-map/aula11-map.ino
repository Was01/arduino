// C++ code
//

# define led 3
# define pot A0  

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pot,INPUT);
}

void loop()
{
  //Analógico = 0 a 1023
  //PWM = 0 a 255
  analogWrite(led,map(analogRead(pot),0,1023,0,255));
}
