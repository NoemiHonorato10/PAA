//Algoritmo Busca Binária em C++
//BINARY-SEARCH é um procedimento serial.
//Implementação Iterativa: repete uma tarefa até que ela seja completa.
/*
classe:	Algoritmo de busca
estrutura de dados:	Array (no caso vector)
complexidade caso médio: O(log n)
complexidade melhor caso:	O(1)
complexidade de espaços pior caso:	O(log n)
otimo:	Sim
espaço: O(1)
 */
#include <iostream>
#include <cstdlib>
#include <vector>
//using namespace std;

  int PesquisaBinaria(const std::vector<int> &v, const int chave);
 // std::vector<char> chave = {'s', 'r', 'h', 'n', 'a', 'o', 'e','m','i', 'h'}; 
   

  int PesquisaBinaria(const std::vector<int> &v, const int chave){
// limite inferior da esquerda (o primeiro índice de chave é zero)
    int esquerda = 0; 
// limite superior da direita (termina em um número a menos. 0 a 9 são 10 números)
    int direita = v.size() - 1;
    int i; //i recebe o índice do meio entre início e fim
    do { //Faça enquando a condição for verdadeira
        i = (esquerda + direita) / 2;
        if (v[i] < chave) {
            esquerda = i + 1;
        } else {
            direita = i - 1;
        }
// O operador lógico && só vai retornar verdadeiro (true), se todas as condições forem verdadeiras.
// ou seja, v na possição [i] é diferente da chave && (true)...
    } while (v[i] != chave && esquerda <= direita);
    if (v[i] == chave) { //devolva o índice i | elemento chave encontrado
        return i;
    } else {
        return -1; //  não encontrou o elemento procurado
    }  
}

int main()
{
    std::cout << "\nBusca Binaria " << std::endl;
  
    int numero;
	std::cout<<"Digite o numero a ser pesquisado na segunda posicao:\n";
	std::cin>>numero;
    std::vector<int> i = {2, 7};
	// Se o número for encontrado, imprima "ENCONTRADO"
	if(PesquisaBinaria(i,numero) == true) std::cout<<"Encontrado\n";
	else std::cout<<"Nao encontrado\n";
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