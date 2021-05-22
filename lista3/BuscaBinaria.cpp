#include <bits/stdc++.h>

/* Busca Binaria- Busca recursivamente a chave dentro do vetor. A cada iteração
   reduz o espaço de busca pela metade. Quando encontra a chave retorna
   o índice(meio) onde ele foi encontrado. Caso contrário retorna -1 

   Relação de recorrência: 
   T(n) = 1*T(n/2)+ Θ(1)
        = T(n/2)+1
*/

int buscaBinaria(std::vector<int> &vetor, int esquerdo, int direito, int chave)

{
    int meio = (esquerdo + direito) / 2; //C1+C2+C3|Três constantes somadas é uma constante Θ(1)

    if (esquerdo > direito) //Busca enquanto tiver espaço no vetor 
    {
        return -1; //Se o valor não for encontrado retorna -1
    }

    if (vetor[meio] == chave) //Cálculo do valor médio
    {
        return meio; //Se for igual o índice encontrado 
    }

    if (vetor[meio] < chave) // Se não, busca a metade da direita
    { // Ou entrar aqui
        return buscaBinaria(vetor, meio + 1, direito, chave); //reduz o vetor do meio ao fim
    }
    else // Ou aqui... ou uma ou outra. | T(n)=1
    { // vetor[meio] > chave
        return buscaBinaria(vetor, esquerdo, meio - 1, chave); //reduz o vetor do início ao meio
    }
}

int main()
{
    int numero;
    std::cout << "Digite o numero a ser pesquisado:\n";
    std::cin >> numero;
    std::vector<int> vetor = {1, 5, 8, 19, 25, 43, 99};

    if (buscaBinaria(vetor, 0, vetor.size(), numero) >= 0)
    {
        std::cout << "Encontrado" << std::endl;
    }
    else
    {
        std::cout << "Nao encontrado" << std::endl;
    }

    return 0;
}
