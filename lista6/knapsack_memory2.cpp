// Algoritmo da Mochila - memory function | Complexidade de tempo: O (N * capacidade).
#include <bits/stdc++.h>

// Retorna o valor máximo suportado
int Knapsack(std::vector<int> &peso, std::vector<int> &valor, int posicao, int capacidade)
{

    int tabela[posicao][capacidade]; // Tabela com a capacidade e a posição do vetor

    // loop para inicialmente

    for (int i = 0; i <= posicao; i++) //critério de deparada
    {
        for (int j = 0; j <= capacidade; j++) // n*m Linear O(n)
        {

            if (i == 0 || j == 0) // caso base , ou
            {
                tabela[i][j] = 0;
            }
            else if (peso[i - 1] <= j) //caso base
            {
                // Armazena o valor máximo em uma tabela antes de retornar
                tabela[i][j] = std::max(valor[i - 1] + tabela[i - 1][j - peso[i - 1]], tabela[i - 1][j]);
            }
            else
            {
                tabela[i][j] = tabela[i - 1][j];
            }
        }
    }

    return tabela[posicao][capacidade];
}
int main()
{
    std::vector<int> peso = {4, 7, 6, 1, 5, 16};
    std::vector<int> valor = {14, 35, 10, 25, 22, 30};
    int mochilaItens = 7;
    std::cout << Knapsack(peso, valor, 5, mochilaItens);

    return 0;
}
/*Referências: 
[1]Introduction to the design & analysis of algorithms / Anany Levitin. — 3rd ed.
Tenenbaum, Aaron M.
[2]Estruturas de dados usando C / Aaron M. Tenenbaum,Yedidyah Langsam, Moshe J. Augenstein ; tradução
Teresa Cristina Félix de Souza ; revisão técnica e adaptação dos programas Roberto Carlos Mayer. —
São Paulo : MAchaveRON Boochaves, 1995.
[3]Introdução à Programação Curso em C++ Dr. Alan R. R. de Freitas,ALANDEFREITAS.COM
Edição: 19 de Março de 2015.
[4]Algoritmos / Thomas H. Cormen... [et al.] ; [tradução Arlete Simille Marques]. - 
Rio de Janeiro : Elsevier, 2012. il| página 32.
Tradução de: Introduction to algorithms, 3rd ed.
1. Programação (Computadores). 2. Algoritmos de computador. 3. 
Estruturas de dados (Computadores). I. Cormen, Thomas H.
[5]https://programmersought.com/article/8173587742/
*/