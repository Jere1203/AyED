/*Escribir un algoritmo que lea dos fechas (día, mes y año) e informe cual es la más reciente.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int dia,mes,anio,dia2,mes2,anio2;
    printf("Ingrese dos fechas en formato --/--/----\n");
    scanf("%d %d %d",&dia,&mes,&anio);
    scanf("%d %d %d",&dia2,&mes2,&anio2);
    if(anio<anio2)printf("La fecha %d/%d/%d es mas reciente.",dia2,mes2,anio2);
    if(anio2<anio)printf("La fecha %d/%d/%d es mas reciente.",dia,mes,anio);
    if(anio==anio2)
    {
        if(mes<mes2)printf("La fecha %d/%d/%d es mas reciente.",dia2,mes2,anio2);
        if(mes2<mes)printf("La fecha %d/%d/%d es mas reciente.",dia,mes,anio);
    }
    if(anio==anio2 && mes==mes2)
    {
        if(dia<dia2)printf("La fecha %d/%d/%d es mas reciente.",dia2,mes2,anio2);
        if(dia2<dia)printf("La fecha %d/%d/%d es mas reciente.",dia,mes,anio);
    }
    getch();
}