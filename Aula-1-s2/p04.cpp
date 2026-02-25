#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    //cout << "" ou cout << variavel

    ofstream tab;
    tab.open("tabela.txt");// arquivo de saida
    for(int i=0;i<100;i++){
        // tab << i << endl; // cout << i << endl;
        tab << dec << i << ";"
            << i * 10 << ";"
            << hex << uppercase << i << endl;

    }

    tab.close();

    return 0;
}