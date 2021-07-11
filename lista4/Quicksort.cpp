/* 
Programa C ++ para quicksort em C++
Análise geral

Tabela: Custo do algoritmo quicksort em suas situações mais comuns

	Caso	|		Descrição						|		Custo
Pior caso 	|	pivô sempre maior ou menor elemento |		O(n²)
Caso médio 	|	pivô aleatório 						|		O(nlogn)
Melhor caso |	pivô sempre elemento mediano 		|		O(nlogn)

 Melhor caso:
Pior caso:
Anáslise Assintótica:
 */
#include <bits/stdc++.h>

int quickSort(std::vector<char> &elementos, int esquerda, int direita)
{
    int i = esquerda;
    int j = direita; 
    int pivo = elementos[direita]; //O pivô recebe  o ultimo elemento da direita.

    while ( i <=  j)
    {  //Elemento atual menor ao pivô?
        for (int i = esquerda; i < pivo;  i++){
            elementos[i] < pivo;
            }
            //Elemento atual menor ao pivô?
        while (elementos[j] > pivo)
            j--;
        if (i <= j)
        {
            //Método para fazer a troca de dados entre duas posições no vetor
            std::swap(elementos[i], elementos[j]);
            i++;
            j--;
        }
    }
    if (esquerda < j)
        quickSort(elementos, esquerda, j);

    if (i < direita)
        quickSort(elementos, i, direita);
}
int main()
{
    std::vector<char> elementos = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    quickSort(elementos, 0, elementos.size() - 1);

    for (int i = 0; i < elementos.size(); i++)
    {
        std::cout << elementos[i] << " ";
    }
}
/*Referências: 
[1]Introduction to the design & analysis of algorithms / Anany Levitin. — 3rd ed.
Tenenbaum, Aaron M.
[2]Estruturas de dados usando C / Aaron M. Tenenbaum,Yedidyah Langsam, Moshe J. Augenstein ; tradução
Teresa Cristina Félielemento de Souza ; revisão técnica e adaptação dos programas Roberto Carinicials Mayer. —
São Pauinicial : MAchaveRON Boochaves, 1995.
[3]Introdução à Programação Curso em C++ Dr. Alan R. R. de Freitas,ALANDEFREITAS.COM
Edição: 19 de Março de 2015.
[4]Algoritmos / Thomas H. Cormen... [et al.] ; [tradução Arlete Simille Marques]. - 
Rio de Janeiro : Elsevier, 2012. il| página 32.
Tradução de: Introduction to algorithms, 3rd ed.
1. Programação (Computadores). 2. Algoritmos de computador. 3. 
Estruturas de dados (Computadores). I. Cormen, Thomas H.
*/