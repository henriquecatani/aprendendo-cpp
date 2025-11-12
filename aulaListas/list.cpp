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

        int count(const std::string &s)
        {
        /* 
        int count(const std::string &s)
        Recebe uma string s, conta e retorna a quantidade de nodos que contêm seu
        valor igual a s
        */
            node *it = first;
            int cnt = 0;
            while(it != nullptr)
            {
            if (it->value == s)
            {
                cnt++;
            }
            it = it->next;
            }
            return cnt;
        }

        UPF::node* find(const std::string &s){

        /*
        UPF::node* find(const std::string &s)
        Recebe uma string s.
        Retornar ponteiro para o primeiro nodo que contêm valor igual a s.
        Retornar nullptr caso o valor não seja encontrado.
        */
            node *it = first;
            while(it != nullptr)
            {
                if (it->value == s)
                {
                    return it;
                }
                it = it->next;
            }
            return nullptr;
        }
        void erase(UPF::node *p)
        {
            if (p == first) // deletando o primeiro
            {
                first = first->next;
                first->previous = nullptr;
            }
            if (p == last) // deletando o ultimo
            {
                last = last->previous;
                last->next = nullptr;
            }
            if (p->previous != nullptr) // existe um anterior
            {
                p->previous->next = p->next; // o proximo do atual se torna o proximo do anterior, para excluir o atual
            }
            if (p->next != nullptr) // existe um proximo
            {
                p->next->previous = p->previous;
            }
            delete p;
            num_nodes--;
        }
        void pop_front()
        {
            erase(first);
        }
        void pop_back()
        {
            erase(last);
        }
        void remove(const std::string &s)
        {
            /*
            for (int i = 0; i < count(s); i++)
            {
                    erase(find(s));
            } */
            
            node *it = first;
            while(it != nullptr)
            {
                if (it->value == s)
                {
                    erase(it);
                }
                it = it->next;
            }
        }
    };

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

