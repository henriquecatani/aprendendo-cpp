/*
beecrowd | 1466 - Percurso em Árvore por Nível
lvl 3

Em uma árvore binária, o percurso por nível é um percurso denominado breadth first search (BFS) ou em português, busca em largura, a qual seria não-recursiva por natureza. Este percurso utiliza uma fila ao invés de pilha para armazenar os próximos 2 nodos que devem ser pesquisados (filho à esquerda e à direita). Esta é a razão pela qual você deve percorrer os nodos na ordem FIFO ao invés da ordem LIFO, obtendo desta forma a recursão.

Portanto nossa tarefa aqui, após algumas operações de inserção sobre uma árvore binária de busca (pesquisa), é imprimir o percurso por nível sobre estes nodos. Por exemplo, uma entrada com a sequência de valores inteiros: 8 3 10 14 6 4 13 7 1 resultará na seguinte árvore:

Com a saída de uma listagem por nível: 8 3 10 1 6 14 4 7 13.
Entrada

A entrada contém vários casos de teste. A primeira linha da entrada contém um inteiro C (C ≤ 1000), indicando o número de casos de teste que virão a seguir. Cada caso de teste é composto por 2 linhas. A primeira linha contém um inteiro N (1 ≤ N ≤ 500) que indica a quantidade de números que deve compor cada árvore e a segunda linha contém N inteiros distintos e não negativos, separados por um espaço em branco.
Saída

Para cada caso de teste de entrada você deverá imprimir a mensagem "Case n:", onde n indica o número do caso de teste seguido por uma linha contendo a listagem por nível dos nodos da árvore, conforme o exemplo abaixo.

Obs: Não deve haver espaço em branco após o último item de cada linha e há uma linha em branco após cada caso de teste, inclusive após o último. A árvore resultante não terá nodos repetidos e também não terá mais do que 500 níveis.

Sample Input 	
2
3
5 2 7
9
8 3 10 14 6 4 13 7 1
	
Sample Output
Case 1:
5 2 7

Case 2:
8 3 10 1 6 14 4 7 13 
*/


#include <iostream>
#include <string>
#include <queue>
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

void BSF(node *root, bool &isFirst) {
    if(!root) return;
    std::queue<node *> fila; // A fila guardará o endereço de memória dos nodos
    fila.push(root);

    while(!fila.empty()) 
    {
        node *aux = fila.front();

        if(!isFirst) std::cout << ' ';
        std::cout << aux->value;
        isFirst = false;

        fila.pop();

        if(aux->left) // se existe filho a esquerda
            fila.push(aux->left);
        if(aux->right) //Se existe filho a direita
            fila.push(aux->right);        
    }
}

int main () 
{
    int C, N, value;
    cin >> C;

    for ( int i = 1; i <= C; i++ ) 
    {
        node *root = nullptr;
        cin >> N;

        for ( int j = 0; j < N; j++ ) {
            cin >> value;
            BST_insert(root, value);
        }
        
        cout << "Case " << i << ":" << endl;
        bool isFirst = true;
        BSF(root, isFirst);
        cout << endl << endl;
    }
    return 0;
}