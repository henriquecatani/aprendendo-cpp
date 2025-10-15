#include<iostream>
using namespace std;


void foo(){
    int n = 0; // alocacao dinamica
    n++;
    cout << n << endl;
}

int main(void){
    foo();
    foo();
    foo();
    return 0;
}