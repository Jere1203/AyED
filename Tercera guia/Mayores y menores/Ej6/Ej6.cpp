/*Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un
Nombre = ‘FIN’, informar el nombre de la persona con mayor edad y el de la más joven.*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    int anio,mes,dia,primIng=true,mayAnio,menAnio,mayMes,menMes,mayDia,menDia;
    char nombre[10],nombreMay[10],nombreMen[10];
    printf("Ingrese nombre y fecha de nacimiento en formato AAAA/MM/DD.\nIngrese 'FIN' para finalizar el ingreso\n");
    while(nombre!="FIN")
    {
        scanf("%s",&nombre);
        if(strcmp(nombre,"FIN")==0) break;
        scanf("%d %d %d",&anio,&mes,&dia);
        if(primIng==true)
        {
            mayAnio=anio;
            menAnio=anio;
            mayMes=mes;
            menMes=mes;
            mayDia=dia;
            menDia=dia;
            primIng=false;
            strcpy(nombreMay,nombre);
            strcpy(nombreMen,nombre);
        }
        if(anio>mayAnio)
        {
            mayAnio=anio;
            if(mes>=mayMes)
            {
                mayMes=mes;
                if(dia>=mayDia)
                {
                    mayDia=dia;
                    strcpy(nombreMay,nombre);
                }
                strcpy(nombreMay,nombre);
            }
            strcpy(nombreMay,nombre);
        }
        
        if(anio<menAnio)
        {
            menAnio=anio;
            if(mes<=menMes)
            {
                menMes=mes;
                if(dia<=menDia)
                {
                    menDia=dia;
                    strcpy(nombreMen,nombre);
                }
                strcpy(nombreMen,nombre);
            }
            strcpy(nombreMen,nombre);
        }
    
        if(anio==mayAnio)
        {
            if(mes==mayMes)
            {
                if(dia>mayDia)
                {
                    mayDia=dia;
                    strcpy(nombreMay,nombre);
                }
            }
            if(mes>mayMes)
            {
                mayMes=mes;
                if(dia>mayDia)
                {
                    mayDia=dia;
                    strcpy(nombreMay,nombre);
                }
                strcpy(nombreMay,nombre);
            }
        }

        if(anio==menAnio)
        {
            if(mes==menMes)
            {
                if(dia<menDia)
                {
                    menDia=dia;
                    strcpy(nombreMen,nombre);
                }
            }
            if(mes<menMes)
            {
                menMes=mes;
                if(dia<menDia)
                {
                    menDia=dia;
                    strcpy(nombreMen,nombre);
                }
                strcpy(nombreMen,nombre);
            }
        }
    }
    printf("La mayor persona es %s y la menor persona es %s",nombreMen,nombreMay);
    getch();
}