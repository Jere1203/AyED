/*Desarrollar una función que dada una cola de personas (de cada persona se tiene dni y nombre)
y un dni, si esta persona está en la cola, la mueva al último lugar de la misma.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct alumno
{
    int dni;
};

struct NodoCola
{
    alumno al;
    NodoCola*sig;
};
void encolar(NodoCola*&pri,NodoCola*&ult,int nro);
void desencolar(NodoCola*&pri,NodoCola*&ult,int&nro);
void secuencial(NodoCola*&Prim,NodoCola*&Ult,int &bus);
int main()
{
    NodoCola*Prim,*Ult;
    Prim=Ult=NULL;
    alumno al;
    int dni;
    cout<<"INGRESE DNI DEL ALUMNO (DNI 0 PARA FINALIZAR)"<<endl;
    cin>>dni;
    while(dni!=0)
    {
        encolar(Prim,Ult,dni);
        cin>>dni;
    }
    cout<<"Ingrese dni a buscar"<<endl;
    cin>>dni;
    secuencial(Prim,Ult,dni);
    while(Prim!=NULL)
    {
        desencolar(Prim,Ult,dni);
        cout<<dni<<endl;
    }
    getch();
}

void encolar(NodoCola*&pri,NodoCola*&ult,int dni)
{
    NodoCola*p=new NodoCola;
    p->al.dni=dni;
    p->sig=NULL;
    if(ult!=NULL) ult->sig=p;
    else pri=p;
    ult=p;
}

void desencolar(NodoCola*&pri,NodoCola*&ult,int&dni)
{
    NodoCola*p=pri;
    dni=p->al.dni; //nro=pri->info;
    pri=p->sig;
    delete p;
    if(pri==NULL) ult=NULL;
}

void secuencial(NodoCola*&Prim,NodoCola*&Ult,int &bus)
{
    unsigned i=0;
    int aux=0,auxcont=0;
    while(Prim!=NULL && Ult!=NULL && aux!=bus)
    {
        desencolar(Prim,Ult,aux);
        i++;
    }
    if(Prim==NULL||Ult==NULL) cout<<"NO SE ENCONTRO"<<endl;
    else
    {
        auxcont=i;
        for(i=0;i<=auxcont;i++)
        {
            if(i==(auxcont-1)) encolar(Prim,Ult,bus);
        } 
    }
}