/*Se ingresa un número de tres cifras. Descomponerlo en unidades, decenas y centenas.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int nro,un,dec,cent;
    scanf("%d",&nro);
    cent=nro/100;
    dec=(nro/10)-(cent*10);
    un=nro%10;
    printf("Centenas %d\nDecenas %d\nUnidades %d",cent,dec,un);
    getch();
}