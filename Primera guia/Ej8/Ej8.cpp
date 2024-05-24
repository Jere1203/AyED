/*Determinar el porcentaje de alumnos aprobados, desaprobados y ausentes que hubo en un
examen, conociendo las cantidades de cada uno.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    float alumnosAprob,alumnosDesap,alumnosAus,sumaAlumnos,porcAprob,porcDesap,porcAus;
    scanf("%d %d %d",&alumnosAprob,&alumnosDesap,&alumnosAus);
    sumaAlumnos=alumnosAprob+alumnosDesap+alumnosAus;
    porcAprob=(alumnosAprob*100)/sumaAlumnos;
    porcDesap=(alumnosDesap*100)/sumaAlumnos;
    porcAus=(alumnosAus*100)/sumaAlumnos;
    printf("%f de los alumnos aprobo\n%f de los alumnos desaprobo\n%f de los alumnos estuvo ausente",porcAprob,porcDesap,porcAus);
    getch();
}