/*Un empresario constructor sabe que necesita 0,5 metros cúbicos de arena por metro
cuadrado de revoque a realizar. Hacer un programa donde ingrese las medidas de una
pared (largo y alto) expresada en metros y obtenga la cantidad de arena necesaria para
revocarla.*/
#include<stdio.h>
#include<conio.h>
#define ARENA 0.5

int main()
{
    float largo,alto,superficie,arenaNec;
    scanf("%f %f",&largo,&alto);
    superficie=largo*alto;
    arenaNec=superficie*ARENA;
    printf("Para una pared de %f metros cuadrados, se necesitan %f metros cubicos de arena",superficie,arenaNec);
    getch();
}