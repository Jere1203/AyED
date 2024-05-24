/*Desarrollar una función que dada una pila y dos int x e y, reemplace cada valor igual a y
que se encuentre en la pila por el valor x, retornando la pila modificada.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct NodoValores
{
    int val;
    NodoValores*sig;
};
void carga(NodoValores*&pila,int valor);
void desapilar(NodoValores*&pila,int &valor);
void apilar(NodoValores*&pila,int valor);
int main()
{
    NodoValores*Pila1=NULL,*Pila2=NULL;
    int valor,x,y;
    cout<<"CARGA DE PILA"<<endl;
    carga(Pila1,valor);
    cout<<"Ingrese valores x e y"<<endl;
    cin>>x>>y;
    while(Pila1!=NULL)
    {
        desapilar(Pila1,valor);
        if(valor==y) apilar(Pila2,x);
        else apilar(Pila2,valor);
    }
    cout<<"PILA MODIFICADA"<<endl;
    while(Pila2!=NULL)
    {
        desapilar(Pila2,valor);
        apilar(Pila1,valor);
        cout<<valor<<endl;
    }
    getch();
}
void carga(NodoValores*&pila,int valor)
{
    cout<<"Ingrese valor: "<<endl;
    cin>>valor;
    while(valor!=-1)
    {
        apilar(pila,valor);
        cin>>valor;
    }
}

void apilar(NodoValores*&pila,int valor)
{
    NodoValores*p;
    p=new NodoValores;
    p->val=valor;
    p->sig=pila;
    pila=p;
}
void desapilar(NodoValores*&pila,int &valor)
{
    NodoValores*p=pila;
    valor=p->val;
    pila=p->sig;
    delete p;
}