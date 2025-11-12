#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main(){

    list<int> lista{10,200,208,41,20,150,208,-18};
    int alvo;
    cin >> alvo;

    //Remover o valor que o usuario digitou
    lista.remove(alvo);
    //Remover os maiores que o int digitado pelo user
    lista.remove_if([alvo](auto n) {return n > alvo;});

    int contador = count_if(lista.begin(),lista.end(),
                           [](int n){return n >150;});

    cout << contador << endl;

    for( auto n:lista){
        cout << n << " ";
    }


    return 0;
}
