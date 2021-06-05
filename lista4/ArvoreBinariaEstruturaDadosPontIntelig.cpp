#include <iostream>
#include <memory>

//Algoritmo árvore binária: Complexidade de tempo: O(n) |
// pior complexidade do espaço é O(n) e a altura é (Log n) para a árvore balanceada.

class No
{
    int valor;
    public:
    std::shared_ptr<No> esquerda;
    std::shared_ptr<No> direita;
    // Acabei de alterar o shared_ptr para weak_ptr
//Weak_ptr permite o compartilhamento, mas não a propriedade de um objeto. Seu objeto é criado por um shared_ptr.
//Consequentemente, usando o weak_ptr, o problema de vazamento de memória é resolvido na da árvore binária.
    std::weak_ptr<No> pai;
    No(int val) : valor(val)     {
         std::cout<<"Construtor"<<std::endl; //constrói novo shared_ptr
    }
    ~No()     {
 //destrói o objeto de propriedade se não houver mais shared_ptrs um link para ele       
         std::cout<<"Desconstrutor"<<std::endl; 
    }
};

int main()
{
    std::shared_ptr<No> raiz = std::make_shared<No>(4);
    raiz->esquerda = std::make_shared<No>(2);
    raiz->esquerda->pai = raiz;
    raiz->direita = std::make_shared<No>(5);
    raiz->direita->pai = raiz;
    std::cout<<"contagem de referencia raiz = "<<raiz.use_count()<<std::endl;
    std::cout<<"raiz-> contagem de referencia Esquerda = "<<raiz->esquerda.use_count()<<std::endl;
    std::cout<<"raiz-> contagem de referencia de Direita = "<<raiz->direita.use_count()<<std::endl;
    //lock () pode retornar shared_ptr vazio se esse shared_ptr us já foi excluído.
    std::cout<<"raiz-> direita-> contagem de referencia pai = "<<raiz->direita->pai.lock().use_count()<<std::endl;
    std::cout<<"raiz-> esquerda-> pai contagem de referencia = "<<raiz->esquerda->pai.lock().use_count()<<std::endl;
    return 0;
}
// Referências
//https://en.cppreference.com/w/cpp/memory/shared_ptr

// make_shared - Constrói um objeto do tipo No o envolve em um 
// std :: shared_ptr usando argscomo a lista.

//weak_ptr é um ponteiro inteligente que contém uma referência 
//não proprietária ("fraca") a um objeto gerenciado por std :: shared_ptr .
//Deve ser convertido em std :: shared_ptr para acessar o objeto referenciado.

//std::shared_ptré um ponteiro inteligente que 
// retém a propriedade compartilhada de um objeto por 
// meio de um ponteiro. Vários shared_ptr objetos podem 
// possuir o mesmo objeto. O objeto é destruído e sua 
// memória desalocada.

//use_count - Retorna o número de shared_ptr instâncias que
//compartilham a propriedade do objeto gerenciado, ou 0 se o 
//objeto gerenciado já foi excluído, ou seja, * isto está vazia

//Passagem adiar_lock(bloqueio) para Unique_lock do construtor, 
//faz com que ele não bloqueie o objeto mutex automaticamente na construção,
//inicializando o objeto como não possuindo um bloqueio.

//No caso de referências cíclicas, ou seja, dois objetos referem-se 
//um ao outro usando shared_ptrs, altere um objeto para conter weak_ptr em vez de shared_ptr.