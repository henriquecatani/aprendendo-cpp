#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ofstream pag;
    pag.open("tabela.html");// arquivo de saida
    pag << "<!DOCTYPE html>\n";
    pag << "<html>\n";
    pag << "<head>\n <title>Est dados</title> </head>\n";
    pag << "<body>\n";
    pag << "<h1> Dec para Hex </h1>\n";
    pag << "<table border=\"1\">\n";

    for(int i=0;i<100;i++){
        // tab << i << endl; // cout << i << endl;
        pag << "<tr>"
            << "<td>" << dec << i << "</td>\n"
            << "<td>" << hex << uppercase << i << "</td>"
            << "</tr>";

    }
    pag << "</table> </body>\n </html>";

    pag.close();

    return 0;
}