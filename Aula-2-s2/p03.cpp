#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

int main(){
    ifstream arq("pastas");
    if(!arq){
        cout << "nao existe\n";
        return 1;
    }
    int cont[256] ={};
    char ch;
    while(arq.get(ch)){
        cont[int(ch)]++;
        cout << ch << " - " << int(ch) << endl;
    }


    return 0;
}
