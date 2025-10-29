#include<iostream>
#include<vector>
using namespace std;

    // capacidade e tamanho sao diferentes
    // tamanho eh a quantidade de elementos do vetor
    // capacidade eh o tamanho alocado para o vetor na memoria

int main()
{
    vector<double> v;
    cout << "Digite 0 para sair\n";
    double x;
    cout    << "Tamanho: " << v.size() << "\t"
            << "Capacidade: " << v.capacity() 
            << endl;

    
    while(cin >> x && x!=0){
        v.push_back(x);
        cout    << "Tamanho: " << v.size()
                << "\tCapacidade: " << v.capacity() 
                << endl;
    }

    return 0;
}