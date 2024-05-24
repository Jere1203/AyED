/*Dado la longitud de los dos catetos de un triángulo rectángulo y mostrar la longitud de la
hipotenusa.*/
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    float ca1,ca2,hip;
    scanf("%f %f",&ca1,&ca2);
    hip=sqrt(pow(ca1,2)+pow(ca2,2));
    printf("La hipotenusa del triangulo es %f",hip);
    getch();
}