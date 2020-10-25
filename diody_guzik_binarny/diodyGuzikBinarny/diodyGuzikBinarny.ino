// Czerwony kabel - x1; Pomarańczowy kabel x2;
int firstDiode = 2;
int secondDiode = 3;
int thirdDiode = 4;
int fourthDiode = 5;
int myNumb=0;

const int buttonReset=13;

const int button=8;
const int button2=9;
const int button3=10;
const int button4=11;

int buttonResetState=0;
int buttonState=0;
int buttonState2=0;
int buttonState3=0;
int buttonState4=0;

int delayTime = 250;

String toBinary(int num){
    int base = num;
    String output = "0000";
    while(base>0){
        int factor = 1;
        int exp = 0;
        while(factor*2 <= base){
            factor*=2;
            exp++;
        }
        base-=factor;
        output[exp]= '1';
    }
    return output;
}
void displayIt(String line){
    if(line.charAt(0) == '1'){
        digitalWrite(firstDiode, HIGH);
    }else{
        digitalWrite(firstDiode, LOW);
    }
    if(line.charAt(1) == '1'){
        digitalWrite(secondDiode, HIGH);
    }else{
        digitalWrite(secondDiode, LOW);
    }
    if(line.charAt(2) == '1'){
        digitalWrite(thirdDiode, HIGH);
    }else{
        digitalWrite(thirdDiode, LOW);
    }
    if(line.charAt(3) == '1'){
        digitalWrite(fourthDiode, HIGH);
    }else{
      digitalWrite(fourthDiode, LOW);
    }
}
void setup() {
     

    pinMode(firstDiode,OUTPUT);
    pinMode(secondDiode,OUTPUT);
    pinMode(thirdDiode,OUTPUT);
    pinMode(fourthDiode,OUTPUT);
    Serial.begin(9600);
    pinMode(button, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
     pinMode(button4, INPUT);
      pinMode(buttonReset, INPUT);

}

void loop() {
  
  buttonState=digitalRead(button);
  buttonState2=digitalRead(button2);
  buttonState3=digitalRead(button3);
  buttonState4=digitalRead(button4);
  buttonResetState=digitalRead(buttonReset);
      
    while(buttonState==HIGH && buttonState2==HIGH && buttonState3==HIGH && buttonState4==HIGH){
      buttonState=digitalRead(button);
      buttonState2=digitalRead(button2);
      buttonState3=digitalRead(button3);
      buttonState4=digitalRead(button4);
      buttonResetState=digitalRead(buttonReset);
      if(buttonResetState==LOW){
        myNumb=0;
        break;
      }
      if(buttonState==LOW){ 
        myNumb++;
        break;
      }
      if(buttonState2==LOW){ 
        myNumb+=2;
        break;
      }
      if(buttonState3==LOW){ 
        myNumb+=4;
        break;
      }
      if(buttonState4==LOW){ 
        myNumb+=8;
        break;
      }
    }
    if(myNumb==16){
      myNumb=0;
    }
    displayIt(toBinary(myNumb));
    delay(delayTime);
}
