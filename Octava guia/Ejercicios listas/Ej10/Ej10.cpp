#include<iostream>
#include<conio.h>
using namespace std;
/*Dada una lista simple de alumnos (n° de documento y nombre) ordenada por documento. De
cada alumno depende una sublista de exámenes rendidos (fecha, código y nota). Hacer una
función que dada la estructura informe número de documento, nombre y promedio de cada
alumno.*/
struct Examen
{
    unsigned fecha;
    unsigned codMat;
    unsigned nota;
};
struct NodoSub
{
    Examen info;
    NodoSub*sig;
};
struct Alumno
{
    unsigned dni;
    string nombre;
    NodoSub*listaExam;
};
struct Nodo
{
    Alumno info;
    Nodo*sig;
};

void insertar(NodoSub*&,Examen);
Nodo* buscarInsertar(Nodo*&,Alumno);
void generar(Nodo*&);
float promedio(NodoSub*lista);
void ejercicio10(Nodo*listaAl);
void codMat(Nodo*lista);
int main()
{
    Nodo*listaAlumnos=NULL;
    generar(listaAlumnos);
    ejercicio10(listaAlumnos);
    getch();
}

void generar(Nodo*&lista)
{
    Alumno al;
    Examen ex;
    Nodo*p;
    unsigned dniAl,codMateria,fechaEx,notaOb;
    string nomAl;
    cout<<"DNI alumno: ";
    cin>>dniAl;
    while(dniAl!=0)  //ingresa datos del examen
    {
        cout<<"Nombre alumno: ";
        cin>>nomAl;
        cout<<"Fecha examen: ";
        cin>>fechaEx;
        cout<<"Materia rendida: ";
        cin>>codMateria;
        cout<<"Nota: ";
        cin>>notaOb;

        al.dni=dniAl;
        al.nombre=nomAl;
        al.listaExam=NULL;
        p=buscarInsertar(lista,al);
        ex.codMat=codMateria;
        ex.fecha=fechaEx;
        ex.nota=notaOb;
        insertar(p->info.listaExam,ex);

        cout<<"DNI alumno: ";
        cin>>dniAl;
    }
}

void insertar(NodoSub*&lista,Examen ex)  //ordenado por fecha
{
    NodoSub*n,*p,*ant;
    n=new NodoSub;
    n->info=ex;
    p=lista;
    while(p!=NULL && p->info.fecha < ex.fecha)
    {
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=lista)
        ant->sig=n;
    else
        lista=n;
}

Nodo* buscarInsertar(Nodo*&lista,Alumno al)
{
    Nodo*ant,*p=lista;
   while(p!=NULL && p->info.dni<al.dni)
   {
       ant=p;
       p=p->sig;
   }
   if(p!=NULL && al.dni==p->info.dni)
        return p;
   else
   {
       Nodo*n=new Nodo;
       n->info=al;
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else
            lista=n;
        return n;
   }
}

void ejercicio10(Nodo*listaAl)
{
    Nodo*p=listaAl;
    NodoSub*q=p->info.listaExam;
    while(p!=NULL)
    {
        cout<<"NOMBRE: "<<p->info.nombre<<" DNI: "<<p->info.dni<<" CODIGO MATERIA: ";
        codMat(listaAl);
        cout<<" PROMEDIO: "<<promedio(q);
        p=p->sig;
        if(p!=NULL) q=p->info.listaExam;
    }
}

void codMat(Nodo*lista)
{
    Nodo*p=lista;
    while(p->info.listaExam!=NULL)
    {
        cout<<p->info.listaExam->info.codMat;
        p->info.listaExam=p->info.listaExam->sig;
    }
}

float promedio(NodoSub*lista)
{
    NodoSub*p=lista;
    int cont=0,acum=0;
    while(p!=NULL)
    {
        acum+=p->info.nota;
        cont++;
        p=p->sig;
    }
    acum=acum/cont;
    return acum;
}