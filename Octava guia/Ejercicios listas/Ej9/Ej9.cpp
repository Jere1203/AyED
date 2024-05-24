#include<iostream>
#include<conio.h>
using namespace std;
/*Hacer una función que dada una lista circular devuelva la cantidad de nodos que tiene.*/
struct Nodo
{
    int dato;
    Nodo*sig;
};
void mostrar(Nodo*listaC);
void insertar(Nodo*&listaC, int nro);
int cantNodos(Nodo*&listaC);
int main()
{
    Nodo*lis=NULL;
    int num;
    cout<<"INGRESE DATO"<<endl;
    cin>>num;
    while(num!=0)
    {
        //agregar(lis,num); //lista desordenada
        insertar(lis,num); //ordenada
        cout<<"INGRESE DATO"<<endl;
        cin>>num;
    }
    cout<<"LISTA"<<endl;
    mostrar(lis);
    cout<<"CANTIDAD DE NODOS"<<endl;
    cout<<cantNodos(lis);
    getch();
}

void mostrar(Nodo*listaC)
{
    if(listaC!=NULL)
    {
        Nodo*p=listaC->sig;
        do
        {
            cout<<p->dato<<endl;
            p=p->sig;
        }while(p!=listaC->sig);
    }
}

void insertar(Nodo*&listaC, int nro)
{
    //agrega un nodo a la lista circular ordenada
    Nodo*n=new Nodo;
    n->dato=nro;
    if(listaC==NULL)
    {
        n->sig=n;
        listaC=n;
    }
    else
    {
        Nodo*p=listaC->sig,*ant=listaC;
        if(p->dato<nro)
        {
            do
            {
                ant=p;
                p=p->sig;
            }while(p!=listaC->sig && p->dato<nro);
        }
        n->sig=p;
        ant->sig=n;
        if(n->dato>listaC->dato)
            listaC=n;
    }
}

int cantNodos(Nodo*&listaC)
{
    Nodo*p;
    int cont=0;
    if(listaC!=NULL)
    {
        p=listaC->sig;
        do
        {
            cont++;
            p=p->sig;
        }while(p!=listaC->sig);
    }
    return cont;
}