/*Dadas dos listas definidas como en el ejercicio 1, conteniendo la información de productos
diferentes manufacturados en dos fábricas, se pide hacer una función que devuelva otra lista
ordenada por código de producto conteniendo la totalidad de la información.*/
#include<iostream>
#include<conio.h>
using namespace std;

struct producto
{
    int cod,importe,stock,pos;
    char desc[10];
};
struct Nodo
{
    producto info;
    Nodo*sig;
};
void insertar(Nodo*&lista,producto prod);
void apareo(Nodo*lista1, Nodo*lista2,Nodo*&listaAp);
void listar(Nodo*lista);
int main()
{
    Nodo *lprod1,*lprod2,*lprod3;
    lprod1=lprod2=lprod3=NULL;
    producto prod;
    cout<<"INGRESO LISTA 1:"<<endl;
    cout<<"CODIGO: "<<endl;
    cin>>prod.cod;
    while(prod.cod!=0)
    {
        cout<<"DESC: "<<endl;
        cin>>prod.desc;
        cout<<"IMPORTE: "<<endl;
        cin>>prod.importe;
        cout<<"STOCK: "<<endl;
        cin>>prod.stock;
        cout<<"POSICION: "<<endl;
        cin>>prod.pos;
        insertar(lprod1,prod);
        cout<<"CODIGO: "<<endl;
        cin>>prod.cod;
    }
    cout<<"INGRESO LISTA 2:"<<endl;
    cout<<"CODIGO: "<<endl;
    cin>>prod.cod;
    while(prod.cod!=0)
    {
        cout<<"DESC: "<<endl;
        cin>>prod.desc;
        cout<<"IMPORTE: "<<endl;
        cin>>prod.importe;
        cout<<"STOCK: "<<endl;
        cin>>prod.stock;
        cout<<"POSICION: "<<endl;
        cin>>prod.pos;
        insertar(lprod2,prod);
        cout<<"CODIGO: "<<endl;
        cin>>prod.cod;
    }
    apareo(lprod1,lprod2,lprod3);
    cout<<"LISTA 1:"<<endl;
    listar(lprod1);
    cout<<"LISTA 2:"<<endl;
    listar(lprod2);
    cout<<"LISTA APAREADA:"<<endl;
    listar(lprod3);
    getch();
}

void insertar(Nodo*&lista,producto prod)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=prod;
    p=lista;
    while(p!=NULL && p->info.cod<prod.cod)
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

void apareo(Nodo*lista1, Nodo*lista2,Nodo*&listaAp)
{
    Nodo*p1,*p2;
    p1=lista1;
    p2=lista2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->info.cod<p2->info.cod)
        {
            insertar(listaAp,p1->info);
            p1=p1->sig;
        }
        else
        {
            if(p1->info.cod==p2->info.cod)
            {
                insertar(listaAp,p1->info);
                insertar(listaAp,p2->info);
                p1=p1->sig;
                p2=p2->sig;
            }
        }
    }
    while(p1!=NULL)
    {
        insertar(listaAp,p1->info);
        p1=p1->sig;
    }
    while(p2!=NULL)
    {
        insertar(listaAp,p2->info);
        p2=p2->sig;
    }
}

void listar(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<p->info.pos<<"_"<<p->info.cod<<" "<<p->info.desc<<" $"<<p->info.importe<<" "<<p->info.stock<<" UNIDADES"<<endl;
        p=p->sig;
    }
}