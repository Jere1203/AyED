/*Hacer un algoritmo que calcule el promedio de números enteros positivos ingresados por teclado
hasta que se ingrese un cero. Este cero sólo indica el fin de ingreso de datos, no se incluirá en el
promedio.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int nro,i,suma=0;
    float prom=0;
    printf("Ingrese numeros enteros positivos para calcular su promedio, ingrese 0 para finalizar\n");
    for(i;nro!=0;i++)
    {
        scanf("%d",&nro);
        suma+=nro;
    }
    prom=(float)suma/(i-1);
    printf("El promedio de los numeros ingresados es %f",prom);
    getch();
}