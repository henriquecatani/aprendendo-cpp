#include <iostream> 
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){ 
    ifstream arq("gpl3"); 
    if(!arq){ 
        cout << "arquivo não existe\n"; 
        return 1; 
    } 
 
    char ch; 
    int nletras = 0, ndig = 0, nspace = 0, noutros = 0;   
    while(arq.get(ch)){ 
        if (isalpha(ch)) nletras++; //é letra? 
        else if(isdigit(ch)) ndig++; // é digito? 
        else if(isspace(ch)) nspace++; // é espaço? 
        else noutros++;                 //é outro caracter 
         
    } 
    int totalch = nletras + nspace + ndig + noutros; 
 
    cout << totalch << "Total de chars, destes temos: "  
        << fixed << setprecision(2) 
        << nletras << "letras(" << nletras * 100.0/totalch << "%\n" 
        << ndig << "digitos(" << ndig * 100.0/totalch << "%\n" 
        << nspace << "espaços(" << nspace * 100.0/totalch << "%\n" 
        << noutros << "outros(" << noutros * 100.0/totalch << "%\n"; 
 
    arq.close(); 
    return 0; 
} 
