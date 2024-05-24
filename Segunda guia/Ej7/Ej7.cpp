/*Dado tres valores que representan las longitudes de segmentos determinar e imprimir una
leyenda según sea: “Forman triangulo” o “No forman triangulo”.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float cat1,cat2,cat3,suma,suma2,suma3;
    printf("Ingrese valores para tres catetos de un triangulo\n");
    scanf("%f %f %f",&cat1,&cat2,&cat3);
    suma=cat1+cat2;
    suma2=cat2+cat3;
    suma3=cat3+cat1;
    if(suma>cat3||suma2>cat1||suma3>cat2) printf("Forma triangulo");
    else printf("No forman triangulo");
    getch();
}