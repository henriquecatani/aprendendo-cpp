#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct Palavra 
{
    string palavra;
    int cnt;
};
int main () 
{
    ifstream arq("clarissacopy.txt");
    string palavra;

    vector<Palavra> palavras;
    while (arq >> palavra) 
    {
        bool achou = false;
        for (auto &p : palavras)
        {
            if (p.palavra == palavra)
            {
                p.cnt++;
                achou = true;
                cout << "achou!\n";
                break;
            }
        }
        if (achou == false) 
        {
            palavras.push_back({palavra, 1});
            cout << "N achou \n";
        }
    }
    for (auto p : palavras) 
    {
        cout << p.palavra << ": " << p.cnt << endl;
    }
}
