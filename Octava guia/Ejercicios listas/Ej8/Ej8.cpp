#include<iostream>
#include<conio.h>
using namespace std;
/*Dada una lista doblemente encadenada de números eliminar los últimos n nodos.*/
struct Nodo
{
    int dato;
    Nodo*sig;
    Nodo*ant;
};
void insertar(Nodo*&lis1,Nodo*&lis2, int nro);
void mostrarAsc(Nodo*l);
void elimNodo(Nodo*&lista2,int n,int tamLista);
int main()
{
    Nodo *l1=NULL,*l2=NULL;
    int num,cantNod,tamLista=0;
    cout<<"INGRESE DATO"<<endl;
    cin>>num;
    while(num!=0)
    {
        insertar(l1,l2,num);
        tamLista++;
        cout<<"INGRESE DATO"<<endl;
        cin>>num;
    }
    cout<<"LISTA:"<<endl;
    mostrarAsc(l1);
    cout<<"SELECCIONE CANTIDAD DE NODOS A ELIMINAR"<<endl;
    cin>>cantNod;
    elimNodo(l2,cantNod,tamLista);
    cout<<"LISTA ACTUALIZADA"<<endl;
    mostrarAsc(l1);
    getch();
}

void insertar(Nodo*&lis1,Nodo*&lis2, int nro)
{
    Nodo*p,*r;
    p=new Nodo;
    p->dato=nro;
    if(lis1==NULL && lis2==NULL) //p no va a tener ni sucesor ni antecesor (agrega a lista vac�a)
    {
        p->sig=p->ant=NULL;
        lis1=lis2=p;
    }
    else
    {
        r=lis1;
        while(r!=NULL&&r->dato<nro)
            r=r->sig;

       if(r==lis1) //p va a tener sucesor y no antecesor
        {
            p->ant=NULL;
            p->sig=r;
            r->ant=p;
            lis1=p;
        }
        else
        {
            if(r==NULL) //p va a tener antecesor y no sucesor
            {
                p->ant=lis2;
                p->sig=r;
                lis2->sig=p;
                lis2=p;
            }
            else
            {   //p va a tener sucesor y antecesor
                p->ant=r->ant;
                p->sig=r;
                /*
                Nodo*anterior=r->ant;
                anterior->sig=p;
                */
                r->ant->sig=p;
                r->ant=p;
            }
        }
    }
}
void mostrarAsc(Nodo*l)
{
    Nodo*p=l;
    while(p!=NULL)
    {
        cout<<p->dato<<endl;
        p=p->sig;
    }
}

void elimNodo(Nodo*&lista2,int cantNodos,int tamLista)
{
    Nodo *p;
    int cont=0;
    if(tamLista>cantNodos)
    {
        while(p!=NULL&&cont<cantNodos)
        {
            p=lista2;
            lista2=lista2->ant;
            delete p;
            cont++;
        }
        if(lista2!=NULL) lista2->sig=NULL;
    } 
}