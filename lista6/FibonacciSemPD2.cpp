//Algoritmo de Fibonacci Recursivo e Programação Dinâmica
#include <bits/stdc++.h>

int fibonacci_rec(int n) // Fibonacci recusivo
{
    if (n == 0)//Caso base 1
    {
        return 0;
    }
    else if (n == 1)//caso base 2
    {
        return 1;
    }
    else
    {
        return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
    }
}

int fibonacci_pd(int n, std::vector<int> &memoria)//Programação Dinâmica
{

    if (memoria[n] != -1)
    {
        return memoria[n];
    }
    else
    {
        if (n <= 1)
        {
            memoria[n] = n;
        }
        else
        {
            memoria[n] = fibonacci_pd(n - 1, memoria) + fibonacci_pd(n - 2, memoria);
        }
        return memoria[n];
    }

    return 0;
}

int fibonacci_pd(int n)
{
    std::vector<int> memoria(n + 1, -1);
    return fibonacci_pd(n, memoria);
}

int main()
{
    std::cout << "Fibonacci\n";
    int n = 7;

    std::cout << fibonacci_rec(n) << std::endl;
    std::cout << fibonacci_pd(n) << std::endl;
    
}