 /*
	Árvore de pesquisa e inserção binária - Implementação em C ++
	Programa simples para criar a melhor forma de inteiros e pesquisar um elemento nele.
	Definimos árvores binárias recursivamente. 
	Uma árvore binária T é uma estrutura definida para um conjunto finito
	de nós que não contém nenhum nó ou é composta por três conjuntos disjuntos de nós:
	um nó raiz, uma árvore binária denominada sua subárvore da
	esquerda e uma árvore binária denominada sua subárvore da direita.
	Assim, uma árvore binária completa tem 2^h – 1 nós internos
	Complexidade:
		Algoritimo| Caso Médio|	Pior Caso
		Espaço		 O(n)	      O(n)
		Busca		 O(log n)	  O(n)
		Inserção	 O(log n)	  O(n)
		Remoção	     O(log n)	  O(n)
*/
#include<iostream>
using namespace std;
// Definição de Nó para árvore de pesquisa binária
struct No {
	int dados; 
	No* esquedo;
	No* direito;
};

// Função para criar um novo Nó
No* GetnovoNo(int dados) {
	No* novoNo = new No();
	novoNo->dados = dados;
	novoNo->esquedo = novoNo->direito = NULL;
	return novoNo;
}
/* 
	Para inserir dados no No, retorna o endereço do nó raiz| 
	Complexidade de inserção no caso médio: O(log n)| Pior caso: O(n)
 */
No* Inserir(No* raiz,int dados) {
	if(raiz == NULL) { // árvore vazia
		raiz = GetnovoNo(dados);
	}
	// se os dados a serem inseridos forem menores, insira na subárvore esquerda.
	else if(dados <= raiz->dados) {
		raiz->esquedo = Inserir(raiz->esquedo,dados);
	}
	// senão, insira na subárvore direita. 
	else {
		raiz->direito = Inserir(raiz->direito,dados);
	}
	return raiz;
}
/*
	Para pesquisar um elemento no No, retorna verdadeiro se o elemento for encontrado
	Complexidade de Busca no caso médio: O(log n)| Pior caso: O(n)
*/
bool buscar(No* raiz,int dados) {
	if(raiz == NULL) {
		return false;
	}
	else if(raiz->dados == dados) {
		return true;
	}
	else if(dados <= raiz->dados) {
		return buscar(raiz->esquedo,dados);
	}
	else {
		return buscar(raiz->direito,dados);
	}
}
int main() {
	No* raiz = NULL;  // Criando uma árvore vazia
	raiz = Inserir(raiz,14); // Teste	
	raiz = Inserir(raiz,20);	
	raiz = Inserir(raiz,10);
	raiz = Inserir(raiz,13);
	raiz = Inserir(raiz,15);
	raiz = Inserir(raiz,17);
	 
	int numero;
	cout<<"Digite o numero a ser pesquisado:\n";
	cin>>numero;
	// Se o número for encontrado, imprima "ENCONTRADO"
	if(buscar(raiz,numero) == true) cout<<"Encontrado\n";
	else cout<<"Nao encontrado\n";
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
[5]https://pt.wikipedia.org/wiki/%C3%81rvore_bin%C3%A1ria_de_busca
[6]https://www.guj.com.br/t/estrutura-de-arvore-binaria-em-c/280737
[7]https://www.clubedohardware.com.br/topic/942951-arvore-binaria-inserir-busca-e-remover/
*/