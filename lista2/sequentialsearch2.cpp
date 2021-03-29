#include <iostream>
using namespace std;
//Algoritmo Sequential Search - O(n) 
int BuscaSequencial(int matriz[], int valorpesquisado, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        if (valorpesquisado == matriz[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    int elemento[7] = {89, 45, 68, 90, 29, 34, 17};

    int valordigitado;

    cout << "\nDigite um numero inteiro:" << endl;
    cin >> valordigitado;

    int resutado = BuscaSequencial(elemento, 7, valordigitado);

    if (resutado >= 0)
    {
        cout << "\nO numero: " << elemento[resutado] << " foi encontrado no"
                                                        "\nelemento com indice: "
             << resutado << endl;
    }
    else
    {
        cout << "\nO numero: " << valordigitado << " nao foi encontrado. " << endl;
    }
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