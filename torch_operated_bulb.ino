//Torch operated bulb


void setup() {
 Serial.begin(9600);
 pinMode(10,OUTPUT);

}

void loop() {
  int sensor=analogRead(A0);
  Serial.println(sensor);


  if(sensor<15)
  {
    digitalWrite(10,HIGH);
  }
  else
  {
    digitalWrite(10,LOW);
  }
  delay(10);
}
