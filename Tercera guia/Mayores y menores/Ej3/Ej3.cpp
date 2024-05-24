/*Dados 50 valores que se ingresan por teclado, mostrar el mayor y la cantidad de veces que fue
ingresado*/
#include<stdio.h>
#include<conio.h>
#define MAX 50

int main()
{
    int i,num,mayor,cantRep;
    printf("Ingrese %d numeros\n",MAX);
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&num);
        if(num==mayor) cantRep++;
        if(i==0) mayor=num;
        if(num>mayor)
        {
            mayor=num;
            cantRep=0;
        }  
    }
    printf("El numero mayor es %d y se repitio %d veces",mayor,cantRep);
    getch();
}