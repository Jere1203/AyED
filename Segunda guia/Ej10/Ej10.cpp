/*Hacer un algoritmo que ingresando por teclado el mes (1 a 12) y el año (4 dígitos), informe la
cantidad de días que tiene el mes.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int mes,anio;
    printf("Ingrese mes y año en formato --/----\n");
    scanf("%d %d",&mes,&anio);
    switch (mes)
    {
    
    case 12:
    case 10:
    case 8:
    case 7:
    case 5:
    case 3:
    case 1:
        printf("El mes tiene 31 dias");
        break;

    case 2:
        if(anio%4==0 && (anio%400==0 || anio%100!=0))
        {
            printf("El mes tiene 29 dias");
        }
        else printf("El mes tiene 28 dias");
        break;

    case 11:
    case 9:
    case 6:
    case 4:
        printf("El mes tiene 30 dias");
        break;
    }
    getch();
}