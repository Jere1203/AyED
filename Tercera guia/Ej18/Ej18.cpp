/*Ingresar por teclado el nombre de un alumno, y a continuación la calificación que obtuvo para
cada materia rendida (hasta ingresar una calificación cero) por cada alumno de los 25 del curso.
Informar por cada alumno nombre y su promedio.*/
#include<stdio.h>
#include<conio.h>
#define MAX 25

int main()
{
    char nombre[10];
    float promedio;
    int nota,i,j,cantMaterias=0,suma=0;
    printf("Ingrese nombre y notas\n");
    for(i=0;i<MAX;i++)
    {
        scanf("%s",&nombre);
        promedio=0;
        suma=0;
        for(cantMaterias=0;1;cantMaterias++)
        {
            scanf("%d",&nota);
            if(nota!=0) suma+=nota;
            else{break;}
        }
        promedio=(float)(suma/(cantMaterias));
        printf("NOMBRE: %s\nPROMEDIO: %f\n",nombre,promedio);
    }
    getch();
}