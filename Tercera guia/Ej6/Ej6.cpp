/*Hacer un algoritmo que ingrese por teclado un número entero n y a continuación ingrese n
números más de los que tendrá que informar su promedio.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int numMax,num,i,suma=0;
    float prom;
    printf("Ingrese un numero 'n'\n");
    scanf("%d",&numMax);
    printf("Ingrese valores para calcular el promedio\n");
    for(i=0;i<numMax;i++)
    {
        scanf("%d",&num);
        prom+=num;
    }
    prom/=(float)numMax;
    printf("El promedio final es: %f\n",prom);
    getch();
}