/*Se ingresan dos valores por teclado si el primero es mayor al segundo, informar la resta de los
valores, en caso contrario la suma.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float num1,num2,suma,resta;
    scanf("%f %f",&num1,&num2);
    if(num1>num2)
    {
        resta=num1-num2; 
        printf("La resta de los numeros %f y %f es igual a %f",num1,num2,resta);
    } 
    if(num1<num2)
    {
        suma=num1+num2; 
        printf("La suma de los numeros %f y %f es %f",num1,num2,suma);
    } 
    getch();
}