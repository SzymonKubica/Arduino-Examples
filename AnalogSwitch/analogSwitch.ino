int Xpin = A0;
int Ypin = A1;
int Spin = A2;
int Xval;
int Yval;
int Sval;
int dt =20;
int led1Pin = 2;
int led2Pin = 3;
int led3Pin = 4;
int led4Pin = 5;
int led5Pin = 9;
int led6Pin = 10;
int led7Pin = 11;
int led8Pin = 12;

void setup(){
    pinMode(Xpin, INPUT);
    pinMode(Ypin, INPUT);
    pinMode(Spin, INPUT);

    pinMode(led1Pin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
    pinMode(led3Pin, OUTPUT);
    pinMode(led4Pin, OUTPUT);
    pinMode(led5Pin, OUTPUT);
    pinMode(led6Pin, OUTPUT);
    pinMode(led7Pin, OUTPUT);
    pinMode(led8Pin, OUTPUT);
    Serial.begin(115200);

    digitalWrite(Spin, HIGH);
}
void loop(){
   Xval = analogRead(Xpin); 
   Yval = analogRead(Ypin); 
   Sval = digitalRead(Spin); 
   delay(dt);
   Serial.print("X value = ");
   Serial.print(Xval);
   Serial.print(" Y value = ");
   Serial.print(Yval);
   Serial.print(" Switch state is ");
   Serial.println(Sval);
  /* if(Xval ==504 && (Yval ==497 || Yval ==498)){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, LOW);
   }
   if(Xval >=290 && Xval <=800 && Yval ==0){
       digitalWrite(led1Pin, HIGH);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, LOW);
   }
   if(Xval ==0 && Yval >=275 && Yval <=650){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, HIGH);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, LOW);
   }
   if(Xval>=400 && Xval <=850 && Yval ==1023){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, HIGH);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, LOW);
   }
   if(Xval ==1023 && Yval <=700 && Yval >=130){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, HIGH);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, LOW);
   }
   if(Xval <=290 && Xval >=0 && Yval ==0){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, HIGH);
   }
   if(Yval >650 && Yval <=1023 && Xval >=0 && Xval <400){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, HIGH);
       digitalWrite(led8Pin, LOW);
   }
   if(Xval >=850 && Xval <=1023 && Yval <=1023 && Yval >=700){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, LOW);
       digitalWrite(led6Pin, HIGH);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, LOW);
   }
   if(Xval <=1023 && Xval >800 && Yval <130 && Yval >=0){
       digitalWrite(led1Pin, LOW);
       digitalWrite(led2Pin, LOW);
       digitalWrite(led3Pin, LOW);
       digitalWrite(led4Pin, LOW);
       digitalWrite(led5Pin, HIGH);
       digitalWrite(led6Pin, LOW);
       digitalWrite(led7Pin, LOW);
       digitalWrite(led8Pin, LOW);
   }
   if(Sval == 0){
       digitalWrite(led1Pin, HIGH);
       digitalWrite(led2Pin, HIGH);
       digitalWrite(led3Pin, HIGH);
       digitalWrite(led4Pin, HIGH);
       digitalWrite(led5Pin, HIGH);
       digitalWrite(led6Pin, HIGH);
       digitalWrite(led7Pin, HIGH);
       digitalWrite(led8Pin, HIGH);
   }*/
}