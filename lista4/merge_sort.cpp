#include <bits/stdc++.h>

/*Programa C ++ para Merge Sort
Criado em 1945 pelo matemático americano John Von Neumann o Mergesort é um exemplo de algoritmo de ordenação
que faz uso da estratégia “dividir para conquistar” para resolver problemas. 
É um método estável e possui complexidade C(n) = O(n log n) para todos os casos
Normalmente usa poucos recursos de mémoria, é um algoritmo eficiente. 
Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. 
Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.
T(n) = 2T(n/2) + complexidade_merge
 */

void snapshot(std::vector<char> &elementos);
// Mescla dois subvetor de vetor [].
// O primeiro subvetor é vetor [e..m]
// O segundo subvetor é vetor [m + 1..d]
void merge(std::vector<char> &elementos, int e, int m, int d) // n O(n)
{
    int n1 = m - e + 1;
    int n2 = d - m;

    // Criar matrizes temporárias
    std::vector<int> Esquerdo(n1, 0), Direito(n2, 0);

    // Copiar dados para matrizes temporárias Esquerdo [] e Direito []
    for (int i = 0; i < n1; i++)
        Esquerdo[i] = elementos[e + i];
    for (int j = 0; j < n2; j++)
        Direito[j] = elementos[m + 1 + j];
    
    // Mesclar as matrizes temporárias de volta em vetor [e..d]

    // Índice inicial do primeiro subvetor
    int i = 0;

    // Índice inicial do segundo subvetor
    int j = 0;

    // Índice inicial do subvetor mesclado
    int k = e;

    while (i < n1 && j < n2)
    {
        if (Esquerdo[i] <= Direito[j])
        {
            elementos[k] = Esquerdo[i];
            i++;
        }
        else
        {
            elementos[k] = Direito[j];
            j++;
        }
        k++;
    }
    // Copie os elementos restantes da
    // Esquerdo [], se houver algum
    while (i < n1)
    {
        elementos[k] = Esquerdo[i];
        i++;
        k++;
    }

    // Copie os elementos restantes da
    // Direito [], se houver algum
    while (j < n2)
    {
        elementos[k] = Direito[j];
        j++;
        k++;
    }
}
// e é para o índice esquerdo e d é
// índice direito da submatriz
// de chegada a ser classificado * /
void mergeSort(std::vector<char> &elementos, int e, int d) //T(n) = 2T(n/2) + n complexidade_merge
{

    snapshot(elementos);

    if (e >= d) // condição de parada
    {
        return; // retorna recursivamente
    }
    int m = e + (d - e) / 2;
    mergeSort(elementos, e, m);
    mergeSort(elementos, m + 1, d);
    merge(elementos, e, m, d);
}

/*   Método utilizado para debugging. Imprime na tela uma 'foto' do vetor */

void snapshot(std::vector<char> &elementos)
{
    std::cout << "[";
    for (auto i = 0; i < elementos.size() - 1; i++)
    {
        std::cout << elementos[i] << " ";
    }
    std::cout << elementos.back() << "]\n";// back é constante e referência o último elemento do vetor
}

// Teste
int main()
{
    std::vector<char> elementos = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};

    std::cout << "Dados de entrada do vetor:\n";
    snapshot(elementos);
    std::cout << "\n";

    std::cout << "Etapas do processo:\n";

    mergeSort(elementos, 0, elementos.size() - 1);

    std::cout << "\nMerge Sort - Vetor ordenado:\n";
    snapshot(elementos);

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