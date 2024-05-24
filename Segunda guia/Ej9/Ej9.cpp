/*Dado un número de cinco cifras informar si es capicúa.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int numero,decmil,mil,cent,dec,un;
    scanf("%d",&numero);
    decmil=numero/10000;
    mil=(numero/1000)-(decmil*10);
    cent=(numero/100)-(mil*10)-(decmil*100);
    dec=(numero/10)-(cent*10)-(mil*100)-(decmil*1000);
    un=numero%10;
    if(decmil==un && mil==dec) printf("El numero %d es capicua",numero);
    getch();
}