#include <iostream>
#include "../Aula-6-s2-trees/tree.cpp"

using namespace std;
using namespace tree;

int main()
{
    node *root = nullptr;
    string val;
    while(cin>> val && val != "exit"){

        
        if (BST_find(root,val))
        {
            cout << "Já foi inserido\n";
        } else {
            BST_insert(root,val);
        }
    }
    BSF(root);
    return 0;
}