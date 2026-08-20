#define pdd pair<double, double>
#include <iostream>
#include <list>

using namespace std;

int main (void)
{
    int numCaixas, maxPeso; cin >> numCaixas >> maxPeso;

    list<pair<double, double>> caixas; 
    
    for ( int i = 0; i < numCaixas; i++ ) {
        double v, p; cin >> v >> p;
        caixas.push_back( { p, v/p });
    } 

    caixas.sort([] (const pdd& a, const pdd& b) {
        return a.second > b.second;
    });

    double valorMax = 0;

    for ( auto c : caixas ) {
        if ( c.first >= maxPeso ) {
            valorMax += maxPeso * c.second;
            break;
        } 
        else {
            maxPeso -= c.first;
            valorMax += c.first * c.second;
        }
    }

    cout << "Valor máximo: " << valorMax << endl;
}