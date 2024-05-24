/*Dada la lista definida en el ejercicio 1 conteniendo productos repetidos, hacer una función que
deje en la lista un solo nodo por producto con el stock sumado.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct producto
{
    int cod,importe,stock;
    char desc[10];
};
struct Nodo
{
    producto info;
    Nodo*sig;
};
void ccontrol(Nodo*lista1,Nodo*&lAp);
void insertar(Nodo*&lista,producto prod);
void listar(Nodo*lista);
int main()
{
    Nodo *lprod1,*lprod2;
    lprod1=lprod2=NULL;
    producto prod;
    cout<<"INGRESO LISTA:"<<endl;
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
        insertar(lprod1,prod);
        cout<<"CODIGO: "<<endl;
        cin>>prod.cod;
    }
    ccontrol(lprod1,lprod2);
    listar(lprod2);
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

void ccontrol(Nodo*lista1,Nodo*&lAp)
{
    Nodo*p=lista1;
    producto aux;
    int acum,cont,cod;
    while(p!=NULL)
    {
        acum=0;
        cont=0;
        cod=p->info.cod;
        do
        {
            acum+=p->info.stock;
            cont++;
            p->info.stock=acum;
            aux=p->info;
            p=p->sig;
        }while(p!=NULL&&p->info.cod==cod);
        insertar(lAp,aux);
    }
}

void listar(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<"PRODUCTO: "<<p->info.cod<<" "<<p->info.desc<<" $"<<p->info.importe<<" "<<p->info.stock<<" UNIDADES"<<endl;
        p=p->sig;
    }
}