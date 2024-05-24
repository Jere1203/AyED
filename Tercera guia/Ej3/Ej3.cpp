/*Informar los primeros n números pares positivos, siendo n un número entero positivo ingresado
por teclado.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    unsigned int n,i;
    printf("Ingrese un numero 'n'\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i%2==0) printf("%d\n",i);
    }
    getch();
}