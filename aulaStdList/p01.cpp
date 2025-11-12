#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> lista;
    lista.push_front(10); //Insere no inicio
    lista.push_back(20); //Insere no final
    lista.push_front(30);
    lista.push_back(40);


    // 30,10,20,40
    //lista.pop_back(); // Remover a calda
    //lista.pop_front(); //Remove o head

    cout << "Size: " << lista.size() << endl;

    for(auto n: lista){
        cout << n << endl;
    }

    //ordem reversa
    for(auto it=lista.rbegin(); it!=lista.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //uso do advance
    auto it = lista.begin(); // end. mem. do inicio da lista
    cout << *it << endl;
    advance(it,2); //Avança duas "casas" ao ponteiro iterator
    cout << *it << endl;

    return 0;
}