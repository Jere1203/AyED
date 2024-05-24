/*Se tiene un vector de notas (cada elemento tiene nombre del alumnos y nota obtenida)
correspondientes al primer parcial y otro vector del mismo tipo del anterior con las notas
correspondientes al segundo parcial, ambos vectores están ordenados alfabéticamente por nombre.
Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno en la
materia, según lo siguiente:
- Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
- Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
- Primer o segundo parcial con nota menor a 6: RECURSA*/
#include<iostream>
#include<conio.h>
#define MAX 3
using namespace std;
struct alumno
{
    char alumno[10];
    unsigned int nota1;
    unsigned int nota2;
};

void ingresoDatos(alumno[]);
alumno ingresoNotas();

int main()
{
    alumno alum[MAX];
    ingresoDatos(alum);
    for(int i=0;i<MAX;i++)
    {
        if(alum[i].nota1>=8&&alum[i].nota2>=8) cout<<"ALUMNO: "<<alum[i].alumno<<" PROMOCION\n";
        if(alum[i].nota1>=6 && alum[i].nota2>=6 && alum[i].nota1<8 && alum[i].nota2<8) cout<<"ALUMNO: "<<alum[i].alumno<<" RINDE FINAL\n";
        if(alum[i].nota1<6||alum[i].nota2<6) cout<<"ALUMNO: "<<alum[i].alumno<<" RECURSA\n";
    }
    getch();
}

alumno ingresoNotas()
{
    alumno alum;
    cout<<"Ingrese nombre del alumno\n";
    cin>>alum.alumno;
    cout<<"Ingrese nota 1\n";
    cin>>alum.nota1;
    cout<<"Ingrese nota 2\n";
    cin>>alum.nota2;
    return alum;
}

void ingresoDatos(alumno alum[])
{
    for(int i=0;i<MAX;i++)
    {
        alum[i]=ingresoNotas();
    }
}