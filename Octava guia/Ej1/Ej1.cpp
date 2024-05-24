/*Dada una pila sacar los dos elementos del tope y reemplazarlos por uno dado (agregar) */
#include<iostream>
#include<conio.h>
using namespace std;
struct Elemento
{
    int elemento;
};
struct NodoPila
{
    Elemento extra;
    NodoPila*sig;
};
void desapilar(NodoPila*&pilaElem,Elemento &item);
void apilar(NodoPila*&pilaElem,Elemento item);
int main()
{
    NodoPila*pilaElem=NULL;
    Elemento item;
    cout<<"CARGA DE PILA"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"Elemento: "<<endl;
        cin>>item.elemento;
        apilar(pilaElem,item);
    }
    for(int i=0;i<2;i++)
    {
        desapilar(pilaElem,item);
    }
    cout<<"Ingrese elemento para reemplazar: "<<endl;
    cin>>item.elemento;
    apilar(pilaElem,item);
    cout<<"NUEVA PILA: "<<endl;
    while(pilaElem!=NULL)
    {
        desapilar(pilaElem,item);
        cout<<item.elemento;
    }
    getch();
}

void apilar(NodoPila*&pilaElem,Elemento item)
{
    NodoPila*p;
    p=new NodoPila;
    p->extra=item;
    p->sig=pilaElem;
    pilaElem=p;
}

void desapilar(NodoPila*&pilaElem,Elemento &item)
{
    NodoPila*p=pilaElem;
    item=p->extra;
    pilaElem=p->sig;
    delete p;
}
