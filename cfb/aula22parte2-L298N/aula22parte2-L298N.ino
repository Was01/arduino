# define  m1a 4
# define m1b 5
#define m2a 8
#define m2b 9





void setup(){
    pinMode(m1a,OUTPUT);
    pinMode(m1b,OUTPUT);
     pinMode(m2a,OUTPUT);
    pinMode(m2b,OUTPUT);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);  
     digitalWrite(m2a,LOW);
    digitalWrite(m2b,LOW);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}
void loop(){
    //M1
    
    digitalWrite(m1a,1);
    digitalWrite(m1b,0);
    digitalWrite(m2a,1);
    digitalWrite(m2b,0);
    delay(3000);
    digitalWrite(m1a,0);
    digitalWrite(m1b,0);
      digitalWrite(m2a,0);
    digitalWrite(m2b,0);
    delay(3000);
    digitalWrite(m1a,0);
    digitalWrite(m1b,1);
     digitalWrite(m2a,0);
    digitalWrite(m2b,1);
    delay(3000);
     digitalWrite(m1a,0);
    digitalWrite(m1b,0);
       digitalWrite(m2a,0);
    digitalWrite(m2b,0);
    delay(3000);
}
