// C++ code
//
#  define velm1 3
# define  m1a 2
# define m1b 4
# define tmp 3000
int velmax=255;


void setup(){
  pinMode(velm1,OUTPUT);
    pinMode(m1a,OUTPUT);
    pinMode(m1b,OUTPUT);
  
 
    analogWrite(velm1,0);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);
  
      
   
}

void loop(){
    //M1
    analogWrite(velm1,velmax);
    digitalWrite(m1a,HIGH);
    digitalWrite(m1b,LOW);
    delay(tmp);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);
    delay(2000);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,HIGH);
    delay(tmp);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);
    delay(2000);
}
    
