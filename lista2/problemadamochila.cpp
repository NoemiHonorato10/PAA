// Algoritmo para o problema da mochila em C++
#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int b[], int n)
{
    // tabela que será preenchida
    int V[n + 1][W + 1];

    // inicializando a primeira linha e primeira coluna com 0
    for (int w = 0; w <= W; w++)
        V[0][w] = 0;
    for (int i = 1; i <= n; i++)
        V[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            // elemento pode fazer parte da solução
            if (wt[i - 1] <= w)
            {
                // max...
                if ((b[i - 1] + V[i - 1][w - wt[i - 1]]) > V[i - 1][w])
                    V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
                else
                    V[i][w] = V[i - 1][w];
            }
            else
                V[i][w] = V[i - 1][w]; // wi > w
        }
    }

    // retorna o valor máximo colocado na mochila
    return V[n][W];
}

int main(int argc, char *argv[])
{
    // capacidade máxima da mochila: W
    int W = 20;

    // número de elementos
    int n = 5;

    // vetor com os valores (benefício) de cada elemento
    int b[] = {3, 5, 8, 4, 10};

    // vetor com os pesos de cada elemento
    int wt[] = {2, 4, 5, 3, 9};

    // obtém o máximo valor que pode ser colocado na mochila
    int max_valor = knapsack(W, wt, b, n);

    cout << "Valor maximo: " << max_valor << endl;

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