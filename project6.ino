//pc controlled door lock

#include<LiquidCrystal.h>
#include<Servo.h>
Servo motor;
LiquidCrystal lcd(12,11,5,4,3,2);
String str;
int p;
void setup() {
 Serial.begin(9600);
 lcd.begin(16,2);
 motor.attach(9);
 lcd.print("ENTER PASSWORD:");

}

void loop() {
  if(Serial.available()==1)
  {
    str=Serial.readString();
    Serial.print(str);
  


    if(str=="CONFIDENTIAL")
    {
      motor.write(180);
      lcd.setCursor(0,1);
      lcd.print("DOOR OPENED");
      delay(2000);
      lcd.clear();
    }
    else
    {
      lcd.setCursor(0,1);
      lcd.print("ACCESS DENIED");
      delay(2000);
      lcd.clear();
    }
  }

}
