/*En una empresa vendedora de alambres se quiere calcular el precio de un pedido. Para ello
se ingresa los metros pedidos. El precio del alambre es de 75 pesos por metro.*/
#include<stdio.h>
#include<conio.h>
#define METRO 75

int main()
{
    int distancia,precio;
    scanf("%d",&distancia);
    precio=distancia*METRO;
    printf("El precio para %d metros es de %d pesos",distancia,precio);
    getch();
}