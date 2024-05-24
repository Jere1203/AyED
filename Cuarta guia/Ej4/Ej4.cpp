/*Dada una serie de números enteros positivos que finalizan con cero, informar:
a) su factorial
b) cuantos múltiplos de 3
c) cuantos múltiplos de 5
d) cuantos múltiplos de 3 y de 5
Utilice las funciones de ejercicios anteriores*/
#include<stdio.h>
#include<conio.h>
int factorial(int);
int mult3(int);
int mult5(int);
int mult3y5(int);

int main()
{
    int numero=1,contMult3=0,contMult5=0,contMult3y5=0;
    printf("Igrese serie de numeros, para finalizar ingrese el numero 0\n");
    while(numero!=0)
    {
        scanf("%d",&numero);
        if(numero==0)break;
        printf("%d\n",factorial(numero));
        /*contMult3=mult3(numero);
        contMult5=mult5(numero);
        contMult3y5=mult3y5(numero);*/
        if(numero%3==0 && numero%5!=0) contMult3++;
        if(numero%5==0 && numero%3!=0) contMult5++;
        if(numero%5==0 && numero%3==0) contMult3y5++;
    }
    printf("Hubieron en total %d numeros multiplos de 3, %d multiplos de 5 y %d multiplos de 5 y 3 al mismo tiempo\n",contMult3,contMult5,contMult3y5);
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
/*
int mult3(int num)
{
    int cont;
    
    return cont;
}

int mult5(int num)
{
    int cont2;
    if(num%5==0) cont2++;
    return cont2;
}

int mult3y5(int num)
{
    int cont3;
    if(num%5==0 && num%3==0) cont3++;
    return cont3;
}
*/