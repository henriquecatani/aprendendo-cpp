#include<utility>
template <typename T>
void bubblesort(T vet[], int n){
    /*
    Algoritmo de ordenação bubblesort:
    roda o vetor diversas vezes, trocando um
    número por vez. Se o número da frente é
    maior do que o número a seguir, eles trocam.
    Se for menor ou igual, passa adiante.
    Muito lento.
    */
    bool trocou; // variavel de controle
    do{
        trocou = false;
        for(int i = 0; i < n - 1; i++){
            if(vet[i]>vet[i+1]){
                std::swap(vet[i],vet[i+1]); // realiza a troca
                trocou = true;
            }
        }

    }while(trocou);
}

template <typename T>
void selectionsort(T vet[], int n){
    /*
    roda todo vetor procurando o menor valor, depois
    troca a posição do valor menor com a posição correta
    ex.:
    5 6 9 12 2 7 14 3
    2 6 9 12 5 7 14 3
    2 3 9 12 5 7 14 6    
    */
    for(int i = 0; i < n - 1; i++){
        T menor = vet[i];
        int pos = i;
        for(int j = i+1; j < n; j++){
            if(vet[j] < menor){
                menor = vet[j];
                pos = j;
            }
        }
        std::swap(vet[i],vet[pos]);

    }
}

template <typename T>
void insertionsort(T vet[], int n){
    for(int i = 1; i < n; i++){
        T aux = vet[i];
        int j = i - 1;
        while(j>=0 && vet[j] > aux){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux;
    }
}