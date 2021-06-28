#include <bits/stdc++.h>

// Função para imprimir o conjunto
void imprimirConjunto(std::vector<int> &elementos)
{

    // Imprime o conjunto
    std::cout << "Elementos: ";
    for (auto i : elementos)
        std::cout << i << " ";

    std::cout << std::endl;
}

// Função para encontrar o elemento máximo
int entradaMax(std::vector<int> &elementos) // n-1 -1 +1 => n-1 O(n)
{

    // Obtenha o elemento máximo
    int max_elemento = elementos.front();
    for (int i = 1; i < elementos.size(); i++)
    {
        if (elementos[i] > max_elemento)
        {
            max_elemento = elementos[i];
        }
    }
    // retorna o elemento máximo
    return max_elemento;
}

// Função para encontrar o elemento mínimo
int entradaMinima(std::vector<int> &elementos) // n-1 -1 +1 => n-1 O(n)
{
    // Obtenha o elemento mínimo
    int min_elemento = elementos.front();
    for (int i = 1; i < elementos.size(); i++)
    {
        if (elementos[i] < min_elemento)
        {
            min_elemento = elementos[i];
        }
    }

    // retorna o elemento mínimo
    return min_elemento;
}

int main()
{
    // Obtenha o conjunto

    // Adicione os elementos no conjunto
    std::vector<int> elementos = {91, 91, 91, 91, 29, 34, 21};

    // Imprime o conjunto {91, 45, 68, 90, 29, 34, 21};
    imprimirConjunto(elementos);

    // O elemento mínimo
    std::cout << "Elemento minimo: "
              << entradaMinima(elementos)
              << std::endl;

    //O elemento máximo
    std::cout << "Elemento maximo: "
              << entradaMax(elementos)
              << std::endl;
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