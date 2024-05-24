/*Dados tres valores que se ingresan por teclado, mostrar por pantalla el valor mayor.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float val1,val2,val3;
    scanf("%f %f %f",&val1,&val2,&val3);
    if(val1>val2&&val1>val3) printf("%f es el valor mayor",val1);
    if(val2>val1&&val2>val3) printf("%f es el valor mayor",val2);
    if(val3>val1&&val3>val2) printf("%f es el valor mayor",val3);
    getch();
}