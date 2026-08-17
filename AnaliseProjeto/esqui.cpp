#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ModeloEsqui {
    string nome;
    int duracao;
    int reembolso;
    double taxa_diaria;
};


bool compararModelos ( const ModeloEsqui& a, const ModeloEsqui& b ) 
{
    // maior cashback diario
    if (a.taxa_diaria != b.taxa_diaria)
        return a.taxa_diaria > b.taxa_diaria;

    // maior duracao
    return a.duracao > b.duracao;
}

int main () 
{
    int D, C; // dias, qtd modelos

    if (!(cin >> D >> C)) return 0;

    vector<ModeloEsqui> modelos(C);

    for ( int i = 0; i < C; i++ ) {
        cin >> modelos[i].nome >> modelos[i].duracao >> modelos[i].reembolso;
        
        // cashback diario
        modelos[i].taxa_diaria = static_cast<double>(modelos[i].reembolso) / modelos[i].duracao;
    }

    sort( modelos.begin(), modelos.end(), compararModelos );

    vector<string> modelos_escolhidos;
    int reembolso_total = 0;
    int dias_restantes = D;

    for ( int i = 0; i < C; i++ ) 
    {
        while (dias_restantes >= modelos[i].duracao) 
        {
            modelos_escolhidos.push_back(modelos[i].nome);
            reembolso_total += modelos[i].reembolso;
            dias_restantes -= modelos[i].duracao;
        }
    }

    cout << "Modelos Escolhidos: [";
    for ( size_t i = 0; i < modelos_escolhidos.size(); i++ ) 
    {
        cout << "Modelo " << modelos_escolhidos[i];

        if (i < modelos_escolhidos.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
    cout << "Reembolso Total: R$ " << reembolso_total << "\n";

    return 0;
}