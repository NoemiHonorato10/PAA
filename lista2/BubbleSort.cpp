//Algoritmo Bubble Sort - Pertence ao conjunto Teta de n ao quadrado - ∈ Θ(n²) em C++
#include <bits\stdc++.h>

int main()
{
    std::vector<int> elemento = {8, 10, 7, 5, 14, 16, 3};
    int aux;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (elemento[j] < elemento[j+1])
            {
                aux = elemento[j];
                elemento[j] = elemento[j+1];
                elemento[j+1] = aux;
            }
        }
    }
    for(int i = 0; i < 7; i++)
    std::cout << elemento[i] << " ";
    std::cout << std::endl;
    return 0;
}