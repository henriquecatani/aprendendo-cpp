#include <iostream>
#include <list>

using namespace std;

struct caixa {
    double valor;
    double peso;
    double razao;
};

int main (void)
{
    int numCaixas, maxPeso; cin >> numCaixas >> maxPeso;

    list<caixa> caixas; 
    
    for ( int i = 0; i < numCaixas; i++ ) {
        double v, p; cin >> v >> p;
        caixas.push_back( { v, p, v/p });
    } 

    caixas.sort([] (const caixa& a, const caixa& b) {
        return a.razao < b.razao;
    });

    double valorMax = 0;

    for ( caixa c : caixas ) {
        if ( c.peso >= maxPeso ) {
            valorMax += maxPeso * c.razao;
            break;
        } 
        else {
            maxPeso -= c.peso;
            valorMax += c.peso * c.razao;
        }
    }

    cout << "Valor máximo: " << valorMax << endl;
}