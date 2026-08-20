#define pii pair<int,int>
#include <iostream>
#include <list>

using namespace std;

int main () 
{
    int n;
    while (cin >> n) {
        int maxPizzas; cin >> maxPizzas;

        list<pair<int, int>> pedidos;
        for (int i = 0; i < n; i++)
        {
            double t, p; cin >> t >> p;
            pedidos.push_back({t, p});
        }

        pedidos.sort([] (const pii &a, const pii &b) {
            return a.first > b.first;
        });

        int tempoTotal = 0;
        int pizzasEntregues = 0;

        for ( pii pedido : pedidos )
        {
            if (pizzasEntregues + pedido.second < maxPizzas) {
                pizzasEntregues += pedido.second;
                tempoTotal += pedido.first;
            }
        }

        cout << tempoTotal << " min.\n";
    }
}