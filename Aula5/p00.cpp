#include<iostream>
using namespace std;

template <typename T> // qualquer tipo vai servir
void swapT(T &a, T &b){
    T aux = a;
    a = b;
    b = aux;

}

int main(void){
    string x = "Hellou", y = "Uorolde";
    cout << "x antes: " << x << " , y antes: " << y << endl;
    swapT(x,y);
    cout << "x depois: " << x << " , y depois: " << y << endl;
    
    int z = 20, v = 30;
    cout << "z antes: " << z << " , v antes: " << v << endl;
    swapT(z,v);
    cout << "z depois: " << z << " , v depois: " << v << endl;
    return 0;
}