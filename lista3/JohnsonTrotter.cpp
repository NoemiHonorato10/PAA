/*  
    Algoritmo de Johnson e Trotter - Tem bom desempenho gera todas as permutações de troca mínima:
    – A partir de uma permutação, apenas dois elementos são
    trocados de lugar (i. e., transpostos) para gerar a próxima
    permutação.
    O algoritmo não requer armazenar todas as permutações
    de tamanho n-1 e não requer passar por todas as permutações mais curtas. 
    Em vez disso, ele acompanha a 
    direção de cada elemento da permutação.
    Logo, a complexidade média (de transposições) é O(n²).
*/
#include <bits/stdc++.h>//Este arquivo inclui todas as bibliotecas padrão
using namespace std;
  
bool esquerdadireita = true;
bool direitaesquerda = false;
  
// Funções utilitárias para encontrar a
// posição do maior número inteiro inverso em um array[].
int searchArr(int a[], int n, int inverso)
{
    for (int i = 0; i < n; i++)
        if (a[i] == inverso)
           return i + 1;
}
  
// Para realizar a etapa 1 do algoritmo, ou seja,
// para encontrar o maior número inteiro inverso.
int getinverso(int a[], bool dir[], int n)
{
    int inverso_prev = 0, inverso = 0;
    for (int i = 0; i < n; i++)
    {
        // direção 0 representa DIREITA PARA ESQUERDA.
        if (dir[a[i]-1] == direitaesquerda && i!=0)
        {
            if (a[i] > a[i-1] && a[i] > inverso_prev)
            {
                inverso = a[i];
                inverso_prev = inverso;
            }
        }

        // direção 1 representa ESQUERDA PARA A DIREITA.
        if (dir[a[i]-1] == esquerdadireita && i!=n-1)
        {
            if (a[i] > a[i+1] && a[i] > inverso_prev)
            {
                inverso = a[i];
                inverso_prev = inverso;
            }
        }
    }
  
    if (inverso == 0 && inverso_prev == 0)
        return 0;
    else
        return inverso;
}
  
// Imprime uma única permutação
int printOnePerm(int a[], bool dir[], int n)
{
    int inverso = getinverso(a, dir, n);
    int pos = searchArr(a, n, inverso);
  
    // trocando os elementos de acordo com o
    // direção, ou seja, dir [].
    if (dir[a[pos - 1] - 1] ==  direitaesquerda)
       swap(a[pos-1], a[pos-2]); //Linear em n : executa uma operação de troca por elemento.
  
    else if (dir[a[pos - 1] - 1] == esquerdadireita)
       swap(a[pos], a[pos-1]); //Linear em n : executa uma operação de troca por elemento.
  
    // alterando as direções dos elementos
    // maior que o maior número inteiro móvel.
    for (int i = 0; i < n; i++)
    {
        if (a[i] > inverso)
        {
            if (dir[a[i] - 1] == esquerdadireita)
                dir[a[i] - 1] = direitaesquerda;
            else if (dir[a[i] - 1] == direitaesquerda)
                dir[a[i] - 1] = esquerdadireita;
        }
    }
  
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << " ";
}
  
// Para finalizar o algoritmo de eficiência, ele termina
// no fatorial de n devido ao número de
// permutações possíveis são apenas n!.
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}
  
// Esta função chama principalmente printOnePerm ()
// um por um para imprimir todas as permutações.
void printPermutation(int n)
{
    // Para armazenar a permutação atual
    int a[n];
  
    // Para armazenar direções atuais
    bool dir[n];
  
    // armazenando os elementos de 1 a n e
    // imprimindo a primeira permutação.
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        cout << a[i];
    }
    cout << endl;
  
   // inicialmente todas as direções são definidas
   // da DIREITA PARA A ESQUERDA, ou seja, 0.
    for (int i = 0; i < n; i++)
        dir[i] =  direitaesquerda;
  
    // para gerar permutações no pedido.
    for (int i = 1; i < fact(n); i++)
        printOnePerm(a, dir, n);
}
  
int main()
{
    std::cout << "\nTodas as permutacaes de troca minima: " << std::endl;
    int n = 4;
    printPermutation(n);
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
http://www3.decom.ufop.br/toffolo/site_media/uploads/2011-1/bcc402/slides/07._recursao.pdf
https://docplayer.com.br/26796343-Algoritmos-e-complexidade-notas-de-aula.html
*/