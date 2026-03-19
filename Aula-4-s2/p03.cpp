#include <iostream>
#include <unordered_map>

using namespace std;

int main () 
{
    unordered_map<int, string> alunos;
    alunos[9090] = "Henrique";
    alunos[9091] = "Arthur";
    alunos[9092] = "Mateus";
    alunos[9093] = "Othavio";

    int matr;
    cout << "informe matricula ou 0 p sair\n";
    while(cin >> matr && matr != 0)
    {
        if (alunos.count(matr) > 0)
        {
            cout << alunos[matr] << endl;
        } else {
            cout << "nao encontrado" << endl;
        }
    }

    return 0;
}