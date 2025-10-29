#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string> v;
    v.push_back("A");
    v.push_back("B");    
    v.push_back("C");
    v.push_back("D");
    v.push_back("E");
    v.push_back("F");
    v.push_back("G");

    cout << "\nOrdem normal com for loop\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    cout << "\nOrdem inversa com for loop\n";
    for(int i=v.size() - 1; i >= 0; i--){
        cout << v[i] << endl;
    }

    cout << "\nUtilizando range for\n";
    for(string n:v){
        cout << n << endl;
    }
    cout << "\nUtilizando range for com tipo AUTO\n";
    for(auto n:v){
        cout << n << endl;
    }

    cout << "\nUtilizando iterator (ponteiros)\n";
    for(auto it = v.begin(); it != v.end(); it++){
        // funcao begin retorna um ponteiro no inicio do vetor
        cout << *it << endl; 
        // pra exibir o valor do ponteiro, precisa de asterisco
    }
    cout << "\nUtilizando reverse iterator (ponteiros)\n";
    for(auto it = v.rbegin(); it != v.rend(); it++){
        // funcao rbegin - begin de tras pra frente, rend - fim de tras pra frente
        cout << *it << endl; 
    }


    return 0;
}