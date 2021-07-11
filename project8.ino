//Temperature sensor based smart fan

#include<LiquidCrystal.h>


LiquidCrystal lcd(12,11,5,4,3,2);
const int sensor=A1;
float temp;
void setup(){
  lcd.begin(16,2);
  
  pinMode(sensor,INPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop(){
  temp=analogRead(sensor);
  temp=temp*0.48828125;
  lcd.setCursor(0,0);
  lcd.print("Temperature");
  lcd.print(temp);
  delay(2000);
  

  if(temp<20)
  {
    analogWrite(9,0);
    digitalWrite(8,0);
    
    
   
    lcd.setCursor(0,1);
    lcd.print("fan off");
    delay(2000);
    
  }
  else if(20<temp && temp<24)
  {
    analogWrite(9,64);
    digitalWrite(8,0);
    
    
   lcd.setCursor(0,1);
    lcd.print("Fan speed:25%");
    delay(2000);
    
  }
  else if(24<temp && temp<28)
  {
    analogWrite(9,127);
    digitalWrite(8,0);
    
    //Serial.print("working>24");
    //delay(20);
    lcd.setCursor(0,1);
    lcd.print("Fan speed:50%");
    delay(2000);
    //lcd.clear();
  }
  else if(28<temp && temp<30)
  {
    analogWrite(9,191);
    digitalWrite(8,0);
    
    
    lcd.setCursor(0,1);
    lcd.print("Fan speed:75%");
    delay(2000);
    //lcd.clear();
  }
  else if(temp>30)
  {
    analogWrite(9,255);
    digitalWrite(8,0);
    
    lcd.setCursor(0,1);
    lcd.print("Fan speed:100%");
    delay(2000);
    
  }
}
