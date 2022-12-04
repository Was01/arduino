// C++ code
//
// C++ code
//
#include <LiquidCrystal.h>


LiquidCrystal lcd(7,6,5,4,3,2);


void setup(){
  lcd.begin(16,2);
    lcd.clear();


}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("Washington");
  lcd.setCursor(1,1);
  lcd.print("Arduino");
  for(int i=0;i<6;i++){
    lcd.scrollDisplayRight();
    delay(1000);
  }
  for(int i=0;i<6;i++){
    lcd.scrollDisplayLeft();
    delay(1000);
    
  }
  
  delay(1000);
  lcd.noDisplay();
  lcd.display();
  delay(500);
 
  
}
