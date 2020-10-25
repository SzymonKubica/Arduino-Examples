int greenLed = 12;
int switchPin = A0;
int buttonReadOld = 1;
int buttonReadNew;
bool isOn = false;
int dt = 100;
void setup(){
    pinMode(greenLed, OUTPUT);
    pinMode(switchPin, INPUT);
    Serial.begin(115200);
}
void loop(){
    buttonReadNew = digitalRead(switchPin);
    Serial.println(buttonReadNew);
    if(buttonReadOld== 1 && buttonReadNew == 0){
       if(isOn == false){
           isOn = true;
       }else{
           isOn = false;
       } 
    }
    
    if(isOn==true){
        digitalWrite(greenLed, HIGH);
    }else{
        digitalWrite(greenLed, LOW);
    }
    buttonReadOld = buttonReadNew; 
    delay(dt);
}