#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,4,5,6,7);

void setup() {
  pinMode(2,INPUT);
  lcd.begin(16,2);
  
  
  
  
  // put your setup code here, to run once:

}

void loop(){ 
  int x;
  x=digitalRead(2);
  if(x==1){
    lcd.setCursor(3,0);
    lcd.print("WISHING YOU");
    lcd.setCursor(4,1);
    lcd.print("GOOD LUCK");
    delay(1000);
    lcd.clear();
  }
  
  
  
  
  
 
  
  // put your main code here, to run repeatedly:

}
