// Um programa C ++ recursivo para
// calcula o tamanho da árvore
#include <bits/stdc++.h>
  
/* Um nó da árvore binária tem dados, ponteiro para filho esquerdo
e um ponteiro para a criança direita */
class no 
{ 
    public:
    int dados; 
    no* esquerda; 
    no* direita; 
}; 
  
/* Função auxiliar que aloca um novo nó com o
dados fornecidos e ponteiros NULL para a esquerda e para a direita. */
no* novoNo(int dados) 
{ 
    no* No = new no();
    No->dados = dados; 
    No->esquerda = NULL; 
    No->direita = NULL; 
          
    return(No); 
} 
  
/* Calcula o número de nós em uma árvore. */
int size(no* no) 
{ 
    if (no == NULL) 
        return 0; 
    else
        return(size(no->esquerda) + 1 + size(no->direita)); 
} 
  
int main() 
{ 
    no *raiz = novoNo(1); 
    raiz->esquerda = novoNo(2); 
    raiz->direita = novoNo(3); 
    raiz->esquerda->esquerda = novoNo(4); 
    raiz->esquerda->direita = novoNo(5); 
      
    std::cout << "O tamanho da arvore: " << size(raiz); 
    return 0; 
} 
/*
Complexidade de tempo: O(n) 
Vejamos diferentes casos extremos. 
Função de complexidade T(n) - para todos os problemas em que a travessia
 da árvore está envolvida - pode ser definida como:
T(n) = T(k) + T(n - k - 1) + c
Onde k é o número de nós em um lado da raiz e nk-1 do outro lado.
Vamos fazer uma análise das condições de contorno
Caso 1: Árvore enviesada (uma das subárvores está vazia e a outra não está vazia)
k é 0 neste caso. 
T(n) = T (0) + T(n-1) + c 
T(n) = 2T (0) + T(n-2) + 2c 
T(n) = 3T (0) + T(n- 3) + 3c 
T(n) = 4T (0) + T(n-4) + 4c
--------------------------------
T(n) = (n-1) T(0) + T(1) + (n-1) c 
T(n) = nT (0) + (n) c
O valor de T (0) será alguma constante, digamos d. 
(percorrer uma árvore vazia levará algum tempo constantes)
T(n) = n (c + d) 
T(n) = Θ (n) (Theta de n)
Caso 2: Ambas as subárvores esquerda e direita têm igual número de nós.
T(n) = 2T (| _n / 2_ |) + c
Esta função recursiva está na forma padrão (T (n) = aT (n / b) + (-) (n)) 
para o método mestre http: // en.wikipedia.org/wiki/Master_theorem . 
Se resolvermos pelo método mestre, obteremos (-) (n)
Espaço Auxiliar: Se não considerarmos o tamanho da pilha para chamadas de função,
 então O (1), caso contrário, O (h) onde h é a altura da árvore. 
A altura da árvore inclinada é n (nº de elementos), 
então a pior complexidade do espaço é O (n) e a altura é (Log n) para a árvore balanceada, 
então a melhor complexidade do espaço é O (Log n).
*/