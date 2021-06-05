void setup() {
  pinMode(9,OUTPUT);
 
  // put your setup code here, to run once:

}

void loop() {
  noTone(9);
  delay(2000);
  tone(9,1000);
  delay(1000);
  tone(9,2000);
  delay(5000);
  tone(9,3000);
  delay(10000);
  tone(9,4000);
  delay(15000);
  noTone(9);
  delay(1000);
  
  // put your main code here, to run repeatedly:

}
