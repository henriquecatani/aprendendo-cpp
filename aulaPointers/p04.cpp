#include<iostream>
using namespace std;

struct aluno{
    int matricula;
    string nome;
};

int main (void)
{
    aluno a1 = {1, "Henrique Catani"};
    aluno *p = &a1;
    cout << p << " " << p->nome << endl;
    // para acessar um elemento em uma struct
    // referenciada por um ponteiro
    // usar -> e não um ponto

    p->nome = "Henrique Bottan Catani";
    cout << p << " " << p->nome << endl;

    string *n = &p->nome;
    int *m = &p->matricula;
    cout << p << " " << n << " " << m << endl;
    return 0;
}