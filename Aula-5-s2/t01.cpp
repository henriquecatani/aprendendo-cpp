// recebe no stdin nome do arquivo, conta palavras usando tabela hash e lista encadeada

#include<iostream>
#include<list>
#include<string>
#include<fstream>

const int HASH_TABLE_SIZE = 97;
using namespace std;

struct Palavra 
{
    string palavra;
    int cnt;
};

int hashFunction(const string &str) {
    int soma = 0;
    for (char c : str) soma += (int)c;
    return soma % HASH_TABLE_SIZE;
}

int main ()
{
    list<Palavra> hashTable[HASH_TABLE_SIZE];
    string inp;
    cin >> inp;
    ifstream arq(inp);
    string palavra;
    char ch;
    while (arq.get(ch)) 
    {
        if (isalpha(ch)) 
        {
            palavra += tolower(ch);
        } 
        else if (palavra.size() > 0) 
        {
            int indice = hashFunction(palavra);
            bool achou = false;
            for (auto &p : hashTable[indice])
            {                
                if (p.palavra == palavra)
                {
                    p.cnt++;
                    achou = true;
                    palavra.clear();
                    break;
                }
            }
            if (achou == false) 
            {
                hashTable[indice].push_back({palavra, 1});
                palavra.clear();
            }
        }


    }
    for (int i = 0; i < HASH_TABLE_SIZE; i++) 
    {
        int count = 0;
        for (auto p : hashTable[i]) 
        {
            count += p.cnt;
        }
        cout << "Indice " << i << ": " << count << " palavras" << endl;
    }

    

    return 0;
}

