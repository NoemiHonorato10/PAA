//Algoritmo Brute Force String Match em C++
#include<iostream>
#include<cstring>
using namespace std;

int n;
int m;
char t[100];
char p[100];
int bruteforceStringMatch(char t[100],char p[100],int n,int m)
{
    int i;
    int j;
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m&&p[j]==t[i+j])
            j++;
        if(j==m){
            cout << "A caracter esta na posicao :\n" << i;
            return i;
        }

    }
    cout << "A caracter nao esta entre os digitados \n";
            return -1;
}
int main()
{
    int local;
    cout << "Digite os caracteres \n";
    cin >> t;

    cout << "Digite o caracter que deseja pesquisar\n";
    cin >> p;
    n=strlen(t);
    m=strlen(p);
    local=bruteforceStringMatch(t,p,n,m);
   //cout << local;
    return 0;
}
/*Referências: 
[1]Introduction to the design & analysis of algorithms / Anany Levitin. — 3rd ed.
Tenenbaum, Aaron M.
[2]Estruturas de dados usando C / Aaron M. Tenenbaum,Yedidyah Langsam, Moshe J. Augenstein ; tradução
Teresa Cristina Félix de Souza ; revisão técnica e adaptação dos programas Roberto Carlos Mayer. —
São Paulo : MAKRON Books, 1995.
[3]Introdução à Programação Curso em C++ Dr. Alan R. R. de Freitas,ALANDEFREITAS.COM
Edição: 19 de Março de 2015.
[4]Algoritmos / Thomas H. Cormen... [et al.] ; [tradução Arlete Simille Marques]. - 
Rio de Janeiro : Elsevier, 2012. il.
Tradução de: Introduction to algorithms, 3rd ed.
1. Programação (Computadores). 2. Algoritmos de computador. 3. 
Estruturas de dados (Computadores). I. Cormen, Thomas H.
*/