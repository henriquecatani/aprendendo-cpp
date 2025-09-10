#include <iostream>
#include <algorithm>
using namespace std;

struct aluno{
    int matricula;
    string nome;
    float nota;
};

bool ordena(const aluno &a1 , const aluno &a2){
    return a1.nota < a2.nota;

}

const int NA = 5;
int main(void){
    aluno turma[NA] = {
        {212122, "bobao", 8.5},
        {213223, "burrao", 6.1},
        {123122, "banana", 9.6},
        {234324, "boiola", 1.3},
        {536233, "bonito", 9.9}
    };
    sort(turma, turma+NA, ordena);
    
    for(int i = 0; i<NA; i++){
        cout << "Matr.: " << turma[i].matricula << ",\t";
        cout << "Nome: " << turma[i].nome << ",\t";
        cout << "Turma: " << turma[i].nota << endl;
    }
    return 0;

}