/*Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los
menores que –10.*/
#include<stdio.h>
#include<conio.h>
#define MAX 5

int main()
{
    int i,numero,suma=0,sumaNeg=0,cant=0;
    float promedio=0;
    printf("Ingrese 50 numeros:\n");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&numero);
        if(numero>100)
        {   
            cant++;
            suma+=numero;
        }
        if(numero<-10)
        {
            sumaNeg+=numero;
        }
    }
    promedio=(float)(suma/cant);
    printf("El promedio de los numeros mayores que 100 es %f\n",promedio);
    printf("La suma de los numeros menores que -10 es %d",sumaNeg);
    getch();
}