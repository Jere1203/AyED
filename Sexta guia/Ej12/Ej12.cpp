/*Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct alumnos
{
    int dni;
    int nota;
};
void ingresodatos(alumnos[],int);
void sort(alumnos[],int);
void maxNota(alumnos[],int);
void minNota(alumnos[],int);
alumnos ingresonotas();
int main()
{
    int max;
    cout<<"Ingrese cantidad de alumnos\n";
    cin>>max;
    alumnos alumno[max];
    ingresodatos(alumno,max);
    sort(alumno,max);
    cout<<"\nLa mayor nota es "<<alumno[max-1].nota;
    cout<<"\nLos alumnos con dicha nota son:";
    maxNota(alumno,max);
    cout<<"\n\nLa menor nota es "<<alumno[max-max].nota;
    cout<<"\nLos alumnos con esa misma nota son:";
    minNota(alumno,max);
    getch();
}

alumnos ingresonotas()
{
    alumnos alum;
    cout<<"Ingrese DNI del alumno\n";
    cin>>alum.dni;
    cout<<"Ingrese nota del alumno\n";
    cin>>alum.nota;
    return alum;
}

void ingresodatos(alumnos alumno[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        alumno[i]=ingresonotas();
    }
}

void sort(alumnos alumno[],int tam)
{
    int i,j;
    for(i=1;i<tam;i++)
    {
        for(j=0;j<tam-i;j++)
        {
            if(alumno[j].nota>alumno[j+1].nota)
            {
                int aux=alumno[j+1].nota;
                int aux2=alumno[j+1].dni;
                alumno[j+1].nota=alumno[j].nota;
                alumno[j+1].dni=alumno[j].dni;
                alumno[j].nota=aux;
                alumno[j].dni=aux2;
            }
        }
    }
}

void maxNota(alumnos alum[],int tam)
{
    int mayNota;
    for(int i=0;i<tam;i++)
    {
        if(alum[i].nota == alum[tam-1].nota) cout<<"\n"<<alum[i].dni;
    }
}

void minNota(alumnos alum[],int tam)
{
    int menNota;
    for(int i=0;i<tam;i++)
    {
        if(alum[i].nota == alum[tam-tam].nota) cout<<"\n"<<alum[i].dni;
    }
}