/*Dados n y m enteros positivos, informar su producto obtenido por sumas sucesivas.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int n,m,i,suma=0;
    printf("Ingrese un valor n\n");
    scanf("%d",&n);
    printf("Ingrese un valor m\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        suma+=n;
    }
    printf("El producto obtenido mediante sumas sucesivas de %d y %d es %d",n,m,suma);
    getch();
}