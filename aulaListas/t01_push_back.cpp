/*
 Implementar na biblioteca "list.cpp" as seguintes funções:

void push_back(const std::string &s)
    Ela recebe uma string, insere no final da lista um novo nodo contendo o
    valor passado e atualizar o tamanho da lista.

void print()
    Exibe os valores contidos na lista, delimitados por aspas duplas,
    separados por espaço, terminado por um endl.
    O exemplo abaixo deve printar:  "aa" "bb" "cc"

 Usar o programa abaixo para validar a implementação
*/

#include <cassert>
#include <iostream>

#include "list.cpp"

using namespace std;

int main() {
  UPF::list l;

  l.push_back("aa");
  assert(l.size() == 1);
  assert(l.first != nullptr);
  assert(l.first == l.last);
  assert(l.first->previous == nullptr);
  assert(l.first->next == nullptr);
  assert(l.first->value == "aa");

  l.push_back("bb");
  assert(l.size() == 2);
  assert(l.last != nullptr);
  assert(l.first != l.last);
  assert(l.first->value == "aa");
  assert(l.last->value == "bb");
  assert(l.first->previous == nullptr);
  assert(l.first->next == l.last);
  assert(l.first->next->value == "bb");
  assert(l.last->next == nullptr);
  assert(l.last->previous == l.first);

  l.push_back("cc");
  assert(l.size() == 3);
  assert(l.last != nullptr);
  assert(l.first != l.last);
  assert(l.first->value == "aa");
  assert(l.first->next != nullptr);
  assert(l.first->next->value == "bb");
  assert(l.first->next->next != nullptr);
  assert(l.first->next->next->value == "cc");
  assert(l.last->value == "cc");
  assert(l.last->next == nullptr);
  assert(l.last->previous != nullptr);
  assert(l.last->previous == l.first->next);

  l.print();
  cout << "\nPassed!\n";
  return 0;
}
