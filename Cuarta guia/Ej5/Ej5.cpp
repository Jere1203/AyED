/*Desarrollar una función que dados n y m devuelva el combinatorio de m tomados de a n.
Usar función punto 2 m!/n!(m-n)!*/
#include<stdio.h>
#include<conio.h>
int factorial(int);
int combinatorio(int,int,int);

int main()
{
    int n,m,comb,fact1,fact2,fact3;
    printf("Ingrese 2 numeros para obtener su combinatorio\n");
    scanf("%d",&n);
    scanf("%d",&m);
    fact1=factorial(n);
    fact2=factorial(m);
    fact3=factorial(n-m);
    printf("El numero combinatorio es %d\n",combinatorio(fact1,fact2,fact3));
    getch();
}

int factorial(int n)
{
    int fact,i=0;
    fact=1;
    for(i=0;i<n;i++)
    {
        fact*=(n-i);
    }
    return fact;
}

int combinatorio(int factn,int factm,int fact3)
{
    int combin; 
    combin=factn/(factm*fact3);
    return combin;
}