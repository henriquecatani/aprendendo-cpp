#include<iostream>
#include<cstring>
using namespace std;


void print(string txt){
    cout << txt << endl;
}

int soma(int x, int y, int z = 0){
    int t = x + y + z;
    return t;
}

int main(void){
    print("Testando print");
    int testSoma = soma(2,4);
    cout << testSoma << endl;
    return 0;
}