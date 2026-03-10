/*
1069- Diamantes e Areia
João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.
Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.
Exemplo de Entrada 	

2

<..><.<..>>

<<<..<......<<<<....>
	
Exemplo de Saída
3

1
*/
#include <iostream>
#include <string>
using namespace std;

int main () {
    int i;
    cin >> i;
    while (i>0)
    {
        string inp;
        cin >> inp;
        int s = inp.size();
        int cnt = 0;
        for (int j=0; j < s; j++)
        {
            if (inp[j] == '<')
            {
                inp.erase(j, 1);
                s--;
                for (int k=j; k < s; k++)
                {
                    if (inp[k] == '>') {
                        cnt++;
                        inp.erase(k, 1);
                        s--;
                        break;
                    
                    }
                }
            }
        }
        cout << cnt << endl;
        i--;
    
    }
    return 0;
}
