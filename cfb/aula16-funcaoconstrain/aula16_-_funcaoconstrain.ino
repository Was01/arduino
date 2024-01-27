# define pot A0
int val =0;


void setup()
{
  pinMode(pot,INPUT);
    Serial.begin(9600);

}

void loop(){
    val=constrain(analogRead(pot),500,800);
    Serial.println(val);
    delay(250);
  
}
