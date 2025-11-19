#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void printLista(list<double> l, int t);

int main ()
{
    list<double> lista;   
    double n, maior;
    cin >> n; 
    maior = n;
    while (n != 0)
    {
        int x = count(lista.begin(), lista.end(), n);
        if (x != 1)
        {
            lista.push_back(n); 
        }
        if (n > maior) maior = n;

        cin >> n;
    }
    cout << "Maior: " << maior
    << "\nValores: ";
    printLista(lista, 0);
    cout << "Reversa: ";
    printLista(lista,1);
    
}

void printLista(list<double> l, int t)
{
    if (t == 0) // ordem normal
    { 
        for (double i:l)
        {
            cout << i << " ";
        }
    }
    else // ordem reversa
    { 
        for(auto it=l.rbegin(); it!=l.rend(); it++)
        {
            cout << *it << " ";
        }
    }
    cout << endl;
}

