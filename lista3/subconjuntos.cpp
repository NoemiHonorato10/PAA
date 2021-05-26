/*
    Algoritmo de Subconjuntos
    Gerar todas as permutações possíveis do conjunto {1, 2, ..., 𝑁}
    As principais aplicações do backtracking são da criação de
    todos os subconjuntos de um conjunto S e na criação de 
    todas as suas permutações.
    Uma forma de visualizar o processo do backtracking é imaginar sua
    árvore enraizada de recursão, onde a raiz representa uma permutação 
    parcial vazia, os nós intermediários representam as permutações 
    parciais em construção e as folhas representam todas
    as possíveis 𝑁! permutações. Para solucionar o problema, assim que o backtracking estiver
    em uma folha que representa uma permutação 𝑝 = {𝑝1, 𝑝2, ..., 𝑝𝑛}, basta iterar por todas
    as 𝑁 − 1 posições de 1 a 𝑁 − 1 e somar os valores |𝑝𝑖+1 − 𝑝𝑖| e atualizar o melhor valor
    já encontrado até então caso o valor atual seja maior que o mesmo.
    Uma permutação completa do algoritmo tem complexidade assintótica
    𝑂(𝑁), o algoritmo final para solucionar o problema do maior coeficiente de diferença tem
    complexidade de tempo de execução 𝑂(𝑁 · 𝑁!) e, com uma implementação cuidadosa,
    𝑂(𝑁) de memória.

        verdadeiro ou falso |   imprime
               (V,V,V)          {1,2,3}
               (V,V,F)          {1,2}
               (V,F,V)          {1,3}
               (V,F,F)          {1}
               (F,V,V)          {2,3}
               (F,V,F)          {2}
               (F,F,V)          {3}
*/
#include <iostream>


void combinacoes(int elemento[], bool verifica[], int i, int tamanho)
{
    if (i == tamanho)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (verifica[j] == 1)
                std::cout << elemento[j] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        verifica[i] = true;
        combinacoes(elemento, verifica, i + 1, tamanho);
        verifica[i] = false;
        combinacoes(elemento, verifica, i + 1, tamanho);
    }
}

int main()
{
    int elemento[] = {1, 2, 3};
    int tamanho = sizeof(elemento) / sizeof(int);
    bool verifica[tamanho];

    for (int i = 0; i < tamanho; i++)
        verifica[i] = false;

    combinacoes(elemento, verifica, 0, tamanho);

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
[5]https://www.ic.unicamp.br/~cid/cursos/MC658/201901/handout-back.pdf
[6]http://arquivoescolar.org/bitstream/arquivo-e/103/1/algoritmos.pdf
[7]https://bdm.unb.br/bitstream/10483/21568/1/2018_LucasVasconcelosMattioli_tcc.pdf
*/