/*Se desea calcular el valor del cambio de moneda a Dólares y Euros ingresando la cantidad
en Pesos y las cotizaciones.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float cantPesos,cotDolar,cotEuro,pFinalEuro,pFinalDolar;
    printf("Ingrese cantidad en pesos, cotizacion del dolar y cotizacion del euro\n");
    scanf("%f %f %f",&cantPesos,&cotDolar,&cotEuro);
    pFinalDolar=cantPesos/cotDolar;
    pFinalEuro=cantPesos/cotEuro;
    printf("%f pesos equivale a %f dolares y %f euros",cantPesos,pFinalDolar,pFinalEuro);
    getch();
}