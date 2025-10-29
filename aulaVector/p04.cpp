#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> v;
    v.push_back("A");
    v.push_back("B");    
    v.push_back("C");
    v.push_back("D");
    v.push_back("E");
    v.push_back("F");
    v.push_back("G");

    // funcao find (retorna um endereco) para retornar a primeira ocorrencia
    auto it = find(v.begin(), v.end(), "C"); 
    // find do std algorithm, find(inicio, fim, oq procurar)
    // procura elemento por elemento
    // se nao encontrar , retorna endereco do final

    if(it == v.end()){
        cout << "Não encontrado!\n";
    } else {
        v.insert(it, "Z");
    }

    for(auto n:v){
        cout << n << endl;
    }

    cout << endl;
    v.insert(v.begin(),"A"); // insere no INICIO do vetor (push_front)
    for(auto n:v){
        cout << n << endl;
    }
    v.clear(); // LIMPA o vetor (mantem mesma alocacao de memoria - capacidade)
    
    cout    << "\nTamanho: " << v.size()
            << "\tCapacidade: " << v.capacity()
            << endl;

    return 0;
}