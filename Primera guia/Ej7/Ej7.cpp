/*Calcular el área y el perímetro de un rectángulo, dado la base y la altura.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float base,altura,perim,area;
    scanf("%f %f",&base,&altura);
    perim=(2*base)+(2*altura);
    area=base*altura;
    printf("El rectangulo tiene como perimetro %f y area %f",perim,area);
    getch();
}