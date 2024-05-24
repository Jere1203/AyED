/*Ingresar la cantidad de alumnos de un curso. Ingresar por cada alumno el nombre y una nota. Por
cada alumno informar su nombre y si está aprobado o desaprobado. Informar también el
porcentaje de alumnos aprobados y la cantidad de desaprobados.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int nota,cantAlum,cantAprob=0,cantDesaprob=0,i,porcAprob,porcDesaprob;
    char nombre[10];
    char porcentaje='%';
    printf("Ingrese cantidad de alumnos en el curso\n");
    scanf("%d",&cantAlum);
    printf("Ingresar el nombre y nota del alumno\n");
    for(i=0;i<cantAlum;i++)
    {
        scanf("%s %d",&nombre,&nota);
        if(nota>=6)
        {
            printf("El alumno %s aprobo\n",nombre);
            cantAprob++;
        } 
        else 
        {
            printf("El alumno %s desaprobo\n",nombre);
            cantDesaprob++;
        }
    }
    porcAprob=(cantAprob*100)/cantAlum;
    porcDesaprob=(cantDesaprob*100)/cantAlum;
    printf("De los %d alumnos registrados, un %d%c aprobo, mientras que un %d%c desaprobo",cantAlum,porcAprob,porcentaje,porcDesaprob,porcentaje);
    getch();
}