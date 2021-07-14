#include<SoftwareSerial.h>
SoftwareSerial ser(12,13);
const byte fan=9;


void setup() {
  ser.begin(9600);
  Serial.begin(9600);
  pinMode(fan,OUTPUT);
  pinMode(8,OUTPUT);

}

void loop() {
  if (Serial.available()){
    String val=Serial.readString();
    ser.println(val);
    if (val=="ON"){
      digitalWrite(fan,1);
      digitalWrite(8,0);
    }
    if(val=="OFF"){
      digitalWrite(fan,0);
      digitalWrite(8,0);
    }
    if (val=="on"){
      digitalWrite(fan,1);
      digitalWrite(8,0);
  }
  if(val=="off"){
      digitalWrite(fan,0);
      digitalWrite(8,0);

}
  }
  }
