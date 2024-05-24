/*En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de todos contra
todos. Por cada partido disputado por un equipo se dispone de la siguiente información :
a) Nombre del equipo,
b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado).
Se arma un lote de datos con todos los resultados del torneo, agrupados por nombre del
equipo.
Desarrollar el programa que imprima:
Por cada equipo, su nombre y el puntaje total que obtuvo (suma 3 si gana, y 1 si empata).*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int cantEquip=0,puntos=0,i,j,cantPart=0;
    char res,equipo[10];
    printf("Ingrese cantidad de equipos\n");
    scanf("%d",&cantEquip);
    cantPart=cantEquip-1;
    for(i=0;i<cantEquip;i++)
    {
        printf("Ingrese nombre del equipo\n");
        scanf("%s",&equipo);
        printf("Ingrese P, E o G segun el resultado del partido\n");
        for(j=0;j<cantPart;j++)
        {
            scanf(" %c",&res);
            switch (res)
            {
                case 'g':
                case 'G':
                    puntos+=3;
                    break;
                case 'e':
                case 'E':
                    puntos+=1;
                    break;
            }
        }
        printf("El equipo %s tiene un total de %d puntos\n\n",equipo,puntos);
        puntos=0;
    }
    getch();
}