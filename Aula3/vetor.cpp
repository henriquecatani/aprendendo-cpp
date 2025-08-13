#include<iostream>
using namespace std;
int main(){
    int vet[6];
    cout << "digite 6 valores\n";
    for(int i=0; i<6; i++){
	cin >> vet[i];
    }
	
    cout << "valores:\n";    
    for(int i=0; i<6; i++){
	cout << vet[i] << endl;
    }

    return 0;
}

