/*Una compañía que ofrece préstamos a sus clientes a pagar en 12 meses, desea
obtener un listado con los códigos de clientes y los números de las cuotas
adeudadas de aquellos clientes que adeuden cuotas, ordenado por código de
cliente. Para ello cuenta con un archivo de cobranzas, sin ningún orden, con el 
siguiente diseño:
Código de cliente (int)
Número de cuota (1 a 12)*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct cobranzas
{
    int codCliente,cuota;
};
struct Nodo
{
    cobranzas info;
    Nodo*sig;
};
void insertar(Nodo*&lista,cobranzas cob);
void listar(Nodo*lista);
int main()
{
    FILE *archCob;
    Nodo *lCobr=NULL;
    cobranzas cob;
    archCob=fopen("Cobranzas.dat","rb");
    fread(&cob,sizeof(cobranzas),1,archCob);
    while(!feof(archCob))
    {
        insertar(lCobr,cob);
        fread(&cob,sizeof(cobranzas),1,archCob);
    }
    listar(lCobr);
    getch();
}

void insertar(Nodo*&lista,cobranzas cob)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=cob;
    p=lista;
    while(p!=NULL && p->info.codCliente<cob.codCliente)
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

void listar(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        cout<<"CLIENTE: "<<p->info.codCliente<<" CUOTAS: "<<p->info.cuota<<endl;
        p=p->sig;
    }
}