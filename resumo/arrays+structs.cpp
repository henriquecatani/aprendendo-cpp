// Resumo baseado nos arquivos do repositório
#include <iostream>
using namespace std;
#include <iomanip>

int main ( void ) {
    {
        double val1 = 0.123421;
        /// Precisão de 1 casa decimal - iomanip
        cout << fixed << setprecision(1) << "valor = " << val1 << endl;
    }

    {
        int tamanho = 5;
        int vetorInteiros[tamanho];
        int vetorIntInit[] {1,3,4,5};
    }

    {
        const int L = 3;
        const int C = 3;
        float matriz[L][C]{
            {1.5, 0.4, 9.1},
            {0.6, 6.4, 10.2},
            {8.7, 1.7, 15.3}
        };

        float valor_2_1 = matriz[2][1];
    }


}