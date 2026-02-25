#include <iostream>
#include <fstream>
using namespace std;

int main () 
{
    int n;
    ifstream arq;
    arq.open("numeros.txt"); // tenta abrir arquivo
    if (!arq)
    {
        cout << "Não abriu" << endl;
        exit(1);

    }

    while (arq >> n) // enquanto tiver conteudo no arquivo, passa para o n
    {
        cout << n*3 << endl;
    }

    arq.close();
}