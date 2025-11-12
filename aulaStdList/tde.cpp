/*
Crie um programa em C++ que permite o gerenciamento de uma lista de compras no
supermercado. Cada item na lista terá um nome, quantidade e a marca. O programa deve
ter as seguintes funcionalidades:
1. Adicionar um item à lista.
2. Remover um item à lista.
3. Listar todos os itens.
4. Sair do programa.

Utilize a estrutura de dados std::list para armazenar as mercadorias.
*/

#include<iostream>
#include<list>
using namespace std;

struct compra
{
    string nome;
    int qtd;
    string marca;
}

int main ()
{
    list<compra> listaCompras;
    compra aux;
    int opcao;
    cout << "Insira a opção desejada:\n"
    << "1- Adicionar elemento à lista de compras\n"
    << "2- Remover item da lista\n"
    << "3- Listar todos os itens\n";
    cin >> opcao;
    switch (opcao)
    {
    case 1:
        /* code */
        cout << "Qual item? ";
        cin >> aux.nome;
        cout << "Quantos? ";
        cin >> aux.qtd;
        cout << "Marca? ";
        cin >> aux.marca;
        break;
    
    case 2:
        
        break;
    default:
        break;
    }

    return 0;
}