#include<iostream>
using namespace std;
// identificando o cha: beecrowd 2006

int main(){
    int T; // resposta correta
    cin >> T;
    int cnt = 0;
    for(int i = 0; i < 5; i++){
        int r = 0;
        cin >> r;
        if (r == T){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}