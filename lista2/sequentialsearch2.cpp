// Algoritmo sequential search2 em C++ | O(n)

#include <bits/stdc++.h>

int BuscaSequencial(std::vector<int> vetor, int item)
{
    for (int i = 0; i < vetor.size(); i++)// Repete n vezes
    {

        if (vetor[i] == item)
        {
            return i;
        }
    }

    return -1; // Se o valor não for encontrado retorna -1
}

int main()
{

    int numero;
    std::cout << "Digite o numero a ser pesquisado:\n";
    std::cin >> numero;

    std::vector<int> vetor = {1, 5, 8, 19, 25, 43, 99};

    if (BuscaSequencial(vetor, numero) >= 0)
    {

        std::cout << "Encontrado" << std::endl;
    }
    else
    {
        std::cout << "Nao encontrado" << std::endl;
    }

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