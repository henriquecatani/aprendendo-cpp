#include<iostream>
using namespace std;

void soma(int &valorInicial, int valoraSomar){
    // o & eh uma referencia ao endereco de memoria da
    // variavel passada na chamada de funcao
    // -- sem precisar de return --
    // o valoraSomar vai fazer uma copia do valor passado na chamada
    valorInicial += valoraSomar;
    valoraSomar += valoraSomar;
    cout << "Valor de b dentro da função: " << valoraSomar << endl;
}
int main(void){
    int a = 100;
    int b = 21;
    cout << "Valor de a antes da função: " << a << endl
    << "Valor de b antes da função: " << b << endl;
    soma(a,b);
    cout << "Valor de a depois da função: " << a << endl
    << "Valor de b depois da função: " << b << endl;
    return 0;
}