/*Dados 50 valores distintos que se ingresan por teclado, mostrar el menor.*/
#include<stdio.h>
#include<conio.h>
#define MAX 4

int main()
{
    int i,numero,menor;
    printf("Ingrese %d valores\n",MAX);

    for(i=0;i<MAX;i++)
    {
        scanf("%d",&numero);
        if(i==0) menor=numero;
        if(numero<menor) menor=numero;
    }
    printf("El menor numero ingresado fue %d",menor);
    getch();
}