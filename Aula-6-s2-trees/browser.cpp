#include <iostream>
#include "tree.cpp"

using namespace tree;
using namespace std;

int main ()
{
    node *root = create_node("pagina inicial");
    node *atual = root;
    string input;
    cin >> input;
    while (input != "exit")
    {
        cout << "Você está em: " << atual->value << endl;
        cout << "Input (l/r): ";
        cin >> input;
        if (input == "l")
        {
            if (atual == root) {
                cout << "você está na pag inicial!\n";
            }
        } else if (input == "r")
        {

        }
    }
}