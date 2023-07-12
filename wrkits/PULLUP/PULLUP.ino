int bot=2;
bool lerbot;

void setup() {
 
  Serial.begin(9600);
  pinMode(bot, INPUT_PULLUP);

}

void loop() {
 lerbot=!digitalRead(bot);
 Serial.println(lerbot);

  delay(200); // this speeds up the simulation
}
