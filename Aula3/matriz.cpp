#include<iostream>
using namespace std;

int main(){
	const int L = 3;
	const int C = 3;
	float m[L][C]{
		{1.5,0.4,9.1},
		{0.6,6.4,10.2},
		{8.7,1.7,15.3}
	};
	for(int i=0; i< L; i++){
	       for(int j = 0; j< C; j++){
			cout << m[i][j] << "\t";
	       }
	       cout << endl;
	}	     
      	cout << "multiplicado por 2:\n ";
	
	for(int i=0; i< L; i++){ 
		for(int j = 0; j< C; j++){
		       	m[i][j] = m[i][j] * 2;
			cout << m[i][j] << "\t";
	       }
	       cout << endl;
	}	 
	return 0;
}

