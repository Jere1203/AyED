/*Dados 50 valores distintos que se ingresan por teclado, mostrar en qué posición se ingresó el
mayor.*/
#include<stdio.h>
#include<conio.h>
#define MAX 4

int main()
{
    int i,num,mayor,pos;
    printf("Ingrese %d valores\n",MAX);

    for(i=0;i<MAX;i++)
    {
        scanf("%d",&num);
        if(i==0)
        {
            mayor=num;
            pos=i+1;
        }  
        if(num>mayor)
        {
            mayor=num;
            pos=i+1;
        } 
    }
    printf("El mayor numero ingresado es el %d en la posicion %d",mayor,pos);
    getch();
}