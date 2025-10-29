#include<iostream>
#include<vector>
using namespace std;

// vetor eh dinamico

int main()
{
    vector<int> v; // VETOR DE INT VAZIO
    cout << "Tamanho: " << v.size() << endl;
    v.push_back(10); // INSERE NO FINAL DO VETOR
    v.push_back(12);
    v.push_back(5);    
    
    for(int i=0; i<v.size();i++)
    {
        cout << i << " : " << v[i] << endl;
    }

    v.pop_back();
    cout << "tamanho: " << v.size() << endl;
    return 0;
}