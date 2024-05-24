/*Desarrollar una función que dados dos números, retorne verdadero si el primero es múltiplo
del segundo, falso en caso contrario.*/
#include <stdio.h>
#include <conio.h>

int mult(int,int);

int main()
{
    int num1,num2;
    bool esMult;
    printf("Ingrese 2 numeros para saber si uno es multiplo del otro\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    esMult=mult(num1,num2);
    if(esMult==true) printf("El numero %d es multiplo de %d",num1,num2);
    else printf("El numero %d no es multiplo de %d",num1,num2);
    getch();
}

int mult(int num1,int num2)
{
    bool mult;
    if(num1%num2==0) mult=true;
    return mult;
}