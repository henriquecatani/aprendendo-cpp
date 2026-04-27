/*
beecrowd | 1201 - Operações em ABP II
lvl 7
Marcela nem terminou de fazer o programa anterior e o professor já lhe pediu um novo programa,
com aprimoramentos sobre o programa anterior. Este novo programa é a implementação de
uma Árvore Binária de Pesquisa (ou Busca) mas utilizando números inteiros agora,
e que deve aceitar um comando extra (R) com relação ao programa anterior:

    I n: Insere na árvore binária de pesquisa o elemento n.
    INFIXA: lista os elementos já inseridos segundo o percurso infixo
    PREFIXA: lista os elementos já inseridos segundo o percurso prefixo
    POSFIXA: lista os elementos já inseridos segundo o percurso posfixo
    P n: Pesquisa se o elemento n existe ou não na árvore.
    R n: Remove o elemento n da árvore, caso ele exista.

A qualquer momento pode-se inserir um elemento, 
visitar os elementos previamente inseridos na ordem infixa, prefixa ou posfixa,
procurar por um elemento na árvore para saber se o elemento existe ou não 
ou ainda retirar um elemento.

Nota: Se um elemento com duas sub-árvores (direita e esquerda) for removido,
o antecessor (o elemento maior de sub-árvore esquerda, deve ocupar o seu lugar
e ao tentar retirar um elemento que não existe, nenhuma mensagem deve ser apresentada.

Entrada
A entrada contém N operações utilizando números inteiros (1-106) sobre uma árvore binária de Busca,
que inicialmente se encontra vazia. A primeira linha de entrada contém a inserção de algum elemento.
As demais linhas de entrada podem conter quaiquer um dos comandos descritos acima, conforme exemplo abaixo.
O final da entrada é determinado pelo final de arquivo (EOF).

Saída
Cada linha de entrada, com exceção das linhas que contém os comandos "I" ou "R", deve produzir uma linha de saída.
A saída deve ser de acordo com o exemplo fornecido abaixo. 
Não deve haver espaço em branco após o último caractere de cada linha, 
caso contrário, sua submissão receberá Presentation Error.

Exemplo de Entrada
I 5
I 2
I 4
I 1
INFIXA
PREFIXA
POSFIXA
P 3
P 1
INFIXA
R 1
INFIXA

Exemplo de Saída
1 2 4 5
5 2 1 4
1 4 2 5
3 nao existe
1 existe
1 2 4 5
2 4 5
*/

#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;

struct node{
    int value; //INFORMAÇÃO
    node *left;  //FILHO DA ESQUERDA
    node *right; //FILHO DA DIREITA
};

node *create_node(int value){
    node *p = new node;
    p->value = value;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void BST_insert(node * &root, int val){
    if(!root)
        root = create_node(val);
    else if(val < root->value)
        BST_insert(root->left,val);
    else if(val > root->value)
        BST_insert(root->right,val);
}

void DFS_pre(node *root, bool &isFirst){ //Percorrer em pré ordem
    if(!root) return;

    if(!isFirst) cout << ' ';
    cout << root->value; // Exibe o nodo
    isFirst = false;

    DFS_pre(root->left, isFirst);// chama a função passando o nodo filho a esq
    DFS_pre(root->right, isFirst);// chama a função passando o nodo filho a dir
}
void DFS_in(node *root, bool &isFirst){ //Percorrer em in order
    if(!root) return;

    DFS_in(root->left, isFirst);

    if(!isFirst) cout << ' ';
    cout << root->value;
    isFirst = false;

    DFS_in(root->right, isFirst);
}

void DFS_post(node *root, bool &isFirst){ //Percorrer em post order
    if(!root) return;

    DFS_post(root->left, isFirst);
    DFS_post(root->right, isFirst);

    if(!isFirst) cout << ' ';
    cout << root->value;
    isFirst = false;
}

bool BST_search (node *root, int val)
{
    if (!root) return false;
    if (root->value == val) return true;

    if (val < root->value) 
        return BST_search(root->left, val);

    return BST_search(root->right, val);
}

node* BST_findMax (node* root) 
{
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

node* BST_remove (node* root, int val) 
{
    if (!root) return root;

    if (val < root->value)
        root->left = BST_remove(root->left, val);
    else if (val > root->value)
        root->right = BST_remove(root->right, val);
    else 
    {
        if (!root->left) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = BST_findMax(root->left);
        root->value = temp->value;
        root->left = BST_remove(root->left, temp->value);
    }
    return root;
}

int main () 
{
    node *root = nullptr;
    std::string comando;
    int value;

    while (cin >> comando) 
    {
        if (comando == "I") {
            cin >> value;
            BST_insert(root, value);
        } 
        else if (comando == "INFIXA") {
            bool isFirst = true;
            DFS_in(root, isFirst);
            cout << endl;
        } 
        else if (comando == "PREFIXA") {
            bool isFirst = true;
            DFS_pre(root, isFirst);
            cout << endl;
        } 
        else if (comando == "POSFIXA") {
            bool isFirst = true;
             DFS_post(root, isFirst);
            cout << endl;
        } 
        else if (comando == "P") {
            cin >> value;
            cout << value << ' ' << (BST_search(root, value) ? "existe" : "nao existe") << endl;
        } 
        else if (comando == "R") {
            cin >> value;
            root = BST_remove(root, value);
        }
    }

    return 0;
}

