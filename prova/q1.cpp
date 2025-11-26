// Henrique Bottan Catani
// 210305

// le notas alunos (float 0 a 10), armazena em 2 containers,
//  um de aprovados (>= 7), outro de nao; encerra com -1
// exibe qtdApr e qtdRepr, notas apr cresc, media global setprecision(2)
// e as maior e menor nota dos apr e repr
/*
8.0
5.5
9.0
7.0
3.0
-1
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<list>
using namespace std;

int main ()
{
    float n = -2, somaNotas = 0, media = 0;
    list<float> listaApr;
    list<float> listaRepr;

    while (n != -1)
    {
        cin >> n;
        if (n > 10 || n < 0 && n != -1)
        {
            cout << "Nota inválida!\n";
        }
        else if (n >= 7)
        {   // aprovado
            listaApr.push_back(n);
            somaNotas += n;
        }
        else if (n < 7 && n != -1)
        {   // reprovado
            listaRepr.push_back(n);
            somaNotas += n;
        }
    } // fim loop, encerramento
    
    int qtdApr = listaApr.size();
    int qtdRepr = listaRepr.size();
    cout << "Quantidade de aprovados: " << qtdApr << endl
         << "Quantidade de reprovados: " << qtdRepr << endl
         << "Notas dos Aprovados (crescente): ";

    listaApr.sort([](float a, float b){return a < b;});  
    for(auto i:listaApr){
        cout << fixed << setprecision(2) << i << " ";
    }

    media = somaNotas / (qtdApr + qtdRepr);
    cout << fixed << setprecision(2) << "\nMedia global das notas: " << media << endl;

    auto it = listaApr.begin();
    float menorApr = *it; 
    advance(it, qtdApr - 1); // avanca ao final da lista
    float maiorApr = *it; 

    listaRepr.sort([](float a, float b){return a < b;});  
    it = listaRepr.begin();
    float menorRepr = *it; 
    advance(it, qtdRepr - 1); // avanca ao final da lista
    float maiorRepr = *it; 
    cout << fixed << setprecision(2) << "Aprovados: Maior nota: " << maiorApr 
         << " e Menor nota: " << menorApr << endl
         << "Reprovados: Maior nota: " << maiorRepr
         << " e Menor nota: " << menorRepr << endl;

    return 0;
}