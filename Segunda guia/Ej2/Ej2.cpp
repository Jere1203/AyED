/*Dado un número que se ingresa por teclado, informar si es par o impar.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int num;
    scanf("%d",&num);
    if(num%2==0) printf("El numero %d es par",num);
    else printf("El numero %d no es par",num);
    getch();
}