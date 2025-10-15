#include<iostream>
using namespace std;

int main (void){
    int vet[4]= {10,20,30,40};
    cout << vet << endl; // printa o endereco do vetor
    int *p = vet; // vet[0]
    cout << *p << " " << p << endl;
    p++ ;
    cout << *p << " " << p << endl;
    return 0;
}