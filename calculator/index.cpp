#include <iostream>
using namespace std;

// Variables
int a,b, res;
string op, resultClosing = "Hasilnya adalah sebagai berikut: ";  
float resFloat;
bool idle = true;

void welcome(){
    cout << "===========================================================" << endl;
    cout << "Welcome to my Calculator Project, press enter to continue" << endl;
    getchar();
}

// Function for sum numbers
int sum(int a, int b){
    return a + b;
}

// Function for minus
int minusNum(int a, int b){
    return a - b;
}

// Function for do times number
int times(int a, int b){
    return a * b;
}

// Function for divide Numbers
float divide(float a, float b){
    return a / b;
}

// Function for request input to user
void inputNumber(){
    cout << "Masukkan Angka Pertama: ";
    cin >> a;
    cout << "Masukkan Angka Kedua: ";
    cin >> b;
};

// Function for choosing the math operator
void calculator(){
    cout << "Pilih Operator (+,-,x,/,%): ";
    cin >> op;

    if(op == "+"){
        res = sum(a,b);
        cout << resultClosing << res << endl;
    } else if(op =="-"){
        res = minusNum(a,b);
        cout << resultClosing << res << endl;
    } else if(op == "x"){
        res = times(a,b);
        cout << resultClosing << res << endl;
    } else if(op == "/"){
        resFloat = divide(a,b);
        cout << resultClosing << resFloat << endl;
    } else{
        cout << "There is no operator beside those" << endl;
    }
};

void again(){
    string answer;
    cout << "Ingin menghitung lagi?(Y/N)";
    cin >> answer;
    if(answer == "Y" || answer == "y"){
        idle = true;
    } else if(answer == "N" || answer == "n"){
        idle = false;
    } else{
        cout << "Masukkan input yang benar";
        again();
    }
};

int main(){
    while(idle){    
        welcome();
        inputNumber();
        calculator();
        again();
    }
    return 0;
}