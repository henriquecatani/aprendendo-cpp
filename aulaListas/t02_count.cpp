/*
 Implementar na biblioteca "list.cpp" a seguinte função:

    int count(const std::string &s)

 Ela recebe uma string s, conta e retorna a quantidade de nodos que contêm seu
 valor igual a s

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
  l.push_back("cc");
  l.push_back("aa");
  l.push_back("dd");

  l.print();

  // Bateria de testes
  assert(l.count("aa") == 3);
  assert(l.count("bb") == 1);
  assert(l.count("cc") == 2);
  assert(l.count("ee") == 0);
  assert(l.count("aaa") == 0);

  cout << "\nFim (OK)!\n";
  return 0;
}
