#include<iostream>
#include<stack>
using namespace std;

int main ()
{
    struct instrucao;
    int valor;
    cin >> instrucao >> valor;
    if (instrucao == "PUSH")
    {
        cout << valor;
    }

}