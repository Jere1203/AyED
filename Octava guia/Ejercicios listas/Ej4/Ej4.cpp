/*Dada la lista del ejercicio 1, hacer una función que devuelva dos listas una con los productos
cuyo stock sea inferior a 50 unidades y otra con los restantes.*/
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
void listar(Nodo*lista);
void insertar(Nodo*&lista,producto prod);
void CrearListas(Nodo*lista,Nodo*&lMas50,Nodo*&lMenos50,producto prod);
int main()
{
    Nodo *lprod=NULL,*lmas50=NULL,*lmenos50=NULL;
    producto prod;
    unsigned k;
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
        insertar(lprod,prod);
        cout<<"CODIGO: "<<endl;
        cin>>prod.cod;
    }
    CrearListas(lprod,lmas50,lmenos50,prod);
    cout<<"LISTA CON STOCK MAYOR O IGUAL A 50"<<endl;
    listar(lmas50);
    cout<<"LISTA CON STOCK MENOR A 50 UNIDADES"<<endl;
    listar(lmenos50);
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

void CrearListas(Nodo*lista,Nodo*&lMas50,Nodo*&lMenos50,producto prod)
{   
    Nodo*p=lista;
    while(p!=NULL)
    {
        if(p->info.stock>=50)   insertar(lMas50,p->info);
        if(p->info.stock<50)    insertar(lMenos50,p->info);
        p=p->sig;
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
