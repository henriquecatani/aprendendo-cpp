// Biblioteca para lista duplamente encadeada
#include <iostream>
#include <string>

namespace UPF {
struct node {
  std::string value;  // Valor
  node *previous;     // Nodo anterior
  node *next;         // Próximo nodo
};

struct list {
  node *first = nullptr;  // Primeiro nodo
  node *last = nullptr;   // Último nodo
  int num_nodes = 0;      // Quantidade de nodos

  int size() { return num_nodes; }

  void push_front(const std::string &s) {
    num_nodes++;
    node *p = new node;
    p->value = s;
    p->previous = nullptr;
    p->next = first;
    if (first != nullptr) first->previous = p;
    first = p;
    if (last == nullptr) last = p;
  }

  void push_back(const std::string &s) {
    num_nodes++;
    node *p = new node;
    p->value = s;
    p->next = nullptr;
    p->previous = last;
    if (last != nullptr) last->next = p;
    last = p;
    if (first == nullptr) first = p;
  }

  int count(const std::string &s) {
    int n = 0;
    node *p = first;
    while (p != nullptr) {
      if (p->value == s) n++;
      p = p->next;
    }
    return n;
  }

  node *find(const std::string &s) { /// Encontra a primeira ocorrença da string s
    node *p = first;
    while (p) {
      if (p->value == s) return p;
      p = p->next;
    }
    return nullptr;
  }

  void print() {
    node *p = first;
    while (p != nullptr) {
      std::cout << '"' << p->value << '"' << ' ';
      p = p->next;
    }
    std::cout << '\n';
  }

  void erase(UPF::node *p) { // Remove um nodo em específico
    if (p == first)         // Deletando o primeiro nodo da lista
      first = first->next;  // O primeiro passa a ser o segundo da lista

    if (p == last)            // Deletando o último
      last = last->previous;  // o último passa a ser o penúltimo

    if (p->next != nullptr)             // Existe um posterior?
      p->next->previous = p->previous;  // Posterior aponta para anterior

    if (p->previous != nullptr)     // Existe um anterior?
      p->previous->next = p->next;  // Anterior aponta para o posterior

    num_nodes--;
    delete p;
  }

  void pop_front() { erase(first); }

  void pop_back() { erase(last); }

  void remove(const std::string &s) {
    node *p = find(s);      // Procura a primeira ocorrência
    while (p != nullptr) {  // enquanto achou
      erase(p);             // delete aquele nodo
      p = find(s);          // procura a próxima ocorrência
    }
  }

  void insere_apos(const std::string &s1,const std::string &s2){     ///Insere a string s1 após a string s2   
        node *f = find(s2);
        if (first == nullptr || f == nullptr){   
            push_back(s1);              
        } else {
             node *p = new node();
             p->previous = f;
             p->next = f->next;
             p->value = s1;
             f->next = p;
             f->next->previous = p; 
            if(f == last){
              last= p;
            } 
            num_nodes ++;        
        }             
  }

  void print_reverse(){
    node *p = last;
    while (p != nullptr) 
    {
      std::cout << '"' << p->value << '"' << ' ';
      p = p->previous;
    }
    std::cout << '\n';
}


  
};
}  // namespace UPF