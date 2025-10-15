#include<iostream>
using namespace std;

int main(void)
{
    int *p = new int;
    *p = 0;
    cout << p << " " << *p << endl;

    delete p; // criou new, deletar


    // vazamento de memoria: 
    int a = 5;
    int *p1 = &a;

    int *p2 = new int;
    *p2 = 35; 
    p2 = p1;
    // o valor 35 foi perdido, ficou em um local de memoria desconhecido
    // pois o p2 tinha o endereco e perdeu esse valor
}