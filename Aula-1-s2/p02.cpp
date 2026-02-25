#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    int n;
    ifstream arq;
    string nome;
    cout << "Digite o nome do arquivo a ser criado: ";
    getline(cin, nome);
    arq.open(nome);
    //arq.open("input/"+name); abre em uma pasta input
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