#include<iostream>
using namespace std;


void foo(){
    int static n = 0; // alocacao estatica , vai alterar 1 so vez
    n++;
    cout << n << endl;
}

int main(void){
    foo();
    foo();
    foo();
    return 0;
}