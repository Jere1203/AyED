/*En una empresa de construcción se quiere almacenar en un archivo los importes y
fechas de los materiales comprados para cada una de las obras que está
construcción. Para ello se ingresa por teclado, por cada compra de materiales
realizada: el código de la obra, la fecha y el importe de la compra. Los datos son
ingresados sin orden. Para cada obra se puede haber comprado materiales varias
veces. Se pide generar un archivo secuencial con código de obra, fecha e importe,
ordenado por código de obra y por fecha, con los datos ingresados por teclado.*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct obra
{
    unsigned codigo, fecha, importe;
};
struct Nodo
{
    obra info;
    Nodo*sig;
};
void ingresoDatos(obra ob, Nodo *&lObra);
void insertar(Nodo*&lista,obra ob);
void insertarPorObra(Nodo*&lista,obra ob);
void listar(Nodo*lista);
int main()
{
    Nodo *lObra=NULL;
    obra ob;
    FILE *ArchObra;
    ArchObra=fopen("Obra.dat","wb");
    ingresoDatos(ob,lObra);
    listar(lObra);
    while(lObra!=NULL)
    {
        fwrite(&lObra->info,sizeof(obra),1,ArchObra);
        lObra=lObra->sig;
    }
    fclose(ArchObra);
    getch();
}

void ingresoDatos(obra ob, Nodo *&lObra)
{
    cout<<"CODIGO DE OBRA: "<<endl;
    cin>>ob.codigo;
    while(ob.codigo!=0)
    {
        cout<<"FECHA: "<<endl;
        cin>>ob.fecha;
        cout<<"IMPORTE: "<<endl;
        cin>>ob.importe;
        insertar(lObra,ob); //inserto en lista ordenado por fecha
        cout<<"CODIGO DE OBRA: "<<endl;
        cin>>ob.codigo;
    }
}

void insertar(Nodo*&lista,obra ob)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=ob;
    p=lista;
    while(p!=NULL && p->info.fecha<ob.fecha)
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

void ordenar3(Nodo*&lista)
{
    //de menor a mayor por nota
    //solo una lista
   Nodo*listaOrd=NULL;
   Nodo*p;
   while(lista!=NULL)
   {
       p=lista;
       lista=lista->sig;
       insertarPorObra(listaOrd,p->info);
       delete p;
   }
   lista=listaOrd;
}

void insertarPorObra(Nodo*&lista,obra ob)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=ob;
    p=lista;
    while(p!=NULL && p->info.codigo<ob.codigo)
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

void listar(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        //cout<<p->info.pos<<p->info.cod<<p->info.desc<<p->info.importe<<p->info.stock<<endl;
        cout<<"CODIGO: "<<p->info.codigo<<endl<<"FECHA: "<<p->info.fecha<<endl<<"IMPORTE: $"<<p->info.importe<<endl;
        p=p->sig;
    }
}