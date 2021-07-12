#include <bits/stdc++.h>

float mediana(std::vector<int> &vetor, int inicio, int fim)
{
    if (fim - inicio == 1)
    {

        return (float)(vetor[inicio] + vetor[fim]) / 2;
    }
    if (inicio == fim)
    {
        return vetor[inicio];
    }

    mediana(vetor, inicio + 1, fim -1);
}

int main()
{
    std::vector<int> vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << mediana(vetor, 0, vetor.size() - 1) << std::endl;
}