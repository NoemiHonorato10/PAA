#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/* 
Análise geral
O quicksort um método muito eficiente para ordenar dados. Devido à pilha de funções
precisa de apenas um espaço extra muito pequeno, que é O(logn). Em termos práticos, este
custo de memória é usualmente considerado muito próximo de O(1).
O algoritmo requer apenas O(nlogn) comparações em seu caso médio. Apesar da mesma
ordem de complexidade média, é usualmente mais rápido que o Merge sort no caso médio.
O quicksort tem um pior caso O(n²) quando o pior pivô possível é sempre selecionado. A
probabilidade de ocorrência deste pior caso é extremamente baixa e não chega a alterar o caso
médio. Contudo, considerar este pior caso pode ser um fator importante em aplicações críticas,
mesmo que com uma baixa probabilidade.
O quicksort também não é um algoritmo estável pois as trocas na fase de partição não
consideram a ordem relativa dos elementos.
Na Tabela 16.4 temos um resumo do custo do quicksort em seus principais casos. Apesar de
ter um pior caso O(nlogn), o algoritmo tem custo O(nlogn) no caso médio e no melhor caso.

Tabela: Custo do algoritmo quicksort em suas situações mais comuns

	Caso	|		Descrição						|		Custo
Pior caso 	|	pivô sempre maior ou menor elemento |		O(n²)
Caso médio 	|	pivô aleatório 						|		O(nlogn)
Melhor caso |	pivô sempre elemento mediano 		|		O(nlogn)
*/

//using namespace std;

int main(){

int tamanho, i = 0, j = 0, moda;
float media = 0, mediana = 0, soma = 0, aux = 0, conta = 0;

//Pega o valor digitado

std::cout<<"Qual o total de numeros? ";
std::cin>>tamanho;

int cont[tamanho], v[tamanho];
if(tamanho>0){

	for(i=0;i<tamanho;i++){

	std::cout<<"Digite o valor? ";
	std::cin>>v[i];

	soma+=v[i];
	}
}

//Média

media=soma/tamanho;
std::cout<<"\nMedia: \n";
std::cout<<media<<std::endl;


//Mediana
 for(i=0;i<tamanho-1;i++){
        for(j=i+1;j<tamanho;j++){
        	
            if(v[i] > v[j]){
            	
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    if(tamanho%2){
         mediana = v[tamanho/2];
    } else {
         mediana = (v[tamanho/2-1]+v[tamanho/2])/2;
    }
	
std::cout<<"Mediana: \n";
std::cout << mediana<< std::endl;

return 0;

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
*/