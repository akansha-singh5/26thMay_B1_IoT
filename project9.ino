#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int slot1=8,slot2=7,slot3=6;
int entry=9;

void setup() {
  lcd.begin(16,2);
  pinMode(slot1,INPUT);
  pinMode(slot2,INPUT);
  pinMode(slot3,INPUT);
  pinMode(entry,INPUT);

}

void loop() {
  int s1,s2,s3,e;
  s1=digitalRead(slot1);
  s2=digitalRead(slot2);
  s3=digitalRead(slot3);
  e=digitalRead(entry);

  if(e==1){

  if(s1==0)
  {
    
    if(s2==0 && s3==0)
    {
      
      lcd.setCursor(0,0);
      lcd.print("vacant:1 2 3");
      
    }
    if(s2==1 && s3==0)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("vacant:1 3");
      delay(2000);
    }
    if(s2==0 && s3==1)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("vacant:1 2");
      delay(2000);
    }
    if(s2==1 && s3==1)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("vacant:1");
      delay(2000);
    }
  }
  if(s1==1)
  {
    
    if(s2==0 && s3==0)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("vacant:2 3");
      delay(2000);
    }
    if(s2==1 & s3==0)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("vacant:3");
      delay(2000);
    }
    if(s2==0 && s3==1)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("vacant:2");
      delay(2000);
    }
    if(s2==1 && s3==1)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("vacant:None");
      delay(2000);
    }
  }
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Parking counter");
    delay(1000);
    lcd.clear();
  }
}
