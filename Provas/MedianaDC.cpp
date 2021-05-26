//Algoritmo da Mediana Diminuir e Conquista
//Teorema Mestre T(n)= aT(n/b)+f(n)
//Relação de recorrência: T(n) = 2T(n/2)+1 T(1)=0
#include <bits/stdc++.h>

float mediana(std::vector<int> &vetor, int inicio, int fim)
{
    if (fim - inicio == 1) // condição para achar o valor  se for Par
    {
        return (float)(vetor[inicio] + vetor[fim]) / 2; //Retorna float caso seja decimal
    }

    if (inicio == fim)  //condição para chegar ao valor se for Impar
    {
        return vetor[inicio];
    }

    mediana(vetor, inicio + 1, fim - 1);
}

int main()
{                 //Posição:  0| 1| 2| 3| 4| 5| 6| 7| 8| 9
    std::vector<int> vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Mediana:\n";
    std::cout << mediana(vetor, 0, vetor.size() - 1) << std::endl;

    return 0;
}