#include <iostream>
#include <list>

using namespace std;

int main (void)
{
    list<pair<double, int>> l_notas {
        {100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}, {2, 0}, 
        {1, 0}, {0.50, 0}, {0.25, 0}, {0.10, 0}, {0.05, 0}, {0.01, 0}};

    double valor; cin >> valor;

    cout << "NOTAS:\n";

    for (auto p : l_notas) 
    {
        p.second = valor / p.first;
        valor -= p.first * p.second;

        if (p.first == 1)
            cout << "MOEDAS:\n";

        cout << p.second << " nota(s) de R$" << p.first << endl;
    }

    return 0;
}