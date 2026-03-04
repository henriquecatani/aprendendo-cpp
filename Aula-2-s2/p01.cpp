#include <iostream> 
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    ifstream arq("gpl3.txt"); //acesso direto ao arquivo, sem o uso do .open
    if(!arq){
        cout << "Erro ao abrir o arquivo. Verifique!\n";
        return 1;
    }


    char ch;
    int cont = 0;
    //while(arq >> ch) -- era o metodo palavra a palavra ate o eof ( end of fine)
    //while(getline(arq, linha) -- metodo linha a linha ate o eof)
    while(arq.get(ch)){
        cout << ch;
        cont++;
    }
    cout << "Quantidade de chars: " << cont << endl;


    arq.close();

    return 0;
}
