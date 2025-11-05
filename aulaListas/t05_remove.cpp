/*
 Implementar na biblioteca "list.cpp" a seguinte função:

    void remove(const std::string &s)

 Ela recebe uma string s e remove todos os nodos da lista cujo valor é igual a s.

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
  l.push_back("zz");
  l.push_back("cc");
  l.push_back("zz");
  l.push_back("ee");

  l.remove("aa");  
  assert(l.size() == 4);
  assert(l.first != nullptr);
  assert(l.first->value == "zz");
  l.remove("ee"); 
  assert(l.size() == 3);
  assert(l.last != nullptr);
  assert(l.last->value == "zz");
  assert(l.last->previous != nullptr);
  assert(l.last->next == nullptr);

  l.remove("zz"); 
  assert(l.size() == 1);
  assert(l.first != nullptr);
  assert(l.first->value == "cc");
  assert(l.first->next == nullptr);
  assert(l.first->previous == nullptr);
  assert(l.last==l.first);

  cout << "\nPassed!\n";
  return 0;
}
