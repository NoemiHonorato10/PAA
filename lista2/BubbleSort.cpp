//Algoritmo Bubble Sort - Pertence ao conjunto Teta de n ao quadrado - ∈ Θ(n²) em C++
#include <iostream>
#include<cstdlib>
#include <vector>

//using namespace std;

template <typename T>
void imprimirVector(std::vector<T>& elemento){

}
int main() {

     std::vector<int> elemento = {89, 45, 68, 90, 29, 34, 17};
  // std::vector<char> elemento = {'w', 's', 'h', 'n', 'a', 'o', 'e'};
    double aux;
    //Crescente
  /*  
    for(int i=0; i<7; i++){ //Começa a troca, faz a varredura de par a par para trocar ou não.
        for(int j=0; j<6; j++){
            if(elemento[j] > elemento[j+1]){
                aux = elemento[j];
                elemento[j] = elemento[j+1];
                elemento[j+1] = aux;
            }
        }

    }
    */
    //decrescente

    for(int i=0; i<7; i++){ //Começa a troca, faz a varredura de par a par para trocar ou não.
        for(int j=i+1; j<6; j++){
            if(elemento[i] < elemento[j]){
                aux = elemento[i];
                elemento[i] = elemento[j];
                elemento[j] = aux;
            }
        }

    }
 std::cout << "\nOrdenar a matriz por Bubble Sort de forma crescente: " << std::endl;
    for(int i=0; i<7; i++)
         std::cout << elemento[i] << "  ";
     std::cout << std::endl;
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