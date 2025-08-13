#include<iostream>
using namespace std;

int main(){
    int tamv;
    cout >> "digite o tamanho do vetor\n";
    cin >> tamv;
    int vet[tamv];
    cout << "digite" << tamv << " valores\n";
    for(int i=0; i<tamv; i++){
	cin >> vet[i];
    }
	
    cout << "valores:\n";    
    for(int i=0; i<tamv; i++){
	cout << vet[i] << endl;
    }

    return 0;
}

