int LED[]={2,3,4,5,6,7,8,9};
void setup() {
 
  for(int i=0;i<8;i++){
    pinMode(LED[i],OUTPUT);
  }

}

void loop() {
 for(int i=0;i<5;i++)
 {
  pattern1();
 }
 for (int i=0;i<5;i++){
  pattern2();
 }
 for(int i=0;i<5;i++){
  pattern3();
 }
}
void pattern1(){
  for(int i=0;i<8;i++){
    digitalWrite(LED[i],HIGH);
    delay(10);
  }
}
void pattern2(){
  for(int i=0;i<4;i++){
    digitalWrite(LED[i],HIGH);
    digitalWrite(LED[8-1-i],HIGH);
    delay(100);
    digitalWrite(LED[i],LOW);
    digitalWrite(LED[8-1-i],LOW);
  }
}
void pattern3(){
  for(int i=3;i>=0;i--){
    digitalWrite(LED[i],HIGH);
    digitalWrite(LED[8-1-i],HIGH);
    delay(100);
    digitalWrite(LED[i],LOW);
    digitalWrite(LED[8-1-i],LOW);
  }
}
