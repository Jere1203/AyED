/*Dados tres valores que representan los lados de un triángulo, informar si el mismo es
equilátero, isósceles o escaleno.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float cat1,cat2,cat3;
    printf("Ingrese valores para tres catetos de un triangulo\n");
    scanf("%f %f %f",&cat1,&cat2,&cat3);
    if(cat1!=cat2&&cat1!=cat3&&cat2!=cat3) printf("El triangulo es escaleno");
    
    if(cat1==cat2||cat1==cat3||cat2==cat3)
    {
        if(cat1!=cat2||cat1!=cat3||cat2!=cat3)printf("El triangulo es isosceles");
    } 
   
    if(cat1==cat2&&cat1==cat3&&cat2==cat3) printf("El triangulo es equilatero");
    getch();
}