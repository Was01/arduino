
#define bt1 8
#define bt2 9

#define out1 3
#define out2 4

void read_keyb();

void setup() {

  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  
  pinMode(bt1,INPUT_PULLUP);
  pinMode(bt2,INPUT_PULLUP);

 digitalWrite(out1,LOW);
 digitalWrite(out2,LOW);
}

void loop() {
  read_keyb();

}

void read_keyb()
{
  static char flag1=0;
  static char flag2=0;
  if(!digitalRead(bt1)) flag1=1;
  if( digitalRead(bt1)&&flag1){
    flag1=0;
    digitalWrite(out1,!digitalRead(out1));
    delay(130);
  }

  if(!digitalRead(bt2)) flag2=1;
  if( digitalRead(bt2)&&flag2){
    flag2=0;
    digitalWrite(out2,!digitalRead(out2));
    delay(130);
  }
  
 }
