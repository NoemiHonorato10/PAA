#include <bits/stdc++.h>
//T(n) = 2T(n/2) + n 
std::pair<int, int> compara(std::vector<int>&elemento, int e, int d)
{
    if (e == d)// condição de parada
    {
        // retorna recursivamente T(1)=0 |T(n) = 2*T(n/2) + 2
        return std::make_pair(e,e);//Constrói um par de objetos
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
    std::vector<int> vetor = {4,8,70,45,63,7,9,150,-1};
    int maior = compara(vetor, 0,vetor.size()-1).second;
    int menor = compara(vetor, 0, vetor.size()-1).first;

    std::cout << "Menor: " << menor << std::endl;
    std::cout << "Maior: " << maior << std::endl;

    return 0;
}