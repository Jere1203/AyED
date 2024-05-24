/*Dados dos valores que se ingresan por teclado, mostrar por pantalla el menor de ellos.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float val1,val2;
    scanf("%f %f",&val1,&val2);
    if(val1<val2) printf("El valor mas chico es %f",val1);
    if(val2<val1) printf("El valor mas chico es %f",val2);
    getch();
}