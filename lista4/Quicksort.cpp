#include <bits/stdc++.h>
/* 
*Programa C ++ para quicksort
Análise geral

Tabela: Custo do algoritmo quicksort em suas situações mais comuns

	Caso	|		Descrição						|		Custo
Pior caso 	|	pivô sempre maior ou menor elemento |		O(n²)
Caso médio 	|	pivô aleatório 						|		O(nlogn)
Melhor caso |	pivô sempre elemento mediano 		|		O(nlogn)

 Melhor caso:
Pior caso:
Anáslise Assintótica:
 */

class Quicksort
{
private:
    /**
     * Vetor de inteiros a ser ordenado
     */
    std::vector<char> &elementos;

    /**
     * Tamanho do vetor
     */
    int size;

    /**
     * Método de particionamento que é o núcleo do algoritmo Quicksort.
     * É a implementação utilizando o paradigma dividir para conquistar
     */
    int partition(const int start, const int end)
    {
        int i = start;

        for (int j = start; j < end; j++)
        {

            /*  Elemento atual menor ou igual ao pivô? */
            if (elementos[j] <= elementos[end])
            {
                swap(i++, j);
            }
        }
        swap(i, end);

        return i;
    }

    /**
     * Método para fazer a troca de dados entre duas posições no vetor
     */
    void swap(const int i, const int j)
    {
        int k = elementos[i];
        elementos[i] = elementos[j];
        elementos[j] = k;
    }

    /**
     * Método privado que implementa o Quicksort recursivamente
     */
    void quicksort(const int start, const int end)
    {
        snapshot();

        if (start >= end)
            return;

        int pivot = partition(start, end);

        quicksort(start, pivot - 1);
        quicksort(pivot + 1, end);
    }

    /**
     * Método utilizado para debugging. Imprime na tela uma 'foto' do vetor
     */
    void snapshot() // Passo a passo
    {
        std::cout << "[";
        for (auto i = elementos.begin(); i < elementos.end() - 1; i++)
        {
            std::cout << *i << ", ";
        }
        std::cout << elementos.back() << "]" << std::endl;
    }

public:
    explicit Quicksort(std::vector<char> &elementos)
        : elementos(elementos),
          size(elementos.size())
    {
    }

    /**
     * Método publico que executa a ordenação
     */
    void Sort()
    {
        if (size <= 1)
            return;

        quicksort(0, size - 1);
        snapshot();
    }
};

int main()
{
    std::vector<char> elementos = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};

    //vector<int> elementos = {50, 42, 8, 23, 74, 91, 13, 26, 66, 3};
    std::cout << "Etapas do processo do QuickSort:\n";
    Quicksort sort(elementos);
    sort.Sort();

    return 0;
}