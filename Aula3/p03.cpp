#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float vet[] {9.6, 3.5, 6.54};
    float soma = 0;
    for (int i = 0; i < 3; i++){
	soma += vet[i];
    }
    cout << "Soma: " << fixed << setprecision(2) << soma << endl;
    return 0;
}

