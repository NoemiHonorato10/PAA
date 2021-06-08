// Algoritmo de Strassen para multiplicação de matrizes em C++

/*
Ele usa a estratégia de dividir e conquistar e, 
portanto, divide a matriz quadrada de tamanho n para n / 2.
Ele reduz as 8 chamadas recursivas para 7.
Neste programa, usamos uma matriz 4 × 4.
*/
#include<iostream>

double a[4][4];
double b[4][4];

void inserir(double x[4][4])
{
	double val;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			std::cin>>val;
			x[i][j]=val;
		}
	}
}
double chama11(double x[4][4])
{
	return (x[1][1] * x[1][2])+ (x[1][2] * x[2][1]);
}
double chama21(double x[4][4])
{
	return (x[3][1] * x[4][2])+ (x[3][2] * x[4][1]);
}

double chama12(double x[4][4])
{
	return (x[1][3] * x[2][4])+ (x[1][4] * x[2][3]);
}

double chama22(double x[4][4])
{
	return (x[2][3] * x[1][4])+ (x[2][4] * x[1][3]);
}

int main()
{
	double a11,a12,a22,a21,b11,b12,b21,b22,a[4][4],b[4][4];
	double p,q,r,s,t,u,v,c11,c12,c21,c22;
	//insira valores na matriz a
	std::cout<<"\n Digite o valor da matriz a: \n";
	inserir(a);
	//insira valores na matriz b
	std::cout<<"\n Digite o valr da matriz b: \n";
	inserir(b);

	//Dividindo uma única matriz 4x4 em quatro matrizes 2x2
	a11=chama11(a);
	a12=chama12(a);
	a21=chama21(a);
	a22=chama22(a);
	b11=chama11(b);
	b12=chama12(b);
	b21=chama21(b);
	b22=chama22(b);

	//Atribui variáveis acc. para o algoritmo de strassen
	p=(a11+a22)*(b11+b22);
	q=(a21+a22)*b11;
	r=a11*(b12-b22);
	s=a22*(b21-b11);
	t=(a11+a12)*b22;
	u=(a11-a21)*(b11+b12);
	v=(a12-a22)*(b21+b22);

    //Apresenta a atriz final
std::cout<<"\n Matriz Final:";
 	std::cout<<"\n"<<p+s-t+v<<" "<<r+t;
	std::cout<<"\n"<<q+s<<" "<<p+r-q+u;
    return 0;
}