/*Dados 50 valores distintos que se ingresan por teclado, mostrar los dos mayores.*/
#include<stdio.h>
#include<conio.h>
#define MAX 4

int main()
{
    int i,num,may1,may2;
    printf("Ingrese 50 valores distintos\n");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&num);
        if(i==0)
        {
            may1=num;
        }
        if(num>may1)
        {
            may1=num;
        } 
        if(num>may2 && i%2!=0)
        {
            may2=num;
        }
    }
    printf("Los 2 numeros mayores son %d y %d",may1,may2);
    getch();
}