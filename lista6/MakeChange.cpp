#include <iostream>
#include <vector>

// Aplica programação dinâmica para encontrar o número mínimo de moedas
// de denominações d1 < d2 <... < dm onde d1 = 1 que somam um
// dado montante n
// Entrada: Número inteiro positivo ne array D [1..m] de positivo crescente
// inteiros indicando as denominações das moedas onde D [1] = 1
// Saída: O número mínimo de moedas que somam n

int makeChange(std::vector<int> listaValorMoedas, int mudanca, std::vector<int> minMoedas)
{
    // loop encontra solução para todos os conjuntos de mudança de 0 a mudança interna.
    for (int centavos = 0; centavos < mudanca + 1; centavos++)
    {
        int contagemMoedas = centavos;
        for (int j : listaValorMoedas)
        {
            if (j <= centavos)
            {
                if (minMoedas[centavos - j] + 1 < contagemMoedas)
                {
                    // atribui o número de moedas que é usado para fazer a mudança.
                    contagemMoedas = minMoedas[centavos - j] + 1;
                }
            }
        }
        minMoedas[centavos] = contagemMoedas;
    }
    return minMoedas[mudanca];
}

int main()
{
    std::vector<int> listaValorMoedas = {3, 7, 10, 14, 54};
    int mudanca = 57;
    std::vector<int> minMoedas(58, 0);
    std::cout << makeChange(listaValorMoedas, mudanca, minMoedas) << std::endl;
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

