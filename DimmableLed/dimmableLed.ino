int buttonUpPin = A5;
int buttonDownPin = A4;

int greenLed = 3;
int ledVal = 0;
int buzzPin = 8;

int buttonUpStateNew;

int buttonDownStateNew;


int dt = 100;

void setup(){
    pinMode(buttonUpPin, INPUT);
    pinMode(buttonDownPin, INPUT);

    pinMode(greenLed, OUTPUT);
    pinMode(buzzPin, OUTPUT);
    Serial.begin(115200);
}
void loop(){
    buttonUpStateNew = digitalRead(buttonUpPin);
    buttonDownStateNew = digitalRead(buttonDownPin);
    Serial.println(buttonUpStateNew);
    Serial.println(buttonDownStateNew);
    if( buttonUpStateNew == 0){
        ledVal+=10;
        if(ledVal>255){
            digitalWrite(buzzPin,HIGH);
            ledVal=255;
        }else{
            digitalWrite(buzzPin,LOW);
        }
    }
    if(buttonDownStateNew == 0 ){
        ledVal-=10;
        if(ledVal<0){
            ledVal=0;
        }
    } 
    if(ledVal==255&& buttonUpStateNew==1){
        digitalWrite(buzzPin,LOW);
    }
    analogWrite(greenLed, ledVal);
    
    delay(dt);
}