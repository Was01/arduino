// C++ code
//

# include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  lcd.begin(16,2);
  
}

void loop()
{
  int idade =44;
  lcd.setCursor(2,0);
  lcd.print("Washington");
  lcd.setCursor(2,1);
  lcd.print("Idade: ");
  lcd.print(idade);
  lcd.print(" anos");
}
