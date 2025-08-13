#include<iostream>
using namespace std;
int main(){

int n, x, y, aux, soma;

cin >> n;

while(n>0){
    cin >> x >> y;

    // se o x for maior que o y, inverte os valores
    if(x>y){
    	aux = x;
	x = y;
	y = aux;
	
    }
    // soma os impares
    soma = 0;
    for(int i = x+1; i < y; i++){
	if(i%2 !=0) {
		soma += i;
	}
    }
	cout << soma << endl;
	n--;
}

return 0;
}
