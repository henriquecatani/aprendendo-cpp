//BIblioteca de arvore
#include <iostream>
#include <string>
#include <algorithm>

namespace tree{
    //struct de cada nodo da árvore
    struct node{
        std::string value; //INFORMAÇÃO
        node *left;  //FILHO DA ESQUERDA
        node *right; //FILHO DA DIREITA
    };

    node *create_node(const std::string &str_value){
        node *p = new node;
        p->value = str_value;
        p->left = nullptr;
        p->right = nullptr;

        return p;
    }

    //Função que retornar o tamanho da árvor
// A
//      B De
    //root é a raiz
    int height(node *root){
        if(root == nullptr){
            return -1;
        }
        return std::max(height(root->left),height(root->right))+1;

                
    }

    // henrique
    void show(node *root, int ident = 0)
    {
        int identl = ident;
        int identr = ident;
        if (root == nullptr) return;
        std::cout << root->value << "\n";
        if (root->left != nullptr)
        {
            identl++;
            std::cout << std::string(identl,' ') << "l: ";
            show(root->left, identl);
        }
        if (root->right != nullptr)
        {
            identr++;
            std::cout << std::string(identr, ' ') << "r: ";
            show(root->right, identr);
        }

        return;

    }

}