/*Desarrollar una función tal que dado un número entero positivo calcule y retorne su
factorial.*/
#include<stdio.h>
#include<conio.h>

int factorial(int);

int main()
{
    int fact,num;
    printf("Ingrese un numero positivo para conocer su factorial\n");
    scanf("%d",&num);
    fact=factorial(num);
    printf("El factorial de %d es %d",num,fact);
    getch();
}

int factorial(int n)
{
    int fact,i=0;
    fact=1;
    for(i=0;i<n;i++)
    {
        fact*=(n-i);
    }
    return fact;
}