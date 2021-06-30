/*
    Algoritmo Insertion Sort em C++
    Para colocar N elementos em seus devidos lugares, precisamos de N-1 passes.
    Muitas trocas, e menos comparações;
    Melhor caso: O(n), quando a matriz está ordenado;
    Médio caso: O(n²/4), quando a matriz tem valores aleatórios sem ordem de classificação (crescente ou decrescente);
    Pior caso: O(n²), quando a matriz está em ordem inversa, daquela que deseja ordenar.
    Para calcular T(n), o tempo de execução de Insertion-Sort de uma entrada de n valores, somamos os
    produtos das colunas custo e vezes, obtendo: Tempo = n-1 | Função linear de n.

                Melhor|	Médio|	Pior
Insertion sort 	 O(n)	O(n²)	O(n²)
Funciona assim:
      Passar|	Lista não classificada|	comparação  |   Lista ordenada
        1	      {12,3,5,10,8,1}	   {12,3}	        {3,12,5,10,8,1}
        2	      {3,12,5,10,8,1}	   {3,12,5}	        {3,5,12,10,8,1}
        3	      {3,5,12,10,8,1}	   {3,5,12,10}	    {3,5,10,12,8,1}
        4	      {3,5,10,12,8,1}	   {3,5,10,12,8}    {3,5,8,10,12,1}
        5	      {3,5,8,10,12,1}	   {3,5,8,10,12,1}	{1,3,5,8,10,12}
        6	      {}	               {}	            {1,3,5,8,10,12}
*/ 
#include <algorithm>
#include <array>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

int main ()  
{    
    //std::vector<int> elemento = { 12,4,3,1,15,45,33,21,10,2};   
    std::vector<char> elemento = {'s', 'r', 'h', 'n', 'a', 'o', 'e','m','i', 'h'}; 
    std::cout<<"\nA lista de entrada: \n";
    for(int i=0;i<10;i++)  
    {  
       std::cout <<elemento[i]<<"\t";  
    } 
    // para cada posição a partir de chave = 1   
    for(int chave=1; chave<10; chave++)   
    {  
        int temp = elemento[chave];  
        int j= chave-1;  
        // enquanto há posições válidas e
        // elemento a colocar é menor que o corrente
        // O operador lógico && só vai retornar verdadeiro (true), se todas as condições forem verdadeiras.
        while(j>=0 && temp <= elemento[j])  
        {  
            // pega elemento guardado e coloca na posição dele
            elemento[j+1] = elemento[j];   
            j = j-1;  
        }  
        elemento[j+1] = temp;  
    }  
    std::cout<<"\nA lista ordenada: \n";
    for(int i=0;i<10;i++)  
    {  
        std::cout <<elemento[i]<<"\t";  
    }  
}
/*Referências: 
[1]Introduction to the design & analysis of algorithms / Anany Levitin. — 3rd ed.
Tenenbaum, Aaron M.
[2]Estruturas de dados usando C / Aaron M. Tenenbaum,Yedidyah Langsam, Moshe J. Augenstein ; tradução
Teresa Cristina Félix de Souza ; revisão técnica e adaptação dos programas Roberto Carlos Mayer. —
São Paulo : MAchaveRON Boochaves, 1995.
[3]Introdução à Programação Curso em C++ Dr. Alan R. R. de Freitas,ALANDEFREITAS.COM
Edição: 19 de Março de 2015.
[4]Algoritmos / Thomas H. Cormen... [et al.] ; [tradução Arlete Simille Marques]. - 
Rio de Janeiro : Elsevier, 2012. il| página 32.
Tradução de: Introduction to algorithms, 3rd ed.
1. Programação (Computadores). 2. Algoritmos de computador. 3. 
Estruturas de dados (Computadores). I. Cormen, Thomas H.
[5]https://commons.wichaveimedia.org/wichavei/File:Insertion-sort-example.gif
[6]https://www.softwaretestinghelp.com/insertion-sort/#C_Example
*/
