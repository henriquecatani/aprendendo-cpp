#include<iostream>
using namespace std;
#define TAMV 6
int main(){
    int tamanhoVetor;
    int vet[TAMV];
    cout << "digite" << TAMV << " valores\n";
    for(int i=0; i<TAMV; i++){
	cin >> vet[i];
    }
	
    cout << "valores:\n";    
    for(int i=0; i<TAMV; i++){
	cout << vet[i] << endl;
    }

    return 0;
}

