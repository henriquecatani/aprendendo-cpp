#include<iostream>
using namespace std;


void foo(int n){
    double d = 0;
    cout << n << " " << &d << endl;
    foo(n+1);
}

int main(void){
    foo(0);
    return 0;
}