// cntwords-hash.cpp
// por Henrique Catani
// Conta palavras usando tabela hash e lista encadeada.

// Uso: cntwords-hash <arquivo> [<opcao> <valor>]
// Se nenhuma opção for fornecida, exibe o número de palavras em cada índice da tabela hash.
// Opcoes:
//   -c <palavra> : Conta ocorrencias da palavra
//   -p <palavra> : Indice da palavra na tabela hash
//   -cl <palavra> : Conta ocorrencias da palavra (retorna somente numero)
//   -pl <palavra> : Indice da palavra na tabela hash (retorna somente numero)

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


void printUsage(const char *progName);

int main (int argc, char *argv[])
{
    // argumentos
    if ((argc != 4) && (argc != 2)) 
    {
        printUsage(argv[0]);
        return 1;
    }

    string inp = argv[1];
    string opcao, valor;
    if (argc == 4)
    {
        opcao = argv[2];
        valor = argv[3];
        if (opcao != "-c" && opcao != "-p" && opcao != "-cl" && opcao != "-pl") 
        {
            cerr << "Opcao invalida: " << opcao << endl;
            printUsage(argv[0]);
            return 1;
        }
    } 
    
    // logica
    list<Palavra> hashTable[HASH_TABLE_SIZE];
    ifstream arq(inp);
    string palavra;
    char ch;
    if (!arq)
    {        
        cerr << "Arquivo invalido: " << inp << endl;
        printUsage(argv[0]);
        return 1;
    }
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
            if (opcao == "-c" && p.palavra == valor) 
            {
                cout << "A palavra '" << valor << "' aparece " << p.cnt <<  (p.cnt != 1 ? " vezes." : " vez.") << endl;
                return 0;
            } 
            else if (opcao == "-p" && p.palavra == valor) 
            {
                cout << "A palavra '" << valor << "' aparece no indice " << i << endl;
                return 0;
            }
            else if (opcao == "-cl" && p.palavra == valor) 
            {
                cout << p.cnt << endl;
                return 0;
            }
            else if (opcao == "-pl" && p.palavra == valor) 
            {
                cout << i << endl;
                return 0;
            }
        }
        if (argc == 2) 
        {
            cout << "Indice " << i << ": " << count << " palavras" << endl;
        }
    }

    return 0;
}


void printUsage(const char *progName) {
    cerr << "Uso: " << progName << " <arquivo> [<opcao> <valor>]" << endl
    << "Se nenhuma opção for fornecida, exibe o número de palavras em cada índice da tabela hash." << endl
    << "Opcoes:" << endl
    << "  -c <palavra> : Conta ocorrencias da palavra" << endl
    << "  -p <palavra> : Indice da palavra na tabela hash" << endl
    << "  -cl <palavra> : Conta ocorrencias da palavra (retorna somente numero)" << endl
    << "  -pl <palavra> : Indice da palavra na tabela hash (retorna somente numero)" << endl;
}