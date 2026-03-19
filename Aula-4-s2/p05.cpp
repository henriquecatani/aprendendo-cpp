#include <iostream>
#include <cstdlib> // para usar a funcao rand
#include <unordered_set>

using namespace std;

int main ()
{
    unordered_set<int> conjunto;
    conjunto.max_load_factor(0.75); // para forcar colisao
    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100;
        conjunto.insert(num);
        cout << i << endl;
        cout << num << endl;
        cout << "Size: " << conjunto.size() << endl;
        cout << "Bucket count: " << conjunto.bucket_count() << endl;
        cout << "Load factor: " << conjunto.load_factor() << endl;
        cout << "Max load factor: " << conjunto.max_load_factor() << endl;
    }
}