#define pii pair<int,int>
#include <iostream>
#include <vector>

using namespace std;

int main () 
{
    int n;
    while (cin >> n && n) {
        int maxPizzas; cin >> maxPizzas;

        vector<pii> pedidos; // <tempo, pizzas>
        for (int i = 0; i < n; i++)
        {
            int t, p; cin >> t >> p;
            pedidos.push_back({t, p});
        }

        vector<int> mochila(maxPizzas + 1, 0);

        for ( pii pedido : pedidos )
        {
            for (int slot = maxPizzas; slot >= pedido.second; slot--)
            {
                mochila[slot] = max(mochila[slot], mochila[slot - pedido.second] + pedido.first);
            }
        }

        cout << mochila[maxPizzas] << " min.\n";
    }
    
    return 0;
}