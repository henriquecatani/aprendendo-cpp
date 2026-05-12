// Henrique Bottan Catani

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

int main ()
{
    ifstream arqProdutos, arqVendas;
    arqProdutos.open("produtos.txt"); 
    arqVendas.open("vendas.txt");

    if (!arqProdutos || !arqVendas) {
        cout << "Não foi possível abrir os arquivos necessários!" << endl;
        exit(1);
    }

    ofstream tab;
    tab.open("relatorio_vendas.csv");

    tab << "Codigo" << ";"
        << "Preco"  << ";"
        << "Status" << endl;

    map<string, double> produtos;
    string codigo_barras;
    double preco;
    // leitura por palavra
    while ( arqProdutos >> codigo_barras >> preco ) {
        produtos[codigo_barras] = preco;
    }

    double totalVendas = 0;
    double qtdLinhas = 0, qtdErros = 0;

    map<string, int> vendasQtd;
    string venda;
    while (getline(arqVendas, venda))
    {
        double preco = produtos[venda];
        totalVendas += preco;
        qtdLinhas += 1;

        tab << venda << ";";
        tab << fixed << setprecision(2) << preco << ";";

        if (preco == 0) {
            qtdErros += 1;
            tab << "Não encontrado" << endl;
        }
        else {
            tab << "Vendido" << endl;

            int qtd = vendasQtd[venda];
            vendasQtd[venda] += 1;
        }
    }

    string maisVendido;
    int qntMaisVendido = 0;

    for (auto t : vendasQtd) {
        if (qntMaisVendido < t.second) {
            qntMaisVendido = t.second;
            maisVendido = t.first;
        }
    }

    double porcentagem = (100 * qtdErros) / qtdLinhas;

    cout << "Valor total das vendas: R$ " 
        << fixed << setprecision(2) << totalVendas << endl
        << "Produto mais vendido: " << maisVendido 
        << " (" << qntMaisVendido << " vendas)" << endl
        << fixed << setprecision(1) << porcentagem
        << "\% das vendas referem-se a produtos não cadastrados"
        << endl;

    arqProdutos.close();
    arqVendas.close();
    tab.close();

    return 0;
}