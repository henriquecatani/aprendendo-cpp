#include<iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int *p = &a; // p eh end de a

    int **pp;   // ponteiro para o ponteiro
    pp = &p;    // atribui endereco do ponteiro para o ponteiro de ponteiro

    cout << pp << " "   // imprime o end de P
    << *pp << " "       // imprime o end apontado por P
    << **pp << endl;    // imprime o valor do end apontado por P
    return 0;
}