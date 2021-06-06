// Algoritmo do Caminhamentos  preorder, postorder e inorder para Árvore Binária.
#include <iostream>
using namespace std;
 
/* 
Pré-ordem: 
1. Executa a operação do algoritmo no nó atual
2. Se tem filho à esquerda: executa o pré-ordem no filho à esquerda.
3. Se tem filho à direita: execuuta o pré-ordem à direita.

Pós-ordem:
1. Se tem filho à esquerda: executa o pós-ordem no filho à esquerda.
2. Se tem filho à direita: execuuta o pós-ordem à direita.
3. Executa a operação do algoritmo no nó atual

Em ordem:
1. Se tem filho à esquerda: executa o em ordem no filho à esquerda.
2. Executa a operação do algoritmo no nó atual.
3. Se tem filho à direita: execuuta o em ordem à direita.
*/

struct No {
    char dados;
    struct No *esquerda, *direita;
    No(char dados)
    {
        this->dados = dados;
        esquerda = direita = NULL;
    }
};
 
/* Pré-ordem:*/
void Preorder(struct No* no)
{
    if (no == NULL)
        return;
 
    //Executa a operação do algoritmo no nó atual
    cout << no->dados << " ";
 
    //Se tem filho à esquerda: executa o pré-ordem no filho à esquerda.
    Preorder(no->esquerda);
 
   //Se tem filho à direita: execuuta o pré-ordem à direita.
    Preorder(no->direita);
}

/*Pós-ordem */
void Postorder(struct No* no)
{
    
    if (no == NULL)
        return;
 
    // Se tem filho à esquerda: executa o pós-ordem no filho à esquerda
    Postorder(no->esquerda);
 
    //Se tem filho à direita: execuuta o pós-ordem à direita.
    Postorder(no->direita);
 
    //Executa a operação do algoritmo no nó atual
    cout << no->dados << " ";
}

/* Em ordem*/
void Inorder(struct No* no)
{
    if (no == NULL)
        return;
 
    //Se tem filho à esquerda: executa o em ordem no filho à esquerda.
    Inorder(no->esquerda);
 
    //Executa a operação do algoritmo no nó atual.
    cout << no->dados << " ";
 
    //Se tem filho à direita: execuuta o em ordem à direita.
    Inorder(no->direita);
}
 
int main()
{
    struct No* raiz = new No('a');
    raiz->esquerda = new No('b');
    raiz->direita = new No('c');
    raiz->esquerda->esquerda = new No('d');
    raiz->esquerda->direita = new No('e');
    raiz->direita->direita = new No('f');
 
    cout << "\nPre-ordem da arvore binaria: \n";
    Preorder(raiz);

    cout << "\nPos-ordem da arvore binaria: \n";
    Postorder(raiz);
 
    cout << "\nEm ordem  da arvore binaria:\n";
    Inorder(raiz);
 
    return 0;
}