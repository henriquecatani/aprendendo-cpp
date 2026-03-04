#include <iostream> 
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){ 
    string arquivo;
    cin >> arquivo;
    ifstream arq(arquivo); 
    if(!arq){ 
        cout << "arquivo não existe\n"; 
        return 1; 
    } 
 
    int cont[256] = {};
    char ch; 
    while(arq.get(ch)){ 
        cont[int(ch)]++;
    } 
 
    ofstream tab;
    tab.open("contagem_caracteres.csv");

    for (int i = 0; i < 256; i++){
        if (cont[i]>0){
            tab << char(i) << ";" << cont[i] << endl;
        }
    }
    tab.close();
    arq.close(); 
    return 0; 
} 
