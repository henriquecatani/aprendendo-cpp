#include<iostream>
using namespace std;
int main(){
	int cod, quant;
	float valor;
	cin >> cod >> quant;
	switch(cod){
		case 1:
			// cachorro
			valor = 10 * quant;
		case 2:
			// xsalada
			valor = 10 * quant;

		case 3:
			//xbacon
			valor = 10 * quant;

		case 4:
			//torrada
			valor = 10 * quant;

		case 5:
			//refri
			valor = 10 * quant;
		}
	
	cout << valor;
	return 0;
}
