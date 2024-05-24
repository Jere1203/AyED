/*Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota.*/
#include<iostream>
#include<conio.h>
using namespace std;
void ingresoDatos(int[],int[],int&);
void compArray(int[],int[],int&,int);
int mayorNota(int[],int[],int&);
int menorNota(int[],int[],int&);
int main()
{
    int tam;
    cout<<"Ingrese cantidad de alumnos\n";
    cin>>tam;
    int dni[tam];
    int notas[tam];
    ingresoDatos(dni,notas,tam);
}

void ingresoDatos(int dni[],int notas[],int &tam)
{
    cout<<"Ingrese DNI y nota del alumno\n";
    for(unsigned int i=0;i<tam;i++)
    {
        cin>>dni[i];
        cin>>notas[i];
    }  
    cout<<"\nLa mayor nota es "<<mayorNota(dni,notas,tam)<<".\nLa menor nota es "<<menorNota(dni,notas,tam);
    cout<<"\nLos alumnos con esa nota son: ";
    compArray(dni,notas,tam,mayorNota(dni,notas,tam));
    cout<<"\nLos alumnos con esa nota son:";
    compArray(dni,notas,tam,menorNota(dni,notas,tam));
    getch();
}

int mayorNota(int dni[],int notas[],int &tam)
{
    bool prim=true;
    int mayor;
    for(unsigned int i=0;i<tam;i++)
    {
        if(prim==true)
        {
            prim=false;
            mayor=notas[i];
        } 
        for(unsigned int j=0;j<tam;j++)
        {
            if(notas[i]>notas[j]) mayor=notas[i];
        }
    }
    return mayor;
}

int menorNota(int dni[],int notas[],int &tam)
{
    bool prim=true;
    int menor;
    for(unsigned int i=0;i<tam;i++)
    {
        if(prim==true)
        {
            prim=false;
            menor=notas[i];
        } 
        for(unsigned int j=0;j<tam;j++)
        {
            if(notas[i]<notas[j]) menor=notas[i];
        }
    }
    return menor;
}

void compArray(int dni[],int notas[],int &tam,int comp)
{
    int i=0,aux=0;
    for(i=0;i<tam;i++)
    {
        if(notas[i]==comp)
        {
            aux=dni[i];//cout<<" \n"<<dni[i];
            cout<<"\n"<<aux;
        } 
    }
}