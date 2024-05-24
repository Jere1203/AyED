/*Dado un número entero positivo informar su factorial.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int n,i,factous;
    printf("Ingrese un numero para conocer su producto factorial\n");
    scanf("%d",&n);
    factous=n;
    for(i=n-1;i>0;i--)
    {
        factous*=(n-i);
    }
    printf("El factorial de %d es %d",n,factous);
    getch();
}