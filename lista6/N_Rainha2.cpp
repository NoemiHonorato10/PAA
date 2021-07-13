//Algoritmo Problema das N Rainhas em c++
#include <bits\stdc++.h>

void imprimir(std::vector<int> &sol)
{
    std::cout << " " <<std::endl;
    int n = 4;
    for (int i = 0; i < n; i++)
    std::cout << sol[i] <<std::endl;
}

bool verificar(std::vector<std::vector<int>> &tabela, int n, int linha, int coluna)
{ //coluna

    for (int i = 0; i < n; i++)
    {

        if (tabela[i][coluna] == 1) // verificar coluna
        {
            return false;
        }

        if (tabela[linha][i] == 1) //verificar linha
        {
            return false;
        }
    }
    // Verificando a diagonal principal de cima para baixo
    int j = coluna;
    for (int i = linha; i < n; i++)
    {
        if (tabela[i][j] == 1)
        {
            return false;
        }
        j++; // incrementa a coluna
    }
    // Verificando a diagonal principal de baixo para cima
     j = coluna;
    for (int i = linha; i >= 0; i--) // i igual a zero, pois volta para coluna e linha zero.
    {
        if (tabela[i][j] == 1)
        {
            return false;
        }
        j--; // incrementa a coluna
    }

    // Verificando a diagonal segundaria de cima para baixo
    j = coluna;
    for (int i = linha; i >= 0; i--) // aumenta a coluna e diminui a linha
    {
        if (tabela[i][j] == 1)
        {
            return false;
        }
        j++; // incrementa a coluna
    }

    // Verificando a diagonal segundaria de cima para baixo
     j = coluna;
    for (int i = linha; i < n; i++) // aumenta a linha e diminui a colina
    {
        if (tabela[i][j] == 1)
        {
            return false;
        }
        j--; // decrementa a coluna
    }

    return true;
}

void backtrack(std::vector<std::vector<int>> &tabela, int n, std::vector<int> &sol, int posicao)
{
    if (posicao == n)
    {
        imprimir(sol);
        return;
    }
    for (int linha = 0; linha < n; linha++)
    {
        if (verificar(tabela, n, linha, posicao))
        {
            tabela[linha][posicao] = 1;
            sol[linha] = posicao;
            backtrack(tabela, n, sol, posicao + 1);
            tabela[linha][posicao] = 0;
            sol[linha] = 0;
        }
    }
}

int main()
{
    std::vector<std::vector<int>> tabela = {{0, 0, 0, 0},
                                            {0, 0, 0, 0},
                                            {0, 0, 0, 0},
                                            {0, 0, 0, 0}};
    std::vector<int> sol = {0, 0, 0, 0};

    int posicao = 0;// para começar a verificação do zero linha e coluna
    backtrack(tabela, 4, sol, posicao);

    return 0;
}