/*
 Implementar na biblioteca "list.cpp" a seguinte função:

UPF::node* find(const std::string &s)
    Ela recebe uma string s.
    Retornar ponteiro para o primeiro nodo que contêm valor igual a s.
    Retornar nullptr caso o valor não seja encontrado.

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
  l.push_back("aa");
  l.push_back("dd");

  // Bateria de testes
  assert(l.find("aa") != nullptr);
  assert(l.find("aa") == l.first);
  assert(l.find("bb") != nullptr);
  assert(l.find("bb") == l.first->next);
  assert(l.find("cc") != nullptr);
  assert(l.find("dd") != nullptr);
  assert(l.find("dd") == l.last);
  assert(l.find("ee") == nullptr);
  assert(l.find("ddd") == nullptr);

  cout << "\nFim (OK)!\n";
  return 0;
}
