//Dados 3 números enteros positivos, muestre la suma, la resta y la multiplicación de todos.
#include <stdio.h>
#include <conio.h>

int main ()
{
    int no1,no2,no3,suma,resta,producto;
    scanf("%d %d %d",&no1,&no2,&no3);
    suma=no1+no2+no3;
    resta=no1-no2-no3;
    producto=no1*no2*no3;
    printf("Suma= %d\nResta= %d\nProducto= %d",suma,resta,producto);
    getch();
}