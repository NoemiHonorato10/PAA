//Algoritmo Brute Force String Match O(n²) em C++
//Força Bruta de Fragmento Partida

#include <bits\stdc++.h>

// Implementa correspondência de string de força bruta

int n;       //n caracteres representando um texto
int m;       //m caracteres representando um padrão
char t[100]; // Input: Uma matriz T [0..n - 1] de n caracteres representando um texto e
char p[100]; // uma matriz P [0..m - 1] de m caracteres representando um padrão
int bruteforceStringMatch(char t[100], char p[100], int n, int m)

{
    int i;
    int j;
    for (i = 0; i <= n - m; i++) //comparações cada uma das n - m + 1 tentativas
    {
        j = 0;
        while (j < m && p[j] == t[i + j])
            j++;
        if (j == m)
        {
            std::cout << "O caracter esta na posicao :\n"
                      << i;
            return i; // Saída: o índice do primeiro caractere do texto que inicia um ->
        }
    }
    std::cout << "O caracter nao esta entre os digitados \n";
    return -1; // substring correspondente ou -1 se a pesquisa não for bem-sucedida
}
int main()
{
    int local;
    std::cout << "Digite os caracteres \n";
    std::cin >> t;

    std::cout << "Digite o caracter que deseja pesquisar\n";
    std::cin >> p;
    n = strlen(t); //Retorna o comprimento da string C str
    m = strlen(p); //Retorna o comprimento da string C str
    local = bruteforceStringMatch(t, p, n, m);
 
    return 0;
}

/*     tamanho_t strlen (const char * str);
    Obter comprimento da corda
    Retorna o comprimento da string C str .

    O comprimento de uma string C é determinado pelo caractere nulo de terminação:
    Uma string C é tão longa quanto o número de caracteres entre o início da string e 
    o caractere nulo de terminação (sem incluir o próprio caractere nulo de terminação).

    Isso não deve ser confundido com o tamanho do array que contém a string. 
    Por exemplo: define uma matriz de caracteres com um tamanho de 100 caracteres,
    mas a string C com a qual mystr foi inicializada tem um comprimento de apenas 11 caracteres.
    Portanto, enquanto sizeof (mystr) avalia para 100 , strlen (mystr) retorna 11

    char mystr[100]="test string";
    Em C ++, char_traits :: length implementa o mesmo comportamento.
    
    O algoritmo muda o padrão quase sempre após um único caractere
    comparação. O pior caso é muito pior: o algoritmo pode ter que fazer
    todas as comparações antes de mudar o padrão, e isso pode acontecer para cada uma das
    n - m + 1 tentativas. Assim, no pior caso, o algoritmo faz
    comparações de caracteres m (n - m + 1), o que o coloca na classe O (nm).
    Para um típico pesquisa de palavras em um texto de linguagem natural, 
    no entanto, devemos esperar que a maioria das mudanças
    aconteceria após muito poucas comparações (verifique o exemplo novamente). Portanto,
    a eficiência do caso médio deve ser consideravelmente melhor do que o do pior caso
    eficiência. Na verdade é: para pesquisar em textos aleatórios, tem se mostrado linear,
    ou seja, (n). Existem vários algoritmos mais sofisticados e mais eficientes para
    pesquisa de string.

Referências: 
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
[5]https://www.cplusplus.com/reference/cstring/strlen/
*/