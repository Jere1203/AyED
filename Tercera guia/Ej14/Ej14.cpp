/*Desarrollar un algoritmo que permita ingresar un conjunto de valores, cada uno de los cuales
representa el sueldo de un empleado (se sabe que un sueldo igual a 0 indica el fin del conjunto), e
informe:
a) Cuántos empleados ganan menos de $900
b) Cuántos ganan $900 o más, pero menos de $1200
c) Cuántos ganan $1200 o más, pero menos de $2000
d) Cuántos ganan $2000 o más.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int cont900=0,cont900o1200=0,cont1200o2000=0,cont2000oMas=0,sueldo,i;
    printf("Ingrese sueldo\n");
    for(i=0;sueldo!=0;i++)
    {
        scanf("%d",&sueldo);
        if(sueldo<900 && sueldo!=0) cont900++;
        if(sueldo>=900 && sueldo<1200 && sueldo!=0) cont900o1200++;
        if(sueldo>=1200 && sueldo<2000 && sueldo!=0) cont1200o2000++;
        if(sueldo>=2000 && sueldo!=0) cont2000oMas++;
    }
    printf("En total, %d empleados ganan menos de $900,  %d ganan entre $900 y $1200, %d ganan entre $1200 y $2000, y %d empleados ganan mas de $2000",cont900,cont900o1200,cont1200o2000,cont2000oMas);
    getch();
}