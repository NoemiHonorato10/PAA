#include <bits/stdc++.h>

using namespace std;

std::pair<int, int> compara(std::vector<int>&elemento, int e, int d)//T(n) = 2T(n/2) + n complexidade_merge
{
    if (e == d)// condição de parada
    {
        return std::make_pair(e,e); // retorna recursivamente T(1)=0 |T(n) = 2*T(n/2) + 2
    }
    int m = e + (d - e) / 2;
    std::pair<int, int>esquerda=compara(elemento, e, m);
    std::pair<int, int>direita=compara(elemento, m + 1, d);

    int menor1=esquerda.first, menor2=direita.first, maior1=esquerda.second, maior2=direita.second;

    int menor, maior;
    if(elemento[menor1] < elemento[menor2]){
        menor = menor1;
       
    }
     else{
         menor=menor2;
     }
      if(elemento[maior1] > elemento[maior2]){
        maior = maior1;
       
    }
     else{
         maior=maior2;
     }
    return std::make_pair(menor,maior);
}

int main()
{
    vector<int> vetor = {4,8,70,45,63,7,9,150,-1};
    int maior = compara(vetor, 0,vetor.size()-1).second;
    int menor = compara(vetor, 0, vetor.size()-1).first;

    cout << "Menor: " << menor << endl;
    cout << "Maior: " << maior << endl;

    return 0;
}