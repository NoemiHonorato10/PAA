//Algoritmo busca em Largura Grafos - BFS (busca em largura) em C ++ 
//Complexidade:  O(n + m)
#include <iostream>
#include <list>
#include <memory>
   
class Graph
{
    int _V;    // número de vértices
    bool _direcionado;
    // ponteiro para um array contendo as listas de adjacências
    std::unique_ptr< std::list<int> > adj;  
      
public:
    Graph(int V, bool direcionado);// construtor
    // adiciona uma aresta no grafo
    void AddAresta(int v, int w);
    //faz uma busca em largura a partir de um vértice 
    void BuscaEmLargura(int s);

};
   
Graph::Graph(int V, bool direcionado) : adj(new std::list<int>[V])
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
   
void Graph::BuscaEmLargura(int s)
{
    bool *visitado = new bool[_V];
    for(int i = 0; i < _V; i++)
        visitado[i] = false;
   
    // Criando uma fila para busca em profundidade 
    std::list<int> fila;
   //Marque o nó atual como visitado e imprima-o
    visitado[s] = true;
    fila.push_back(s);
   
    // 'i' será usado para obter todos os vértices adjacentes de um vértice
    std::list<int>::iterator i;
   
    while(!fila.empty()) //Enquanto a fila for vazia
    {
        // Defila um vértice de fila e imprima-o
        s = fila.front();
        std::cout << s << " ";
        fila.pop_front();
   
        // Pega todos os vértices adjacentes do vértice defilad s
         // Se um adjacente não foi visitado, marque-o como visitado
         // e enfila isso
        for(i = (adj.get())[s].begin(); i != (adj.get())[s].end(); ++i)
        {
            if(!visitado[*i])
            {
                visitado[*i] = true;
                fila.push_back(*i);
            }
        }
    }
}
   
int main()
{
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
   
    std::cout << "Busca em largura iniciando com vertice 2:\n";
    g.BuscaEmLargura(2);
   
    return 0;
}