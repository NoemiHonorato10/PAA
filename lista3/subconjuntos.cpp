/*
Algoritmo de subconjuntos
As principais aplicações do backtracking são da criação de
 todos os subconjuntos de um conjunto S e na criação de 
 todas as suas permutações.
 
n! ≈ √2πn (n/e)^n (1 + O(1/n))

        verdadeiro ou falso |   imprime
               (V,V,V)          {1,2,3,}
               (V,V,F)          {1,2}
               (V,F,V)          {1,3}
               (V,F,F)          {1}
               (F,V,V)          {2,3}
               (F,V,F)          {2}
               (F,F,V)          {3}
*/
#include <iostream>

using namespace std;

void combinacoes(int elemento[], bool verifica_e[], int i, int tamanho_e)
{
	if(i == tamanho_e
    )
	{
		for(int j = 0; j < tamanho_e
        ; j++)
		{
			if(verifica_e[j] == 1)
				cout << elemento[j] << " ";
		}
		cout << endl;
	}
	else
	{
		verifica_e[i] = true;
		combinacoes(elemento, verifica_e, i + 1, tamanho_e
        );
		verifica_e[i] = false;
		combinacoes(elemento, verifica_e, i + 1, tamanho_e
        );
	}
}

int main()
{
	int elemento[] = {1, 2, 3};
	int tamanho_e
     = sizeof(elemento) / sizeof(int);
	bool verifica_e[tamanho_e
    ];

	for(int i = 0; i < tamanho_e
    ; i++)
		verifica_e[i] = false;

	combinacoes(elemento, verifica_e, 0, tamanho_e
    );

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
*/