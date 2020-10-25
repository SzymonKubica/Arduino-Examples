int firstDiode = 8;
int secondDiode = 9;
int thirdDiode = 10;
int fourthDiode = 11;
int fifthDiode = 12;
int sixthDiode = 13;
int seventhDiode = 7;
int eighthDiode = 6;
int ninthDiode = 5;
int tenthDiode = 4;

int time = 250;

String line;

string toBinary(int num){
    int base = num;
    String output = "0000000000";
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
    if(line.charAt(6) == '1'){
        digitalWrite(seventhDiode, HIGH);
    }else{
        digitalWrite(seventhDiode, LOW);
    }
    if(line.charAt(7) == '1'){
        digitalWrite(eighthDiode, HIGH);
    }else{
        digitalWrite(eighthDiode, LOW);
    }
    if(line.charAt(8) == '1'){
        digitalWrite(ninthDiode, HIGH);
    }else{
        digitalWrite(ninthDiode, LOW);
    }
    if(line.charAt(9) == '1'){
        digitalWrite(tenthDiode, HIGH);
    }else{
        digitalWrite(tenthDiode, LOW);
    }
}

void setup(){
    pinMode(firstDiode,OUTPUT);
    pinMode(secondDiode,OUTPUT);
    pinMode(thirdDiode,OUTPUT);
    pinMode(fourthDiode,OUTPUT);
    pinMode(fifthDiode,OUTPUT);
    pinMode(sixthDiode,OUTPUT);
    pinMode(seventhDiode,OUTPUT);
    pinMode(eighthDiode,OUTPUT);
    pinMode(ninthDiode,OUTPUT);
    pinMode(tenthDiode,OUTPUT);
}
void loop(){
    for(int i = 0; i<1024; i++){
        display(toBinary(i));
        delay(time);
    }
}