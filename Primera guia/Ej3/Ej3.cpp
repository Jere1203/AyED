/*Determinar la suma de las cifras de un número entero positivo de 4 cifras. Ejemplo: Dado
8125, la suma es 16.*/
#include <stdio.h>
#include <conio.h>

int main()
{
    int no=0,mil=0,cent=0,dec=0,uni=0,suma=0;
    scanf("%d",&no);
    mil=no/1000;
    cent=(no/100)-(mil*10);
    dec=(no/10)-((mil*100)+(cent*10));
    uni=no%10;
    suma=mil+cent+dec+uni;
    printf("Del numero %d la suma de sus cifras es %d",no,suma);
    getch();
}