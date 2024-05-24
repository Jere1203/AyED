/*Ingresar la cantidad de alumnos de un curso. Ingresar por cada alumno el nombre y dos notas. Por
cada alumno informar su nombre y el promedio de sus notas.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int nota1,nota2,cant,i;
    float prom;
    char alumno[10];
    printf("Ingrese cantidad de alumnos que hay en el curso\n");
    scanf("%d",&cant);
    for(i=0;i<cant;i++)
    {
        printf("Ingrese nombre del alumno y sus notas\n");
        scanf("%s %d %d",&alumno,&nota1,&nota2);
        prom=(float)(nota1+nota2)/2;
        printf("El alumno %s tiene nota %f de promedio\n",alumno,prom);
    }
    getch();
}