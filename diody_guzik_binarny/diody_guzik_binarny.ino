int firstDiode = 1;
int secondDiode = 2;
int thirdDiode = 3;
int fourthDiode = 4;
int myNumb=0;
const int button=5;
int buttonState=0;
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
void display(String line){
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
    }
}
void setup() {
     

    pinMode(firstDiode,OUTPUT);
    pinMode(secondDiode,OUTPUT);
    pinMode(thirdDiode,OUTPUT);
    pinMode(fourthDiode,OUTPUT);

    pinMode(button, INPUT);

    

}

void loop() {
    buttonState=digitalRead(button);

    display(toBinary(myNumb));
    
    if(buttonState==HIGH){ 
      myNumb=myNumb+1;
    }

    if(myNumb=16){
      myNumb=0;
    }
}
