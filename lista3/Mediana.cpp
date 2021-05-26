#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

//Mediana em C++

int main()
{
    int tamanho = 0;
    float mediana = 0;

    //Pega o valor digitado

    std::cout << "Qual o total de numeros? ";
    std::cin >> tamanho;

    int v[tamanho];
    if (tamanho > 0)
    {

        for (int i = 0; i < tamanho; i++)
        {

            std::cout << "Digite o valor? ";
            std::cin >> v[i];
        }
    }

    // para a mediana matematica tem que ordenar o vetor v crescente aqui antes de buscar a mediana

    if (tamanho % 2 != 0) //resto da divisão, para verificar se o tamanho do vetor é impar
    {                             
        mediana = v[tamanho / 2]; //pega o elemento do meio
    }
    else
    {
        mediana = (float)(v[tamanho / 2 - 1] + v[tamanho / 2]) / 2; // pega os valores do meio soma e faz a média.
    }

    std::cout << "Mediana: \n";
    std::cout << mediana << std::endl;

    return 0;
}