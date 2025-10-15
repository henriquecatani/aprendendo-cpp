#include<iostream>
using namespace std;

int main(void){
    int a = 10;
    int b  = 20;
    int *p; // asterisco define um ponteiro
    int *z;
    p = &a; // endereço de memoria de a
    z = &b;
    cout << p << endl; // endereco de memoria
    cout << *p << endl; // o valor apontado por p
    cout << z << endl; // endereco de memoria
    cout << *z << endl; // o valor apontado por p

    return 0;
}