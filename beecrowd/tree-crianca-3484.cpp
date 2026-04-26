/*
beecrowd | 3484 - Turma Dividida
Por Marcos José Brusso, UPF
lvl 2

Na escola Brincadeira e Sabedoria Total, a turma do 5º ano está sempre curiosa para a chegada do recreio, pois a professora incentiva seus alunos a aprenderem de maneiras divertidas e criativas. Numa tarde de sol, ela pensou em dividir os alunos em duas filas, com os mais altos na direita e os mais baixos na esquerda. Mas depois a professora percebeu que poderia ficar mais divertido se cada fila fosse sempre subdividida em duas com esta mesma lógica. Então ela definiu as seguintes regras para a brincadeira:

    Início da Fila: A primeira criança a entrar na brincadeira fica na frente da fila.
    Comparação de Altura: Cada nova criança que entrar na brincadeira compara sua altura com a da primeira criança:
        Se for mais baixa, vai para a fila da esquerda.
        Se for mais alta, vai para a fila da direita.
    Subdivisões das Filas: Cada vez que uma criança chega na posição já ocupada por outra criança, ela compara sua altura com a altura daquele/a colega até encontrar uma posição livre:
        Se for mais baixa, continua indo para a esquerda.
        Se for mais alta, continua indo para a direita.
        Ao encontrar uma posição livre, fica lá.

Por exemplo, dada a seguinte sequência de crianças entrando na brincadeira, com a respectiva altura anotada em centímetros [130, 120, 140, 115, 125, 135, 145, 142, 138] a turma ficaria organizada com a seguinte disposição:

Como a brincadeira se mostrou divertida, a professora solicitou que você escrevesse um programa que, dada a ordem de entrada dos alunos na brincadeira, exibe qual é a altura da menor criança que está em cada um dos níveis desta estrutura. Entende-se por nível a distância entre a que está no início da fila (a primeira a entrar) e cada uma das demais, considerando-se um espaçamento uniforme.
Entrada

A entrada contém um único caso de teste. A primeira linha contém um inteiro N (1 ≤ N < 250) indicando a quantidade de alunos na turma. A segunda linha vai conter N inteiros H1, H2, ...., Hn representando a altura em centímetros de cada um dos alunos (50 ≤ Hi ≤ 300). Considerar que não existem dois estudantes com exatamente a mesma altura em uma turma.

Saída
A saída é formada por uma sequência de linhas contendo dois inteiros separados por espaço: o número do nível (iniciando em 0) e a altura da menor criança que está posicionada naquele nível.

Exemplos de Entrada / Saída

9
130 120 140 115 125 135 145 142 138
	
0 130
1 120
2 115
3 138

---
3
100 120 115

0 100
1 120
2 115

---
3
115 120 110

0 115
1 110

*/
#include <iostream>
#include <string>

using std::cin, std::cout, std::endl;

struct node{
    int value; //INFORMAÇÃO
    node *left;  //FILHO DA ESQUERDA
    node *right; //FILHO DA DIREITA
};

node *create_node(const int &val){
    node *p = new node;
    p->value = val;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void BST_insert(node * &root, const int &val){
    if(!root)
        root = create_node(val);
    else if(val < root->value)
        BST_insert(root->left,val);
    else
        BST_insert(root->right,val);    
}

int listarMenorPorNivel (node * &root, int nivelAtual = 0, int nivelMaximo = -1) 
{
    if (!root) return nivelMaximo;

    if (nivelAtual > nivelMaximo) 
    {
        cout << nivelAtual << " " << root->value << endl;
        nivelMaximo++;
    }

    nivelMaximo = listarMenorPorNivel(root->left, nivelAtual + 1, nivelMaximo);
    nivelMaximo = listarMenorPorNivel(root->right, nivelAtual + 1, nivelMaximo);

    return nivelMaximo;
}

int main ()
{
    int N; // qtd alunos na turma
    int altura;

    cin >> N;
    cin >> altura;
    node *root = create_node(altura);
    N--;
    
    while (N--)
    {
        cin >> altura;
        BST_insert(root, altura);
    }
    
    listarMenorPorNivel(root);

    return 0;
}
