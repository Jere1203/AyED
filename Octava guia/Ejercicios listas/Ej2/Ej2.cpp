/*Se tiene lista enlazada donde cada nodo contiene nombre y número de documento de las
personas inscriptas en un curso, ordenada por número de documento. Hacer funciones para:
a. agregar un inscripto al curso, considerar que puede estar la lista vacía o ya contener
información.
b. dar de baja una persona que no concurrirá al curso.
c. imprimir la lista completa.
d. Imprimir la lista en orden inverso (ordenada por documento de mayor a menor)*/
#include<iostream>
#include<conio.h>
using namespace std;
struct persona
{
    int dni;
    char nom[10];
};
struct Nodo
{
    persona info;
    Nodo*sig;
};
void insertar(Nodo*&lista,persona prod);
Nodo* buscarSecMejorada(Nodo*lista,unsigned unDni);
void eliminar(Nodo*&lista,int unDni);
void listar(Nodo*lista);
void ordenar4(Nodo*&lista);
void insertarNotaSinMem(Nodo*&lista,Nodo*n);
int main()
{
    persona per;
    Nodo *lper=NULL;
    int dni;
    cout<<"DNI: "<<endl;
    cin>>per.dni;
    while(per.dni!=0)
    {
        cout<<"NOMBRE: "<<endl;
        fflush(stdin);
        cin.getline(per.nom,10);
        insertar(lper,per);
        cout<<"DNI: "<<endl;
        cin>>per.dni;
    }
    cout<<"INGRESE DNI DEL ALUMNO QUE DESEA ELIMINAR DE LA LISTA: "<<endl;
    cin>>dni;
    eliminar(lper,dni);
    listar(lper);
    cout<<endl;
    ordenar4(lper);
    listar(lper);
    getch();
}

void insertar(Nodo*&lista,persona prod)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=prod;
    p=lista;
    while(p!=NULL && p->info.dni<prod.dni)
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

Nodo* buscarSecMejorada(Nodo*lista,unsigned unDni)
{
    //solo para buscar por lo que est� ordenado
    Nodo*p=lista;
    while(p!=NULL && p->info.dni<unDni)
        p=p->sig;
    if(p==NULL || p->info.dni!=unDni)
        return NULL;
    else
        return p;
}

void eliminar(Nodo*&lista,int unDni)
{
    Nodo*ant,*p=lista;
    while(p!=NULL && p->info.dni<unDni)
    {
        ant=p;
        p=p->sig;
    }
    if(p!=NULL && p->info.dni==unDni)
    {
        if(p!=lista)
            ant->sig=p->sig;
        else
            lista=p->sig;

        delete p;
    }
}

void listar(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<p->info.dni<<p->info.nom<<endl;
        p=p->sig;
    }
}

void ordenar4(Nodo*&lista)
{
    //de menor a mayor por nota
    //solo una lista
   Nodo*listaOrd=NULL;
   Nodo*p;
   while(lista!=NULL)
   {
       p=lista;
       lista=lista->sig;
       insertarNotaSinMem(listaOrd,p);

   }
   lista=listaOrd;
}

void insertarNotaSinMem(Nodo*&lista,Nodo*n)
{
    Nodo*p,*ant;
    p=lista;
    while(p!=NULL && p->info.dni>n->info.dni)
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