// recebe input nome do arquivo

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
    string inp;
    cin >> inp;
    ifstream arq(inp);
    string palavra;
    char ch;
    vector<Palavra> palavras;
    while (arq.get(ch)) 
    {
    if (isalpha(ch)) {
        palavra += tolower(ch);
    } else if (palavra.size() > 0) {
        bool achou = false;
        for (auto &p : palavras)
        {
            if (p.palavra == palavra)
            {
                p.cnt++;
                achou = true;
                palavra.clear();
                break;
            }
        }
        if (achou == false) 
        {
            palavras.push_back({palavra, 1});
            palavra.clear();
        }
    }
    }
    for (auto p : palavras) 
    {
        cout << p.palavra << ": " << p.cnt << endl;
    }
}
