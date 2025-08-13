#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int tempo, velm;
    float dist;
    cin >> tempo >> velm;
    dist = (tempo*velm);
    cout << fixed << setprecision(3) << dist/12 << endl;
}
