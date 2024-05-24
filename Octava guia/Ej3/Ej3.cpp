/*Desarrollar una función que dada una letra devuelva true si es capicúa y falso en caso
contrario. (usar una pila)*/
#include<iostream>
#include<conio.h>
using namespace std;

struct letra
{
    char letra;
};

struct NodoPila
{
    letra caracteres;
    NodoPila*sig;
};
void carga(NodoPila*&pila,letra word);
void desapilar(NodoPila*&pila,letra &elemExtra);
void apilar(NodoPila*&pilaS,letra elemento);
int main()
{
    NodoPila *pilaPalabra=NULL,*pilaSecun=NULL,*pilaTer=NULL;
    letra word,letra1,letra2;
    bool iguales=false;
    carga(pilaPalabra,word);
    while(pilaPalabra!=NULL)
    {
        desapilar(pilaPalabra,word);
        apilar(pilaSecun,word);
        apilar(pilaTer,word);
    }
    while(pilaTer!=NULL)
    {
        desapilar(pilaTer,word);
        apilar(pilaPalabra,word);
    }
    while(pilaPalabra!=NULL && pilaSecun!=NULL)
    {
        desapilar(pilaPalabra,letra1);
        desapilar(pilaSecun,letra2);
        if(letra1.letra==letra2.letra) iguales=!iguales;
    }
    if(iguales==true) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    getch();
}
void carga(NodoPila*&pila,letra word)
{
    cout<<"Ingrese letra: "<<endl;
    cin>>word.letra;
    while(word.letra!='-')
    {
        apilar(pila,word);
        cin>>word.letra;
    }
}
void desapilar(NodoPila*&pila,letra &elemExtra)
{
    NodoPila*p=pila;
    elemExtra=p->caracteres;
    pila=p->sig;
    delete p;
}

void apilar(NodoPila*&pilaS,letra elemento)
{
    NodoPila*p;
    p=new NodoPila;
    p->caracteres=elemento;
    p->sig=pilaS;
    pilaS=p;
}