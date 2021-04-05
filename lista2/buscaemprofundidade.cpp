// Algoritmo para Grafos - DFS (busca em profundidade) em C++ 
#include <iostream>
#include <list>
#include <algorithm> // função find
#include <stack> // pilha para usar na DFS
 
using namespace std;
 
class Grafo
{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências
 
public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
 
	// faz uma DFS a partir de um vértice
	void dfs(int v);
};
 
Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}
 
void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}
 
void Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[V]; // vetor de visitados
 
	// marca todos como não visitados
	for(int i = 0; i < V; i++)
		visitados[i] = false;
 
	while(true)
	{
		if(!visitados[v])
		{
			cout << "Visitando vertice " << v << " ...\n";
			visitados[v] = true; // marca como visitado
			pilha.push(v); // insere "v" na pilha
		}
 
		bool achou = false;
		list<int>::iterator it;
 
		// busca por um vizinho não visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				achou = true;
				break;
			}
		}
 
		if(achou)
			v = *it; // atualiza o "v"
		else
		{
			// se todos os vizinhos estão visitados ou não existem vizinhos
			// remove da pilha
			pilha.pop();
			// se a pilha ficar vazia, então terminou a busca
			if(pilha.empty())
				break;
			// se chegou aqui, é porque pode pegar elemento do topo
			v = pilha.top();
		}
	}
}
 
int main()
{
	int V = 8;
 
	Grafo grafo(V);
 
	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);
	
	grafo.dfs(0);
 
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