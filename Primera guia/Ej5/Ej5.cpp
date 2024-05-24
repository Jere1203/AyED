/*Dadas las notas de cuatro exámenes, mostrar la nota promedio.*/
#include<stdio.h>
#include<conio.h>
#define cantNotas 4
int main()
{
    int nota1,nota2,nota3,nota4,promedio;
    scanf("%d %d %d %d",&nota1,&nota2,&nota3,&nota4);
    promedio=(nota1+nota2+nota3+nota4)/cantNotas;
    printf("El promedio de las notas es %d",promedio);
    getch();
}