// Algoritmo para o problema do caixeiro viajente em C++
#include <vector>
#include <iostream>

using namespace std;

/**
    Dado um grafo completo, não direcionado e ponderado na forma de uma matriz de adjacência,
    retorna o menor passeio que visita todos os nós e começa e termina no mesmo
    nó. Esta solução de programação dinâmica é executada em O (n * 2 ^ n)., ou seja, se o valor de "n" for grande
    é um problema de otimização combinatória. Por enumeração completa serão (n-1)!/2 Rotas.
    cresce mais rápido do que exponencialmente.
    É um problema NP-Completo.
    visa saber o custo mínimo para completar o passeio.
*/
int minimo(const vector<vector<int>> &cidades, int posicao, int visitou, vector<vector<int>> &estado)
{
    if (visitou == ((1 << cidades.size()) - 1))
        return cidades[posicao][0]; // voltar para a cidade de partida

    if (estado[posicao][visitou] != INT_MAX)//constantes INT_MAX = Valor máximo para um objeto do tipo int, 32767( ) ou maior *2^15-1
        return estado[posicao][visitou];

    for (int i = 0; i < cidades.size(); ++i)
    {
        // não podemos nos visitar a menos que estejamos terminando e pule se já visitamos
        if (i == posicao || (visitou & (1 << i)))
            continue;

        int distancia = cidades[posicao][i] + minimo(cidades, i, visitou | (1 << i), estado);
        if (distancia < estado[posicao][visitou])
            estado[posicao][visitou] = distancia;
    }

    return estado[posicao][visitou];

}

int main()
{
    vector<vector<int>> cidades = {{0, 20, 42, 35},
                                  {20, 0, 30, 34},
                                  {42, 25, 0, 12},
                                  {35, 10, 12, 0}};

    vector<vector<int>> estado(cidades.size());
    for (auto &vizinhas : estado)
        vizinhas = vector<int>((1 << cidades.size()) - 1, INT_MAX); //constantes INT_MAX = Valor máximo para um objeto do tipo int
    std::cout << "Minino: " << minimo(cidades, 0, 1, estado) << std::endl;

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
