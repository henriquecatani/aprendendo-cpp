/*
Implementar na biblioteca "list.cpp" as seguintes funções:

int size()
   Retorna o tamanho (quantidade de elementos) da lista.

void push_front(std::string &s)
   Ela recebe uma string, insere no início da lista um novo nodo contendo o
   valor passado e atualizar o tamanho da lista.

Usar o programa abaixo para validar a implementação
*/
#include <cassert>
#include <iostream>

#include "list.cpp"

using namespace std;

int main() {
  UPF::list l;

  l.push_front("aa");
  assert(l.size() == 1);
  assert(l.first != nullptr);
  assert(l.first == l.last);
  assert(l.first->previous == nullptr);
  assert(l.first->next == nullptr);
  assert(l.first->value == "aa");

  l.push_front("bb");
  assert(l.size() == 2);
  assert(l.first != nullptr);
  assert(l.first != l.last);
  assert(l.first->value == "bb");
  assert(l.first->previous == nullptr);
  assert(l.first->next != nullptr);
  assert(l.first->next == l.last);
  assert(l.first->next->value == "aa");
  assert(l.last->next == nullptr);
  assert(l.last->previous == l.first);

  l.push_front("cc");
  assert(l.size() == 3);
  assert(l.first != nullptr);
  assert(l.first != l.last);
  assert(l.first->value == "cc");
  assert(l.first->previous == nullptr);
  assert(l.first->next != nullptr);
  assert(l.first->next->value == "bb");
  assert(l.first->next->next != nullptr);
  assert(l.first->next->next->value == "aa");
  assert(l.last->next == nullptr);

  cout << "\nPassed!\n";
  return 0;
}
