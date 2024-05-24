/*Desarrollar una función que dada una pila y un valor, inserte ese valor como tercer elemento de
la pila.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct item
{
    int extra;
};
struct NodoPila
{
    item elem;
    NodoPila*sig;
};
void apilar(NodoPila*&pilaS,item elemento);
void carga(NodoPila*&pilaElem,item elemExtra);
void desapilar(NodoPila*&pilaP,item &elemExtra);
int main()
{
    NodoPila*pilaP=NULL;
    NodoPila*pilaS=NULL;
    item elemExtra;
    int i=0;
    carga(pilaP,elemExtra);
    for(int i=0;i<5;i++)
    {
        desapilar(pilaP,elemExtra);
        apilar(pilaS,elemExtra);
    }
    
    for(int i=0;i<5;i++)
    {
        if(i!=2)
        {
            desapilar(pilaS,elemExtra);
            apilar(pilaP,elemExtra);
        }
        else
        {
            desapilar(pilaS,elemExtra);
            cout<<"Ingrese nuevo elemento"<<endl;
            cin>>elemExtra.extra;
            apilar(pilaP,elemExtra);
        }
    }
    while(pilaP!=NULL)
    {
        desapilar(pilaP,elemExtra);
        cout<<elemExtra.extra<<endl;
    }
    getch();
}

void carga(NodoPila*&pilaElem,item elemExtra)
{
    cout<<"Ingrese dato: "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>elemExtra.extra;
        NodoPila*p;
        p=new NodoPila;
        p->elem=elemExtra;
        p->sig=pilaElem;
        pilaElem=p;
    }
}

void desapilar(NodoPila*&pila,item &elemExtra)
{
    NodoPila*p=pila;
    elemExtra=p->elem;
    pila=p->sig;
    delete p;
}

void apilar(NodoPila*&pilaS,item elemento)
{
    NodoPila*p;
    p=new NodoPila;
    p->elem=elemento;
    p->sig=pilaS;
    pilaS=p;
}

/*void cambioPila(NodoPila*&pilaP,NodoPila*&pilaS,int &i)
{
    i=0;
    while(pilaP!=NULL)
    {
        NodoPila*princ=pilaP;
        NodoPila*sec=pilaS;
        sec=new NodoPila;
        item aux;
        aux=princ->elem;
        pilaP=princ->sig;
        sec->elem=aux;
        sec->sig=pilaS;
        delete princ;
        pilaS=sec;
        i++;
    }
}
void cambioElemento(NodoPila*&pilaP,NodoPila*&pilaS,int &i,item ElemExtra)
{
    i=0;
    while(pilaS!=NULL)
    {
        NodoPila*princ=pilaP;
        NodoPila*sec=pilaS;
        princ=new NodoPila;
        item aux;
        if(i==2)
        {
            cout<<"Ingrese elemento para cambiar"<<endl;
            cin>>ElemExtra.extra;
            princ->elem=ElemExtra;
            princ->sig=pilaP;
        }
        else
        {            
            aux=sec->elem;
            pilaS=sec->sig;
            princ->elem=aux;
            princ->sig=pilaP;
            delete sec;
            pilaP=princ;
        }
        i++;
    }
}*/