#include <iostream>
#include <unordered_set>

using namespace std;

int main () 
{
    unordered_set<string> alunos;

    alunos.insert("Henrique");
    alunos.insert("Arthur");
    alunos.insert("Mateus");
    alunos.insert("Othavio");

    cout << alunos.size() << endl;
    
    for (const auto & aluno : alunos)
    {
        cout << aluno << endl;
    }

    // buscar valores
    // metodo find retorna um iterator para o elemento se encontrar
    // se nao, iterator p o final do container

    if (alunos.find("Henrique") != alunos.end())
    {
        cout << "Henrique encontrado\n";
    } else {
        cout << "Henrique nao encontrado\n";
    }

    return 0;
}