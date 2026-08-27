#include <iostream>

using namespace std;

int main ( )
{
    int N, M; cin >> N >> M;

    int turmas[M];    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int G; cin >> G;
            if (turmas[j] < G)
                turmas[j] = G;
        }
    }

    int sum = 0;
    for (auto &&t : turmas)
    {
        sum += t;   
    }
    
    cout << sum << "\n";
}