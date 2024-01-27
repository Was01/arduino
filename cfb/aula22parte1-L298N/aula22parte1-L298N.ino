// C++ code
//

# define  m1a 4
# define m1b 5




void setup(){
    pinMode(m1a,OUTPUT);
    pinMode(m1b,OUTPUT);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
}
void loop(){
    //M1
    
    digitalWrite(m1a,1);
    digitalWrite(m1b,0);
    delay(3000);
    digitalWrite(m1a,0);
    digitalWrite(m1b,0);
    delay(3000);
    digitalWrite(m1a,0);
    digitalWrite(m1b,1);
    delay(3000);
     digitalWrite(m1a,0);
    digitalWrite(m1b,0);
    delay(3000);
}
