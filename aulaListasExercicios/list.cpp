//Biblioteca para lista duplamente encadeada
#include <iostream>
#include <string>

namespace UPF{

struct node{
    std::string  value; // VALOR
    node *previous = nullptr; // Nodo anterior
    node * next = nullptr; //Nodo posterior
};

struct list{
    // VARIAVEIS DE CONTROLE
    node *first = nullptr; // primeiro nodo
    node *last  = nullptr; // ultimo elemento
    int num_nodes = 0; //Quantidade de nodos

    //funções da biblioteca

    int size(){
        return num_nodes;
    }

    void push_front(const std::string &s){
        num_nodes++;
        node *p = new node; //Alocando um espaço de mem. p/ o nodo
        p->value = s;
        p->previous = nullptr;
        p->next = first;
        if(first != nullptr) //Já existem valores inseridos (lista não esta vazia)
            first->previous = p;
        first = p;
        if(last == nullptr) // LISTA VAZIA
            last = p;

    }

    void push_back(const std::string &s){
        num_nodes++;
        node *p = new node; //aloca memoria
        p->value = s;
        p->next = nullptr;
        p->previous = last;
        if(last != nullptr) //Não é nulo, ja existem elementos
            last->next = p;
        
        last = p;

        if(first == nullptr) // Em caso de lista ainda vazia. ALém do ultimo, será também o primeiro
            first = p;
    }

    void print(){
        node *p = first; // pega o valor do primeiro nodo
        while(p!=nullptr){
            std::cout<<'"'
                     <<p->value
                     << '"'
                     << " ";
            p = p->next;
        }
        std::cout<< std::endl;
        
    }

    int count(const std::string &s){ //s é o elemento que eu quero encontrar
        node *p = first; // pega o valor do primeiro nodo
        int n=0; //Contador. Fará a contagem de quantas vezes o S(parametro) apareceu na lists
        while(p!=nullptr){
            if(p->value == s){
                n++;
            }
            p = p->next;  // o P irá receber o proximo nodo     
           
        }      
        return n;      

    }

    UPF::node* find(const std::string &s){
        node *p = first; // pega o valor do primeiro nodo
        while(p!=nullptr){
            if(p->value == s){
                return p;
            }
            p =p->next;
        }
        return nullptr;//so chegará aqui se não encontrar o elemento na lista
    }

    void erase(UPF::node *p){
        if(p == first){ // deletando o 1º
            first = first->next;
            first->previous = nullptr;
        }
        if(p==last){ // deletando o ultimo
            last = last->previous;
            last->next = nullptr;
        }
        if(p->previous != nullptr){ //Existe um anterior
            p->previous->next = p->next;
        }

        if(p->next != nullptr){
            p->next->previous = p->previous; 
        }
        delete p;
        num_nodes--;

    }

    void pop_front(){  //Remover o primeiro
        erase(first);
    }
    void pop_back(){ // Remover o ultimo
        erase(last);
    }

    //Ela recebe uma string s e remove todos os nodos da lista cujo valor é igual a s.
    void remove(const std::string &s){ 
        node *p = first; // pega o valor do primeiro nodo
        while(p!=nullptr){
            if(p->value == s){
                erase(p);
            }
            p =p->next;
        }
    }
};
} //namespace upf