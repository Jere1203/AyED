/*Se tiene un vector con las notas de los exámenes rendidos por los alumnos (nombre y nota)
ordenado por nombre con un elemento por cada examen rendido (un alumno puede haber rendido 1,
2, ó más exámenes). Se pide generar un vector con un elemento por alumno con el promedio de las
notas de sus exámenes, ordenado por nombre.*/
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct alumno
{
    char nombre[10];
    int nota[10] {0,0,0,0,0,0,0,0,0,0};
    float prom;
};
void ingresoDatos(alumno[],int);
alumno ingresoNotas();
void sort(alumno[],int);
void mostrar(alumno[],int);
int main()
{
    int max;
    cout<<"Ingrese cantidad de alumnos"<<endl;
    cin>>max;
    alumno alum[max];
    ingresoDatos(alum,max);
    sort(alum,max);
    mostrar(alum,max);
    getch();
}

void ingresoDatos(alumno alum[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        alum[i]=ingresoNotas();
    }
}

alumno ingresoNotas()
{
    alumno alum;
    int i=0;
    cout<<"Ingrese nombre del alumno"<<endl;
    cin>>alum.nombre;
    cout<<"Ingrese notas del alumno"<<endl;
    alum.prom=0;
    while(alum.nota[i-1]!=-1)
    {
        cin>>alum.nota[i];
        if(alum.nota[i]!=-1)alum.prom+=alum.nota[i];
        i++;
    }
    alum.prom/=i-1;
    i=0;
    return alum;
}

void sort(alumno al[],int tam)
{
    alumno aux;
    for(int i=1;i<tam;i++)
    {
        for(int j=0;j<tam-i;j++)
        {
            if(al[j].nombre<al[j+1].nombre)
            {
                aux=al[j];
                al[j]=al[j+1];
                al[j+1]=aux;
            }
        }
    }
}

void mostrar(alumno al[],int max)
{   
    int i;
    for(i=0;i<max;i++)
    {
        cout<<"Nombre: "<<al[i].nombre<<endl;
        cout<<"Promedio: "<<al[i].prom<<endl;
        int j=0;
        while(al[i].nota[j]!=-1)
        {
            cout<<"Nota: "<<al[i].nota[j]<<endl;
            j++;
        }
    }
}