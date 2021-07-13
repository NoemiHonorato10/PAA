//Grafo de M_Cores C++
#include <bits/stdc++.h>

class No
{
    // Uma classe de nó que armazena a cor e as bordas
    // conectado ao nó
public:
    int cor = 1;
//set - Conjuntos de contêineres que armazenam elementos 
//exclusivos seguindo uma ordem específica.
    std::set<int> arestas;
};

int pintar(std::vector<No> &no, int n, int m)
{

    // Cria um vetor visitado de n
    // nós, inicializado em zero
    std::vector<int> visitado(n + 1, 0);

    // maxcors usados até agora são 1 como
    // todos os nós são pintados com a cor 1
    int maxcors = 1;

    // Faça uma travessia da largura da primeira pesquisa completa de
    // todos os pontos de partida não visitados
    for (int sv = 1; sv <= n; sv++)
    {

        if (visitado[sv])
            continue;

        // Se o ponto de partida não for visitado,
        // marque como visitado e coloque-o na fila
        visitado[sv] = 1;
        std::queue<int> q;
        //push - Insere um novo elemento no topo do pilha
        q.push(sv);

        // Largura da primeira pesquisa percorrida começa aqui
        // empty - Retorna se a "string" está vazia (ou seja, se seu comprimento é 0 ).
        while (!q.empty())
        {
        //front - Retorna uma referência ao primeiro elemento do vetor .
            int topo = q.front();
        // pop - Remove o elemento em cima do pilha, reduzindo efetivamente seu tamanho em 
            q.pop();

            // Verificando todos os nós adjacentes
            // para a borda "superior" em nossa fila
            for (auto it = no[topo].arestas.begin();
                 it != no[topo].arestas.end(); it++)
            {

                // Se a cor do
                // nó adjacente é o mesmo, aumente em 1
                if (no[topo].cor == no[*it].cor)
                    no[*it].cor += 1;

                // Se o número de cores usadas dispara m, retornar
                // 0
                //max - Retorna o maior de a e b . Se ambos forem equivalentes, a será retornado.
                maxcors = std::max(maxcors, std::max(no[topo].cor,no[*it].cor));
                if (maxcors > m)
                    return 0;

                // Se o nó adjacente não for visitado,
                // marque como visitado e coloque-o na fila
                if (!visitado[*it])
                {
                    visitado[*it] = 1;
                    //push - Insere um novo elemento no topo do pilha
                    q.push(*it);
                }
            }
        }
    }

    return 1;
}

int main()
{
    int n = 4;
    bool graph[n][n] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    int m = 3; // Número de cores

    // Cria um vetor de n + 1
    // nós do tipo "nó"
    // A posição zero é apenas
    // fictícia (1 é para ser usado)
    std::vector<No> no(n + 1);

    // Adicione arestas a cada nó de acordo com a entrada fornecida
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                // Conecte o gráfico não direcionado
                no[i].arestas.insert(i);
                no[j].arestas.insert(j);
            }
        }
    }

    // Exibir resposta final - pode pintar
    std::cout << pintar(no, n, m);
    std::cout << "\n";

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
