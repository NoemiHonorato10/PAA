#include <bits/stdc++.h>

/* Busca Binaria- Busaca recursivamente a chave dentro do vetor. A cada iteração
   reduz o espaço de busca pela metade. Quando encontra a chave retorna
   o índice(meio) onde ele foi encontrado. Caso contrário retorna -1 */


int buscaBinaria(std::vector<int> &vetor, int esquerdo, int direito, int chave)

{
    int meio = (esquerdo + direito) / 2;

    if (esquerdo > direito)
    {
        return -1;
    }

    if (vetor[meio] == chave)
    {
        return meio;
    }

    if (vetor[meio] < chave)
    {
        return buscaBinaria(vetor, meio + 1, direito, chave);
    }
    else
    { // vetor[meio] > chave
        return buscaBinaria(vetor, esquerdo, meio - 1, chave);
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
