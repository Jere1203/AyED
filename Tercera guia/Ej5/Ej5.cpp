/*Calcular e informar la sumatoria de 10 números ingresados por teclado.*/
#include<stdio.h>
#include<conio.h>
#define MAX 10

int main()
{
    int num,i,suma=0;
    printf("Ingrese %d numeros\n",MAX);
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&num);
        suma+=num;
    }
    printf("La sumatoria de todos los numeros ingresados es: %d",suma);
    getch();
}