/*Leer dos números y encontrar:
a. La suma del doble del primero mas el cuadrado del segundo.
b. El promedio de sus cubos. */
#include <stdio.h>
#include <conio.h>

int main()
{
    int no1,no2,suma,promedio;
    scanf("%d %d",&no1,&no2);
    suma=(2*no1)+(no2*no2);
    promedio=((no1*no1*no1)+(no2*no2*no2))/2;
    printf("La suma total es: %d\nEl promedio de sus cubos es: %d",suma,promedio);
    getch();
}