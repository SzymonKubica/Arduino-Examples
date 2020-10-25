int readPin = A3;
int greenLed = 8;
int yellowLed = 9;
int redLed = 10;
float V2 = 0;
float readVal;
int time = 100;
void setup(){
    pinMode(readPin, INPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    Serial.begin(115200);
}
void loop(){
    readVal = analogRead(readPin);
    V2 = (5./1023.)*readVal;
    if(V2<2){
       digitalWrite(greenLed, HIGH); 
       digitalWrite(yellowLed, LOW); 
       digitalWrite(redLed, LOW); 
    }else if(V2<4){
       digitalWrite(greenLed, LOW); 
       digitalWrite(yellowLed, HIGH); 
       digitalWrite(redLed, LOW) ;
    }else{
       digitalWrite(greenLed, LOW) ;
       digitalWrite(yellowLed, LOW); 
       digitalWrite(redLed, HIGH); 
    }    
    Serial.println(V2);
    delay(time);
}