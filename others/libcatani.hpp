/// Funções úteis escritas nos aprendizados de programação.
#pragma once

#include <vector>

#define db_out cout << "[DEBUG] "

namespace libctn {
    /// @brief Calcula a quantidade de notas de troco para o valor, de acordo com a lista de notas disponíveis.
    /// @param valor O valor a ser calculado o troco. 
    /// @param notas A lista de notas disponíveis.
    /// @return Um vetor de pairs (nota, qtd).
    std::vector<std::pair<double, int>> calc_troco(double valor, std::vector<double> notas);
}