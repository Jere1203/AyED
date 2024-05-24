/*Confeccionar un programa que solicite dos valores reales positivos, expresados en cm. El
primero corresponde a la base y el segundo a la altura de un triángulo, se desea calcular el
valor de la superficie. Si la superficie calculada es menor a 100 cm2, expresarla en milímetros
cuadrados, caso contrario en metros cuadrados. Informar resultado con unidades. ( 1 m2 =
10.000 cm2)*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int base,altura,superf;
    printf("Ingrese valores de base y altura en cm\n");
    scanf("%d %d",&base,&altura);
    superf=(base*altura)/2;
    if(superf<100)
    {
        superf=superf*100;
        printf("La superficie del triangulo es de %dmm^2",superf);
    }
    else printf("La superficie del triangulo es de %dcm^2",superf);
    getch();
}