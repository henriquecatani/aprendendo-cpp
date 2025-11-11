// BIBLIOTECA PARA LISTA DUPLAMENTE ENCADEADA
#include<iostream>
#include<string>

namespace UPF{
    struct node 
    {
        std::string value;
        node *previous = nullptr; // ponteiro nodo anterior
        node *next = nullptr;// ponteiro nodo proximo
    };

    struct list
    {
        node *first = nullptr; // ponteiro primeiro nodo
        node *last  = nullptr; // ponteiro ultimo nodo
        int num_nodes = 0; // tamanho da lista, qtd de nodos
        
        // == funcoes ==
        int size()
        {
            return num_nodes;
        }

        void push_front(const std::string &s)
        {
            num_nodes++;
            node*p = new node;
            p->value = s;
            p->previous = nullptr;
            p->next = first;
            if(first != nullptr) // nao eh nulo, existem elementos na lista
                first -> previous = p;
            first = p;

            if(last == nullptr) // lista vazia
                last = p;
        }

        void push_back(const std::string &s)
        {
            num_nodes++;
            node *p = new node;
            p->value = s;
            p->next = nullptr;
            p->previous = last;

            if(last != nullptr)
                last->next = p;
            
            last = p;
            if(first == nullptr)
                first = p;

        }

        void print()
        {
            node *it = first;
            while(it != nullptr)
            {
                std::cout << '"' << it->value << '"' << ' ';
                it = it->next;
            }
            std::cout<< std::endl;

        }
    };

    /*
 Implementar na biblioteca "list.cpp" a seguinte função:

    int count(const std::string &s)

 Ela recebe uma string s, conta e retorna a quantidade de nodos que contêm seu
 valor igual a s

 Usar o programa abaixo para validar a implementação
*/
    int count(const std:string &s){
	   node *it = first;
	   int cnt = 0;
	   while(it != nullptr)
	   {
		   if (it->value == s)
		   {
			   cnt++;
		   }
		   it = i->next
	   }
	   return cnt;
    }

/*
 Implementar na biblioteca "list.cpp" a seguinte função:

UPF::node* find(const std::string &s)
    Ela recebe uma string s.
    Retornar ponteiro para o primeiro nodo que contêm valor igual a s.
    Retornar nullptr caso o valor não seja encontrado.

 Usar o programa abaixo para validar a implementação
*/
    int count(const std::string &s){
        node *it = first;
        while(it != nullptr)
        {
            if (it->value == p)
	    {
		    return it;
	    }
	    it = it->next;
        }
	return nullptr;
    }

}

/*
uma lista usa enderecos aleatorios para cada elemento
em uma lista duplamente encadeada, cada elemento armazena o 
endereco anterior e o proximo.\
push back: insere elemento, prox null,
encadeia o anterior (prox do anterior = endereco novo)
ant = end, 
depois atualiza o end e o tamanho
*/

