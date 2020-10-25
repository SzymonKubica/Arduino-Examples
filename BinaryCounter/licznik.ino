//Zmień numery na odpowiednie piny zasilające diody;
int firstDiode = 1;
int secondDiode = 2;
int thirdDiode = 3;
int fourthDiode = 4;
//To jest funkcja której dajesz liczbę a ona zwraca Ci Stringa w zapisie binarnym;
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
//To jest funkcja zaświecająca odpowiednie diody w oparciu o Stringa w zapisie binarnym;
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
//Żeby wywołać funkcję musisz napisać: display(toBinary(*liczba, którą chcesz wyświetlić*));
//Ten kod musisz wkleić tam, gdzie deklarujesz zmienne, przed void setup();