#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a,b,c,d;
    int diferenca;
    cin >> a >> b >> c >> d;
    diferenca = (a*b - c*d);
    cout << fixed << setprecision(1) << "DIFERENCA = " << diferenca << endl;
}
