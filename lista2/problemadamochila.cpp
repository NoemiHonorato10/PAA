// Algoritmo para o problema da mochila (knapsack) em C++
#include <iostream>

int mochila(int capacidade, int peso[], int valor[], int item)
{
    // tabela que será preenchida
    int tabela[item + 1][capacidade + 1];

    // inicializando a primeira linha e primeira coluna com 0
    for (int j = 0; j <= capacidade; j++)
        tabela[0][j] = 0;
    for (int i = 1; i <= item; i++)
        tabela[i][0] = 0;

    for (int i = 1; i <= item; i++)
    {
        for (int j = 1; j <= capacidade; j++)
        {
            // elemento pode fazer parte da solução
            if (peso[i - 1] <= j)
            {
                //máximo
                if ((valor[i - 1] + tabela[i - 1][j - peso[i - 1]]) > tabela[i - 1][j])
                    tabela[i][j] = valor[i - 1] + tabela[i - 1][j - peso[i - 1]];
                else
                    tabela[i][j] = tabela[i - 1][j];
            }
            else
                tabela[i][j] = tabela[i - 1][j]; // ji > j
        }
    }

    // retorna o valor máximo colocado na mochila
    return tabela[item][capacidade];
}

int main()
{
    // capacidade máxima da mochila
    int capacidade = 10;

    // número de elementos itens
    int item = 4;

    // vetor com os valores de cada elemento
    int valor[] = {3, 5, 8, 9};

    // vetor com os pesos de cada elemento
    int peso[] = {2, 4, 3, 1};

    // obtém o máximo valor que pode ser colocado na mochila
    int max_valor = mochila(capacidade, peso, valor, item);

    std::cout << "Valor maximo: " << max_valor << std::endl;

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