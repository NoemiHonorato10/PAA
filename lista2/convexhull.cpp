// Algoritmo em C ++ para encontrar a casca convexa de um conjunto de pontos em um plano.
// Achar os extremos requer tempo O(n)
// Melhor caso: T(n)=2T(n/2)+O(n) | Solução: O(n log n)
//Pior caso: quando cada partição esta extremanente desbalanceada: 
//           T(n)=T(n-1)+O(n)
//               =T(n-1)+cn
//Ou seja, O(n²) -> pior caso quadrático.
#include <iostream>
#include <stack> //pilha
#include <stdlib.h>
using namespace std;
 
struct Ponto
{
    int x, y;
};
 
// Um ponto global necessário para pontos de classificação com referência
// até o primeiro ponto Usado na função de comparação de qsort ()
Ponto p0;
 
// Uma função de utilidade para encontrar próximo do topo em uma pilha
Ponto proxParaTopo(stack<Ponto> &S)
{
    Ponto p = S.top();
    S.pop();
    Ponto res = S.top();
    S.push(p);
    return res;
}
 
// Uma função de utilidade para swapr(trocar) dois pontos
void swap(Ponto &p1, Ponto &p2)
{
    Ponto temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// Uma função de utilidade para retornar o quadrado da distância
// entre p1 e p2
int distSq(Ponto p1, Ponto p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
// Para encontrar a orientação do trio ordenado (p, q, r).
// A função retorna os seguintes valores
// 0 -> p, q e r são colineares
// 1 -> Sentido horário
// 2 -> Anti-horário
int orientacao(Ponto p, Ponto q, Ponto r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // sentido horário ou anti-horário
}
 
// Uma função usada pela função de biblioteca qsort () para classificar um array de
// pontos em relação ao primeiro ponto
int compare(const void *vp1, const void *vp2)
{
   Ponto *p1 = (Ponto *)vp1;
   Ponto *p2 = (Ponto *)vp2;
   
   // Encontrar orientação
   int o = orientacao(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
// Imprime o casco convexo de um conjunto de n pontos.
void convexHull(Ponto points[], int n)
{
   // Encontre o ponto mais baixo
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
    // Escolha a parte inferior ou escolha a esquerda
    // mais pontos em caso de empate
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Coloque o ponto mais inferior na primeira posição, ou seja, faz a troca
   swap(points[0], points[min]);

   // Classifica n-1 pontos em relação ao primeiro ponto.
    // Um ponto p1 vem antes de p2 na saída classificada se p2
    // tem um ângulo polar maior (no sentido anti-horário
    // direção) do que p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Ponto), compare);
 
    // Se dois ou mais pontos fizerem o mesmo ângulo com p0,
    // Remova tudo, exceto aquele que está mais distante de p0
    // Lembre-se de que, na classificação acima, nosso critério foi
    // para manter o ponto mais distante no final quando mais de
    // um ponto tem o mesmo ângulo.
    int m = 1; // Inicializa o tamanho do array modificado
   for (int i=1; i<n; i++)
   {
       // Continue removendo i enquanto o ângulo de i e i + 1 é o mesmo
        // com respeito a p0
       while (i < n-1 && orientacao(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
       points[m] = points[i];
       m++;  // Atualizar o tamanho da matriz modificada
   }
 
   // Se a matriz de pontos modificada tiver menos de 3 pontos,
    // casco convexo não é possível
   if (m < 3) return;
 
   // Cria uma pilha vazia e empurra os primeiros três pontos
    // para isso.
   stack<Ponto> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Processo restantes n-3 pontos
   for (int i = 3; i < m; i++)
   {
      // Continue removendo o topo enquanto o ângulo formado por
       // pontos próximo ao topo, topo e pontos [i] tornam
       // uma curva não à esquerda
      while (S.size()>1 && orientacao(proxParaTopo(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   // Agora a pilha tem os pontos de saída, imprime o conteúdo da pilha
   while (!S.empty())
   {
       Ponto p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
 
// Programa de driver para testar as funções acima
int main()
{
    Ponto points[] = {{0, 3}, {1, 1}, {2, 2}, {5, 4},
                      {0, 0}, {1, 2}, {6, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
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
[5]http://www.dcs.gla.ac.uk/~pat/52233/slides/Hull1x1.pdf
*/
