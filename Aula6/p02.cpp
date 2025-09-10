#include <iostream>
using namespace std;

struct aluno{
    int matricula;
    string nome;
    float nota;
};

void exibeAluno(aluno a);
aluno criaAluno();

int main(){
    aluno henrique; // variavel do tipo aluno

    // inserindo dados na variavel tipo aluno
    henrique.matricula = 210305;
    henrique.nome = "Henrique Catani";
    henrique.nota = 9.9;
    exibeAluno(henrique);

    cout << "Adicionando aluno... " << endl;
    aluno a1 = criaAluno();
    exibeAluno(a1);
    
    aluno a2 = {210200, "Othavio", 5.6};

    return 0;
}

void exibeAluno(aluno a){
    cout << "Matr.: " << a.matricula << endl;
    cout << "Nome: "  << a.nome << endl;
    cout << "Nota: "  << a.nota << endl; 
    if (a.nota < 6){
        cout << "Reprovado!" << endl;
    }
    else{
    cout << "Aprovado! " << endl;
    }
}

aluno criaAluno(){
    aluno a;
    cout << "Diga o nome: " << endl;
    getline(cin,a.nome);
    cout << "Diga a matricula: " << endl;
    cin >> a.matricula;
    cout << "Diga a nota: " << endl;
    cin >> a.nota;
    return a;
}
