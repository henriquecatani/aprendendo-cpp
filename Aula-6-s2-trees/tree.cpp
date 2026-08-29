//BIblioteca de arvore
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

namespace tree{
    //struct de cada nodo da árvore
    struct node{
        std::string value;
        node *left;
        node *right;
    };

    node *create_node(const std::string &str_value){
        node *p = new node;
        p->value = str_value;
        p->left = nullptr;
        p->right = nullptr;

        return p;
    }

    //Função que retornar o tamanho da árvor
    int height(node *root){
        if(root == nullptr){
            return -1;
        }
        return std::max(height(root->left),height(root->right))+1;
    }

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

    void DFS_pre(node *root){ //Percorrer em pré ordem
        if(!root) return;
        std::cout << root->value << ' ';
        DFS_pre(root->left);
        DFS_pre(root->right);
    }

    void DFS_in(node *root){ //Percorrer em in order
        if(!root) return;
        DFS_in(root->left);
        std::cout<< root->value << ' ';
        DFS_in(root->right);
    }

    void DFS_post(node *root){ //Percorrer em post order
        if(!root) return;
        DFS_post(root->left);
        DFS_post(root->right);
        std::cout << root->value << ' ';
    }

    void BSF(node *root){ //Percorre em largura
        if(!root) return;
        std::queue<node *> fila;
        fila.push(root);
        while(!fila.empty()){
            node *aux = fila.front();
            std::cout << aux->value << ' ';
            fila.pop();
            if(aux->left)
                fila.push(aux->left);
            if(aux->right)
                fila.push(aux->right);        
        }

    }

    //implementa a inserção em uma árvore binária de pesquisa
    void BST_insert(node * &root, const std::string &val){
        if(!root)
            root = create_node(val);
        else if(val < root->value)
            BST_insert(root->left,val);
        else
            BST_insert(root->right,val);    
    }

    //Pesquisar um valor na BST
    // se encontrar: Retornar o pointer para o node
    // se ñ encontrar: retorna nullptr
    node* BST_find(node * &root, const std::string &val){
        if (!root || root->value == val)
            return root;
        if (root->value > val) {
            return BST_find(root->left, val);
        }
        if (root->value > val) {
            return BST_find(root->right, val);

        }

    }


}