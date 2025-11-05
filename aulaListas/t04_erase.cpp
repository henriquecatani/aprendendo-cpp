/*
 Implementar na biblioteca "list.cpp" a seguinte função:

    void l.erase(UPF::node* p)

 Ela recebe um ponteiro para um nodo p.
 Remover o nodo apontado da lista, liberando a memória ocupada e atualizar o tamanho da lista.

 Usar o programa abaixo para validar a implementação
*/

#include <cassert>
#include <iostream>

#include "list.cpp"

using namespace std;

int main() {
  UPF::list l;

  // Preparando a lista para os testes
  l.push_back("aa");
  l.push_back("bb");
  l.push_back("cc");
  l.push_back("dd");
  l.push_back("ee");

  l.erase(l.first);  // Apaga o primeiro nodo da lista
  assert(l.size() == 4);
  assert(l.first != nullptr);
  assert(l.first->value == "bb");
  assert(l.first->next != nullptr);
  assert(l.first->previous == nullptr);

  l.erase(l.last);  // Apaga o primeiro nodo da lista
  assert(l.size() == 3);
  assert(l.last != nullptr);
  assert(l.last->value == "dd");
  assert(l.last->previous != nullptr);
  assert(l.last->next == nullptr);

  auto p = l.find("cc");
  l.erase(p);
  assert(l.size() == 2);
  assert(l.first != nullptr);
  assert(l.first->value == "bb");
  assert(l.first->next != nullptr);
  assert(l.first->next->value == "dd");
  assert(l.first->next->previous == l.first);
  assert(l.last != nullptr);
  assert(l.last->value == "dd");
  assert(l.last->previous != nullptr);
  assert(l.last->previous->value == "bb");
  assert(l.last->previous->next == l.last);

  cout << "\nPassed!\n";
  return 0;
}
