#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> v(n); // tamanho minimo n ; ja vai alocar o tamanho certo
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout    << "Tamanho: " << v.size()
            << "\tCapacidade: " << v.capacity()
            << endl;
    
    v.push_back("adasdSd");
    v.push_back("aaiscbhoas");

    // se o tamanho passar da capacidade, a capacidade duplica. Se for 5, vira 10
    cout    << "Tamanho: " << v.size()
            << "\tCapacidade: " << v.capacity()
            << endl;


    return 0;
}
