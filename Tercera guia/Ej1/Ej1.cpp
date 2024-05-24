/*Ingresar 10 números por teclado y mostrar sólo los positivos.*/
#include<stdio.h>
#include<conio.h>
#define MAX 10

int main()
{
    int num,i;
    printf("Ingrese 10 numeros\n");
    /*for(i=0;i<MAX;i++)
    {
        scanf("%d",&num[i]);
    }*/
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&num);
        if(num>0) printf("El numero: %d es positivo\n",num);
    }
    getch();
}