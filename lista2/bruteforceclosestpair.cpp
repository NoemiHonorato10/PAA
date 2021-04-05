//Algoritmo brute force closest pair em C ++ 
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
//Algoritmo  de Brute Force Closest Pair
// Um programa de divisão e conquista para encontrar a menor distância de um
// determinado conjunto de pontos.
// Uma estrutura para representar um Ponto no plano 2D
struct Ponto
{
    int x, y;
};
// Necessário classificar a matriz de pontos de acordo com a coordenada X
int compararX(const void *a, const void *b)
{
    Ponto *p1 = (Ponto *)a, *p2 = (Ponto *)b;
    return (p1->x - p2->x);
}
// Necessário para classificar a matriz de pontos de acordo com a coordenada Y
int compararY(const void *a, const void *b)
{
    Ponto *p1 = (Ponto *)a, *p2 = (Ponto *)b;
    return (p1->y - p2->y);
}

// Uma função de utilidade para encontrar a distância entre dois pontos
float dist(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Um método de força bruta para retornar a menor distância entre dois pontos
// em P [] de tamanho n
float forcaBruta(Ponto P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// Uma função de utilidade para encontrar um mínimo de dois valores flutuantes
float min(float x, float y)
{
    return (x < y) ? x : y;
}

// Uma função de utilidade para encontrar a distância entre os pontos mais próximos de
// tira de um determinado tamanho. Todos os pontos na faixa [] são classificados de acordo com
// coordenada y. Todos eles têm um limite superior na distância mínima como d.
// Observe que este método parece ser um método O (n ^ 2), mas é um método O (n)
// método já que o loop interno é executado no máximo 6 vezes
float stripClosest(Ponto strip[], int tamanho, float d)
{
    float min = d; // Inicializa a distância mínima como d

    // Escolha todos os pontos um por um e tente os próximos pontos até a diferença
    // entre as coordenadas y é menor que d.
    // É um fato comprovado que este loop roda no máximo 6 vezes
    for (int i = 0; i < tamanho; ++i)
        for (int j = i + 1; j < tamanho && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// Uma função recursiva para encontrar a menor distância. A matriz Px contém
// todos os pontos classificados de acordo com as coordenadas x e Py contém todos os pontos
// classificado de acordo com as coordenadas y
float closestUtil(Ponto Px[], Ponto Py[], int n)
{
    // Se houver 2 ou 3 pontos, use força bruta
    if (n <= 3)
        return forcaBruta(Px, n);

    // Encontre o ponto médio
    int mid = n / 2;
    Ponto midPoint = Px[mid];

    // Divide os pontos no array ordenado y em torno da linha vertical.
    // Suposição: Todas as coordenadas x são distintas.
    Ponto Pyl[mid];     // y pontos classificados à esquerda da linha vertical
    Ponto Pyr[n - mid]; // y pontos classificados à direita da linha vertical
    int li = 0, ri = 0; // índices de subarrays esquerdo e direito
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x && li < mid)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    // Considere a linha vertical passando pelo ponto médio
    // calcula a menor distância dl à esquerda do ponto médio e
    // dr no lado direito
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n - mid);

    // Encontre a menor das duas distâncias
    float d = min(dl, dr);

    // Constrói uma faixa de matriz [] que contém pontos próximos (mais próximos do que d)
    // para a linha que passa pelo ponto médio
    Ponto strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    // Encontre os pontos mais próximos na faixa. Retorne o mínimo de d e o mais próximo
    // a distância é strip []
    return stripClosest(strip, j, d);
}

// A função principal que encontra a menor distância
// Este método usa principalmente closestUtil()
float closest(Ponto P[], int n)
{
    Ponto Px[n];
    Ponto Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    qsort(Px, n, sizeof(Ponto), compararX);
    qsort(Py, n, sizeof(Ponto), compararY);

    // // Use a função recursiva closestUtil() para encontrar a menor distância
    return closestUtil(Px, Py, n);
}

// Programa de driver para testar as funções acima
int main()
{
    Ponto P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "A menor distancia " << closest(P, n);
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
[5]Função de biblioteca qsort ().Consulte: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
