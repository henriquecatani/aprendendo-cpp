// Henrique Bottan Catani
// 210305

// usa fila; le ints, para no 0
// para cada valor:
// se fila vazia ou n > frente: insere n
// se n <= frente, remove y, insere n + y 
// se n = 0, exibir tamanho da fila

/*
10 5 20 2 8 12 35 22 0

5 4 3 2 1 0
*/
#include<iostream>
#include<queue>
using namespace std;
int main () 
{
    int n = 1;
    queue<int> fila;
    while (n != 0)
    {
        cin >> n;
        if (n == 0)
        {
            cout << "Fim com tamanho da fila = " << fila.size() << endl;
        }
        else if (fila.empty() || n > fila.front())        
        {
            fila.push(n);
        }
        else if (n <= fila.front())
        {
            int y = fila.front();
            fila.pop();
            fila.push(n+y);
        }
    }
    return 0;
}