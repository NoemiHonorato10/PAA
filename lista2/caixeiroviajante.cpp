// Algoritmo para o problema do caixeiro viajente em C++
#include <vector>
#include <iostream>

using namespace std;

/**
    \brief Dado um grafo completo, não direcionado e ponderado na forma de uma matriz de adjacência,
            retorna o menor passeio que visita todos os nós e começa e termina no mesmo
            nó. Esta solução de programação dinâmica é executada em O (n * 2 ^ n).
    \return o custo mínimo para completar o passeio 
*/
int tsp(const vector<vector<int>> &cidades, int pos, int visitou, vector<vector<int>> &estado)
{
    if (visitou == ((1 << cidades.size()) - 1))
        return cidades[pos][0]; // voltar para a cidade de partida

    if (estado[pos][visitou] != INT_MAX)
        return estado[pos][visitou];

    for (int i = 0; i < cidades.size(); ++i)
    {
        // não podemos nos visitar a menos que estejamos terminando e pule se já visitamos
        if (i == pos || (visitou & (1 << i)))
            continue;

        int distancia = cidades[pos][i] + tsp(cidades, i, visitou | (1 << i), estado);
        if (distancia < estado[pos][visitou])
            estado[pos][visitou] = distancia;
    }

    return estado[pos][visitou];

}

int main()
{
    vector<vector<int>> cidades = {{0, 20, 42, 35},
                                  {20, 0, 30, 34},
                                  {42, 30, 0, 12},
                                  {35, 34, 12, 0}};

    vector<vector<int>> estado(cidades.size());
    for (auto &vizinhas : estado)
        vizinhas = vector<int>((1 << cidades.size()) - 1, INT_MAX);

    std::cout << "Minino: " << tsp(cidades, 0, 1, estado) << std::endl;

    return 0;
}

/*Referências: 
[1]Introduction to the design & analysis of algorithms / Anany Levitin. — 3rd ed.
Tenenbaum, Aaron M.
[2]Estruturas de dados usando C / Aaron M. Tenenbaum,Yedidyah Langsam, Moshe J. Augenstein ; tradução
Teresa Cristina Félix de Souza ; revisão técnica e adaptação dos programas Roberto Carlos Mayer. —
São Paulo : MAKRON Books, 1995.
[3]Introdução à Programação Curso em C++ Dr. Alan R. R. de Freitas,ALANDEFREITAS.COM
Edição: 19 de Março de 2015.
[4]Algoritmos / Thomas H. Cormen... [et al.] ; [tradução Arlete Simille Marques]. - 
Rio de Janeiro : Elsevier, 2012. il.
Tradução de: Introduction to algorithms, 3rd ed.
1. Programação (Computadores). 2. Algoritmos de computador. 3. 
Estruturas de dados (Computadores). I. Cormen, Thomas H.
*/