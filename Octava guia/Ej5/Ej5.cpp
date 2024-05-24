/*Desarrollar una función que dada una cola elimine 4 nodos de la misma, y devuelva un valor
true si ello fue posible, de lo contrario un valor falso.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct NodoCola
{
    int num;
    NodoCola*sig;
};

void encolar(NodoCola*&pri,NodoCola*&ult,int nro);
void desencolar(NodoCola*&pri,NodoCola*&ult,int&nro);
bool elim(NodoCola*&Prim,NodoCola*&Ult,int&nro);
int main()
{
    NodoCola*PrimCola,*UltCola;
    PrimCola=UltCola=NULL;
    int dato;
    cout<<"INGRESE DATOS DISTINTOS A -1"<<endl;
    cin>>dato;
    while(dato!=-1)
    {
        encolar(PrimCola,UltCola,dato);
        cin>>dato;
    }
    if(elim(PrimCola,UltCola,dato)==1)cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    getch();
}

void encolar(NodoCola*&pri,NodoCola*&ult,int nro)
{
    NodoCola*p=new NodoCola;
    p->num=nro;
    p->sig=NULL;
    if(ult!=NULL) ult->sig=p;
    else pri=p;
    ult=p;
}

void desencolar(NodoCola*&pri,NodoCola*&ult,int&nro)
{
    NodoCola*p=pri;
    nro=p->num; //nro=pri->info;
    pri=p->sig;
    delete p;
    if(pri==NULL) ult=NULL;
}

bool elim(NodoCola*&Prim,NodoCola*&Ult,int&nro)
{
    int i=0;
    while(Prim!=NULL,Ult!=NULL)
    {
        desencolar(Prim,Ult,nro);
        i++;
    }
    if(i>=4) return true;
    else return false;
}