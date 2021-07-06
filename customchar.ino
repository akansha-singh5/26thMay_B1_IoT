#include <LiquidCrystal.h>

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte a[8] = {
B00001,
B00011,
B00111,
B01110,
B11110,
B11111,
B11111,
B11111
};

byte b[8] = {
B11111,
B11111,
B11111,
B01110,
B01110,
B11111,
B11111,
B11111
};

byte c[8] = {
B10000,

B11000,
B11100,
B01110,
B01111,
B11111,
B11111,
B11111
};

byte d[8] = {
B11011,
B11000,
B11100,
B11110,
B01111,
B00111,
B00011,
B00001
};

byte e[8] = {
B11111,
B00000,
B00000,
B00000,
B00000,
B11111,
B11111,
B11111

};

byte f[8] = {
B11011,
B00011,
B00111,
B01111,
B11110,
B11100,
B11000,
B10000
};

void setup() {

lcd.begin(16, 2);

lcd.createChar(0, a);

lcd.createChar(1, b);

lcd.createChar(2, c);

lcd.createChar(3, d);

lcd.createChar(4, e);

lcd.createChar(5, f);

}

void loop() {

lcd.setCursor(2, 0);
lcd.write(byte(0));

lcd.setCursor(3, 0);
lcd.write(byte(1));

lcd.setCursor(4, 0);
lcd.write(byte(2));

lcd.setCursor(2, 1);
lcd.write(byte(3));

lcd.setCursor(3, 1);
lcd.write(byte(4));

lcd.setCursor(4, 1);
lcd.write(byte(5));

}
