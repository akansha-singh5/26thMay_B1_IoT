#include <Keypad.h>
#include<LiquidCrystal.h>
#include<EEPROM.h>


LiquidCrystal lcd(13,12,11,10,9,8);

char password[4];
char pass[4],pass1[4];
int i=0;
char Key_pressed=0;

const byte ROWS = 4;
const byte COLS = 3; 

char Keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {3, 2, 1, 0}; 
byte colPins[COLS] = {4, 5, 6}; 

Keypad keypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  lcd.begin(16,2);
  
  
  
  
  lcd.setCursor(0,0);
  
  lcd.print("Enter Ur Passkey:");
  lcd.setCursor(0,1);
  for(int j=0;j<4;j++)
  EEPROM.write(j, j+49);
  for(int j=0;j<4;j++)
  pass[j]=EEPROM.read(j);
}
  
void loop()
{
  char key_pressed =keypad.getKey();
  if(key_pressed=='*')
  change();
  if (key_pressed)
  {
     password[i++]=key_pressed;
     lcd.print(key_pressed);
    
  }
  if(i==4)
  {
    delay(200);
    for(int j=0;j<4;j++)
    pass[j]=EEPROM.read(j);
    if(!(strncmp(password, pass,4)))
    {
      
      lcd.clear();
      lcd.print("Passkey Accepted");
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("* Change Passkey");
      delay(2000);
      //lcd.clear();
      //lcd.print("Enter Passkey:");
      //lcd.setCursor(0,1);
      i=0;
      
    }
    
    else
    {
      
      lcd.clear();
      lcd.print("Access Denied...");
      lcd.setCursor(0,1);
      lcd.print("*.Change Passkey");
      delay(2000);
      lcd.clear();
      lcd.print("Enter Passkey:");
      lcd.setCursor(0,1);
      i=0;
      
    }
  }
}

void change()
{
  int j=0;
  lcd.clear();
  lcd.print("Current Passk");
  lcd.setCursor(0,1);
  while(j<4)
  {
    char key=keypad.getKey();
    if(key)
    {
      pass1[j++]=key;
      lcd.print(key);
      
    }
    key=0;
  }
  delay(500);
  
  if((strncmp(pass1, pass, 4)))
  {
    lcd.clear();
    lcd.print("Wrong Passkey...");
    
    delay(1000);
  }
  else
  {
    j=0;
    
  lcd.clear();
  lcd.print("New Passk:");
  lcd.setCursor(0,1);
  while(j<4)
  {
    char key=keypad.getKey();
    if(key)
    {
      pass[j]=key;
      lcd.print(key);
      EEPROM.write(j,key);
      j++;
      
    }
  }
  lcd.print("  Done......");
  delay(1000);
  }
  lcd.clear();
  lcd.print("Enter Ur Passk:");
  lcd.setCursor(0,1);
  char key_pressed=0;
}
