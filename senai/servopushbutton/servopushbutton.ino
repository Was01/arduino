# include <Servo.h>
# define btn 11

Servo s;

void setup()
{
  pinMode(btn, INPUT_PULLUP);
  s.attach(3);
}


void loop()
{
  if(!digitalRead(btn)){
    for(int angulo=0;angulo<=180;angulo++){
      s.write(angulo);
        delay(10);
    }
 
     for(int angulo=180;angulo>=0;angulo--){
      s.write(angulo);
        delay(10);
    }
  }
 
}
