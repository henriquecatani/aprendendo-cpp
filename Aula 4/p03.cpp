#include<iostream>
using namespace std;

void dobrar(int v[], int tamanho){
    for(int i = 0; i<tamanho; i++){
        v[i] = v[i] * 2;
        // vetor sempre altera direto no endereco da memoria, mesmo sem &
    }
}

int main(void){
    int vetor[3] = {1,2,3};
    for(int i = 0; i<3; i++){
        cout << vetor[i] << " ";    
    }
    return 0;
}