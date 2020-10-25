int firstDiode = 8;
int secondDiode = 9;
int thirdDiode = 10;
int fourthDiode = 11;
int fifthDiode = 12;
int sixthDiode = 13;

int time = 1000;

String line;

String toBinary(int num){
    int base = num;
    String output = "000000";
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
    }else{
        digitalWrite(fourthDiode, LOW);
    }
    if(line.charAt(4) == '1'){
        digitalWrite(fifthDiode, HIGH);
    }else{
        digitalWrite(fifthDiode, LOW);
    }
    if(line.charAt(5) == '1'){
        digitalWrite(sixthDiode, HIGH);
    }else{
        digitalWrite(sixthDiode, LOW);
    }
}

void setup(){
    pinMode(firstDiode,OUTPUT);
    pinMode(secondDiode,OUTPUT);
    pinMode(thirdDiode,OUTPUT);
    pinMode(fourthDiode,OUTPUT);
    pinMode(fifthDiode,OUTPUT);
    pinMode(sixthDiode,OUTPUT);
}
void loop(){
    for(int i = 0; i<64; i++){
        display(toBinary(i));
        delay(time);
    }
}
