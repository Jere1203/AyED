/*Informar la cantidad de números negativos que hay dentro de 20 números ingresados por teclado.*/
#include<stdio.h>
#include<conio.h>
#define MAX 20

int main()
{
    int num,i,contNeg=0;
    printf("Ingrese %d numeros\n",MAX);
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&num);
        if(num<0)contNeg++;
    }
    if(contNeg==1) printf("Hubo %d numero negativo en total",contNeg);
    else if(contNeg!=0) printf("Hubieron %d numeros negativos en total",contNeg);
    getch();
}