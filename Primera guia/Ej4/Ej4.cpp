/*Obtener la edad de una persona en meses, si se ingresa su edad en años y meses.
Ejemplo: Ingresado 3 años 4 meses debe mostrar 40 meses.*/
#include<stdio.h>
#include<conio.h>
#define anio 12

int main()
{
    int edad,meses,convAnios,sumaMeses;
    printf("Ingrese edad en años y meses\n");
    scanf("%d %d",&edad,&meses);
    convAnios=edad*anio;
    sumaMeses=convAnios+meses;
    printf("La edad ingresada en meses es de %d meses",sumaMeses);
    getch();
}