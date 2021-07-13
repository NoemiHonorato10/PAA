/* Algoritmo Ciclo Hamiltoniano em C++
Problema de ciclo usando backtracking */
#include <bits/stdc++.h>

void printSol(std::vector<int> &sol, int n)
{
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << sol[i] << " ";
    }
    std::cout << std::endl;
}
//As Restrições
bool caminhoSeguro(std::vector<std::vector<int>> &grafo, std::vector<int> &sol, int v, int pos)
{
    // Verifique se este vértice é adjacente
    if (grafo[sol[pos - 1]][v] == 0)
    {
        return false;
    } // Verifique se o vértice já foi incluído.   Esta etapa pode ser otimizada criando
    for (int i = 0; i < pos; i++)
    {
        if (sol[i] == v)
            return false;
    }
    return true;
}
// Faz a verificação
void backtracking(std::vector<std::vector<int>> &grafo, int n, std::vector<int> &solucao, int posicao)
{
    if (n == posicao) // Se posição final for igual ao tamanho da solução imprime a solução
    {
        printSol(solucao, n);
        return;
    }

    for (int i = 1; i < n; i++) //Começa verificar pelo vertice 1
    {
        // Se retornar verdadeira adc i na solução e na posição atual
        if (caminhoSeguro(grafo, solucao, i, posicao))
        {
            solucao[posicao] = i;
            backtracking(grafo, n, solucao, posicao + 1); // Chama a função na próxima posição
            solucao[posicao] = -1;
        }
    }
}

int main()
{
    // Vamos criar o seguinte gráfico
    std::vector<std::vector<int>> grafo{{0, 1, 0, 1, 0},
                                        {1, 0, 1, 1, 1},
                                        {0, 1, 0, 0, 1},
                                        {1, 1, 0, 0, 1},
                                        {0, 1, 1, 1, 0}};
    std::vector<int> solucao{0, -1, -1, -1, -1};
    int n = 4;
    int posicao_inicial = 1;
    backtracking(grafo, n, solucao, posicao_inicial);
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
[5]Função de biblioteca qsort ().Consulte: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
