// Algoritmo de Busca em Profundidade em C++ 
//Complexidade:  O(n + m)
#include <iostream>
#include <list>
#include <memory>
   
class Graph
{
private:
    int _V;    // número de vértices
    bool _direcionado;
    // ponteiro para um array contendo as listas de adjacências
    std::unique_ptr< std::list<int> > adj;  
    void BuscaUtil(int v, bool visitado[]);
      
public:
    Graph(int V, bool direcionado);// construtor
    void AddAresta(int v, int w); // adiciona uma aresta no grafo
    void BuscaEmProfundidade(int s); //faz uma busca em profundidade a partir de um vértice
};
   
Graph::Graph(int V, bool direcionado) : adj(new std::list<int>[V]) // cria as listas
{
    _V = V;// atribui o número de vértices
    _direcionado = direcionado;       
}   
   
void Graph::AddAresta(int v, int w)
{
    std::list<int>* adjacente = adj.get();
    // adiciona vértice v à lista de vértices adjacentes de w
    adjacente[v].push_back(w);
   
    if (!_direcionado)
    {
        // insere "v" na lista Adiciona um novo elemento no final do vetor
        adjacente[w].push_back(v);
    }
}
  
void Graph::BuscaUtil(int v, bool visitado[])
{
    //Marque o nó atual como visitado e imprima-o
    visitado[v] = true; // marca como visitado
    std::cout << v << " ";
  
    // Percorre para todos os vértices adjacentes a este vértice
    std::list<int>::iterator i;
    for (i = (adj.get())[v].begin(); i != (adj.get())[v].end(); ++i)
        if (!visitado[*i])
            BuscaUtil(*i, visitado);
}
  
// Transversal da busca em profundidade dos vértices alcançáveis de v. 
//Ele usa BuscaUtil() recursivo
void Graph::BuscaEmProfundidade(int v)
{
    // Marque todos os vértices como não visitados
    std::unique_ptr<bool[]> visitado(new bool[_V]);
     
    for (int i = 0; i < _V; i++)
        visitado[i] = false;
  
    // Chame a função auxiliar recursiva 
    //para imprimir o percurso da busca em proundidade
    BuscaUtil(v, visitado.get());
}
  
int main()
{
    // Crie um graph fornecido no diagrama acima
    Graph g(7, true);
    g.AddAresta(0, 1);
    g.AddAresta(0, 2);
    g.AddAresta(0, 3);
    g.AddAresta(1, 0);
    g.AddAresta(1, 5);
    g.AddAresta(2, 5);
    g.AddAresta(3, 0);
    g.AddAresta(3, 4);
    g.AddAresta(4, 6);
    g.AddAresta(5, 1);
    g.AddAresta(6, 5);
  
    std::cout << "Busca em profundidade iniciando com vertice 2:\n";
    g.BuscaEmProfundidade(2);
  
    return 0;
}