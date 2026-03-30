#include<iostream>
#include<list>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int t = 0; t < N; t++) 
    {
        int M, C;
        cin >> M >> C;
        list<int> hashTable[M];
        for (int i = 0; i < C; i++) 
        {
            int chave;
            cin >> chave;
            int indice = chave % M;
            hashTable[indice].push_back(chave);
        }
        for (int i = 0; i < M; i++) 
        {
            cout << i << " -> ";
            for (auto chave : hashTable[i]) 
            {
                cout << chave << " -> ";
            }
            cout << "\\" << endl;
        }
        if (t != N - 1) cout << endl;
    }
    return 0;
}