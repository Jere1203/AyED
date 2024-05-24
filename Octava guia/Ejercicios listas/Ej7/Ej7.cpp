/*Dada una lista doblemente encadenada de números enganchada solo por el puntero al siguiente
y con todos los punteros al anterior en NULL, se pide hacer una rutina que la recorra y
complete los punteros convenientemente incluyendo el puntero externo para recorrerla de atrás
hacia adelante.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct Nodo
{
    int dato;
    Nodo*sig;
    Nodo*ant;
};
void insertar(Nodo*&lista,int dato);
void convertir(Nodo*&lista1,Nodo*&lista2);
void insertar(Nodo*&lista,int dato);
void listarAsc(Nodo*lista);
void listarDesc(Nodo*lista);
int main()
{
    Nodo *lista1,*lista2;
    lista1=lista2=NULL;
    int data;
    cout<<"INGRESE DATO"<<endl;
    cin>>data;
    while(data!=0)
    {
        insertar(lista1,data);
        cout<<"INGRESE DATO"<<endl;
        cin>>data;
    }
    convertir(lista1,lista2);
    cout<<"LISTA ASCENDENTE"<<endl;
    listarAsc(lista1);
    cout<<"LISTA DESCENDENTE"<<endl;
    listarDesc(lista2);
    getch();
}

void insertar(Nodo*&lista,int dato)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->dato=dato;
    p=lista;
    while(p!=NULL && p->dato<dato)
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

void convertir(Nodo*&lista1,Nodo*&lista2)
{
    Nodo*a,*p;
    a=p=lista1;
    while(p->sig!=NULL)
    {   
        p=p->sig;
        p->ant=a;
        a=p;
    }
    lista2=a;
}

void listarAsc(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<p->dato<<endl;
        p=p->sig;
    }
}
void listarDesc(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<p->dato<<endl;
        p=p->ant;
    }
}