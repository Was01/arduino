// C++ code
//

#define led 3
#define max 255
#define min 0
#define tmp 100
int i;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{   
   for(i=min;i<=max;i++)
  {
    analogWrite(led,i);
    delay(tmp);
  }
    for(i=max;i>=0;i--)
  {
    analogWrite(led,i);
    delay(tmp);
  }
  delay(5000);
}
