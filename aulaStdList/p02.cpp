#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> lista{10,200,208,41,20,150,208,-18};

    //lista.remove(208);//Remove todas as ocorrencias 
    //lista.remove_if([](auto n){return n%2=0;}); //Remove os pares
    //Remove os maiores que 50
    //lista.remove_if([](auto n){return n >50;});     
    //remove os negativos
    //lista.remove_if([](auto n){return n<0;});

    //Neste exemplo ordenaremos na propria função sort da list
    lista.sort([](int a, int b){return a < b;});  
    
    for( auto n:lista){
        cout << n << " ";
    }


    return 0;
}