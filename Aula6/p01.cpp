#include <iostream>
#include <algorithm>
using namespace std;

bool ordena(double a, double b){
    return a > b;
}

int main(){
    const int N = 5;
    double v[N] = {9.5, 5.8, 4.6, 5.5, 1.3};
    sort(v,v+N); // ordenar
    for (int i=0; i<N; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}