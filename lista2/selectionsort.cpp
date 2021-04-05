/* Algoritmo Selection Sort
ordenação por seleção é um algoritmo Θ(n²) em todas as entradas.
No entanto, o número de trocas de chave é Θ(n).
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

template <typename T>
void imprimirVector(vector<T>& elemento){

}
int main(){

    //vector<int> elemento = {89, 45, 68, 90, 29, 34, 17};
    vector<char> elemento = {'w', 's', 'h', 'n', 'a', 'o', 'e'};
    double aux;

    double menor; //Grava o menor elemento atual
    int posicao; //Grava a posição que se encontrar o menor elemento
    bool troca; // saber se precisa haver troca ou não.
    for (int i = 0; i < 6; i++) // For - para contar quantas vezes vou repetir isso, limitado a posição a 6, pois tem o incremento.
    {
        menor = elemento[i]; // o menor vai para posição 0, pois o i começa com 0.
        posicao = i; // gravar a posição
        troca = false;
        for (int j = i + 1; j < 7; j++)//Vai varrer todas as posições
        {
            if (elemento[j] < menor)// Faz a verificação
            {
                menor = elemento[j];// Se for menor, grava o valor
                posicao = j;// a posição era 0 agora passa a valer 1
                troca = true;// Continua até o valor passar por todos e ser o menor de todos
            }
        }
        if (troca == true)// Faz a troca
        {
            aux = elemento[i]; // Grava o elemento que estava na primeira posição
            elemento[i] = menor;// O elemento da primeira possição passa a ser o menor (no caso 1).
            elemento[posicao] = aux;// Faz a troca - O elemento da segunda posição(no caso 2) passar a ser o auxiliar(que era o elelmento da 1ªPosição).
        }
    }
    cout << "\nOrdenado por Selection Sort: " << endl;
    for (int i = 0; i < 7; i++)
        cout << elemento[i] << "  ";
    cout << endl;
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