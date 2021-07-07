//digital notice display

#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
byte ch;
int col=0;
int row=0;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.clear();

}

void loop() {
  
  if(Serial.available()){
    char ch=Serial.read();
    Serial.write(ch);
    Serial.println();
    lcd.setCursor(col,row);
    lcd.write(ch);
    col++;

    if (col>15){
      row++;
      col=0;
      lcd.write(ch);
    }
    if (row>1){
      lcd.clear();
      row=0;
      col=0;
      lcd.setCursor(row,col);
    }
  }

}
