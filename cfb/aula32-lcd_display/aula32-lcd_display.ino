// C++ code
//
#include <LiquidCrystal.h>


LiquidCrystal lcd(7,6,5,4,3,2);


void setup(){
  lcd.begin(16,2);
    lcd.clear();


}

void loop(){
  lcd.setCursor(3,0);
  lcd.print("Washington");
  lcd.setCursor(5,1);
  lcd.print("Arduino");
  delay(300);
  lcd.clear();
  delay(300);
  lcd.setCursor(3,0);
  lcd.print("Washington");
  lcd.setCursor(5,1);
  lcd.print("Arduino");
  delay(300);
  
}
