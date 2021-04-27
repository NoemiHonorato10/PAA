// Programa C ++ para implementar pesquisa de interpolação
/*
            ***Interpolation Search***
    Dada uma matriz classificada de n valores uniformemente distribuídos vetor [], 
    escreva uma função para pesquisar um elemento x particular na matriz. 
    A pesquisa linear encontra o elemento no tempo O (n), 
    a pesquisa de salto leva o tempo O (√ n) e a pesquisa binária leva o tempo O (Log n). 
    A pesquisa de interpolação é uma melhoria em relação à pesquisa binária para instâncias,
    onde os valores em uma matriz classificada são uniformemente distribuídos. 
    A pesquisa binária sempre vai para o elemento do meio para verificar.
    Por outro lado, a pesquisa de interpolação pode ir para locais diferentes de
    acordo com o valor da chave que está sendo pesquisada. Por exemplo, 
    e o valor da chave estiver mais próximo do último elemento, 
    a pesquisa de interpolação provavelmente iniciará a pesquisa em direção ao lado final.
 */
#include<bits/stdc++.h>
#include<vector>
#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
//using namespace std;
 
// Se elemento está presente em vetor [0..n-1], então retorna
// índice dele, senão retorna -1.
int interpolationSearch(std::vector<int> &vetor, int n, int elemento)
{
    // Encontre índices de dois cantos
    int inicial = 0, final = (n - 1);
 
    // Uma vez que a matriz é classificada, um elemento presente
     // na matriz deve estar no intervalo definido pelo canto
     
    while (inicial <= final && elemento >= vetor[inicial] && elemento <= vetor[final])
    {
        if (inicial == final)
        {
            if (vetor[inicial] == elemento) return inicial;
            return -1;
        }
        // Sondando a posição mantendo
         // distribuição uniforme em mente.
        int posicao = inicial + (((double)(final - inicial) /
            (vetor[final] - vetor[inicial])) * (elemento - vetor[inicial]));
 
        // Condição do alvo encontrado
        if (vetor[posicao] == elemento)
            return posicao;
 
        // Se elemento for maior, elemento estará na parte superior
        if (vetor[posicao] < elemento)
            inicial = posicao + 1;
 
        // Se elemento é menor, elemento está na parte inferior
        else
            final = posicao - 1;
    }
    return -1;
}
 
int main()
{  
    std::cout<<"**Pesquisa de Interpolacao**\n";
   int numero;

    // Vetor de itens em que a pesquisa irá
    // ser conduzido.

	std::cout<<"Digite o numero:\n";
	std::cin>>numero; 

    std::vector<int>vetor = {10, 14, 20, 22, 25, 62};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    
     int elemento = numero;
    int indice = interpolationSearch(vetor, n, elemento);

	// Se o número for encontrado, imprima "ENCONTRADO"

	if(indice != -1 ) 
         std::cout<<"Elemento encontrado no indice:\n"<< indice;
	else 
        std::cout<<"Elemento nao encontrado.\n";

    return 0;
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