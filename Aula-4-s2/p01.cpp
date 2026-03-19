// ex de tabelas hash utilizando
// tratamento de colisao por encadeamento externo

#include<iostream>
#include<list>
#include<string>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
    string email;
};

#define HASH_TABLE_SIZE 10

// a tabela hash é um vetor de tamanho fixo
// e cada posição é uma lista de alunos (encadeamento externo)
list<Aluno> hashtable[HASH_TABLE_SIZE];

int hashFunction(int matricula)
{
    return matricula % HASH_TABLE_SIZE;
}

void inserir(Aluno aluno)
{
    hashtable[hashFunction(aluno.matricula)].push_back(aluno);
}

Aluno buscar(int matricula)
{
    int indice = hashFunction(matricula);

    for (auto it = hashtable[indice].begin(); it != hashtable[indice].end(); it++)
    {
        if (it->matricula == matricula)
        {
            return *it; // aluno encontrado na posicao do it
        }
    }
    return Aluno();
}

void remover(int matricula) {
    int indice = hashFunction(matricula);

    for (auto it = hashtable[indice].begin(); it != hashtable[indice].end(); it++)
    {
        if (it->matricula == matricula)
        {
            hashtable[indice].erase(it);
            break;
        }
    }
}

void imprimir()
{
    int linha = 0;
    for (list<Aluno> i : hashtable)
    {
        for(Aluno a : i) 
        {
            cout << "linha: " << linha << endl
                 << "Nome: "        << a.nome
                 << ", Matricula: " << a.matricula
                 << ", Email: "     << a.email
                 << endl;
        }
        linha++;
    }

}

void get();

int main ()
{
    get();
    imprimir();

    
    return 0;

}


void get()
{
    Aluno a1 = {"Henrique", 123, "henrique@example.com"};
    inserir(a1);
    Aluno a2 = {"Mateus", 456, "mateus@example.com"};
    inserir(a2);
    Aluno a3 = {"Arthur", 789, "arthur@example.com"};
    inserir(a3);
    Aluno a4 = {"Othavio", 145, "othavio@example.com"};
    inserir(a4);
    Aluno a5 = {"Vitor", 678, "vitor@example.com"};
    inserir(a5);
    Aluno a6 = {"Rodrigo", 234, "rodrigo@example.com"};
    inserir(a6);
    Aluno a7 = {"Gustavo", 567, "gustavo@example.com"};
    inserir(a7);
    Aluno a8 = {"Lucas", 890, "lucas@example.com"};
    inserir(a8);
    Aluno a9 = {"Rafael", 345, "rafael@example.com"};
    inserir(a9);
    Aluno a10 = {"Bruno", 678, "bruno@example.com"};
    inserir(a10);
    Aluno a11 = {"Diego", 901, "diego@example.com"};
    inserir(a11);
    Aluno a12 = {"Eduardo", 245, "eduardo@example.com"};
    inserir(a12);
}