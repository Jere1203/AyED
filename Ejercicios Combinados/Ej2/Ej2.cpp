/*Dado el archivo VENTAS.DAT, ordenado por número de factura, con la siguiente
estructura de registro:
Número de factura (int)
Código de vendedor (int)
Importe (float)
a) Imprima un listado ordenado por código de vendedor, con código de vendedor
y el detalle de cada venta, ordenadas de mayor a menor por importe.
b) Genere el archivo “VentasVendedor.dat” ordenado por código de vendedor,
con código de vendedor y el importe total de ventas.*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct ArchivoVentas
{
    int factura, codVend;
    float importe;
};

struct NodoSub
{
    ArchivoVentas info;
    NodoSub*sig;
};
struct Vendedor
{
    int codigo;
    NodoSub*lventas;
};
struct Nodo
{
    Vendedor info;
    Nodo*sig;
};
struct VentasVendedor
{
    int codigo;
    float total;
};


Nodo* buscarInsertar(Nodo*&lista,Vendedor vend);
void insertar(NodoSub*&lista,ArchivoVentas vent);
void listar(Nodo *&lven);
float cc1(NodoSub*lista);
void puntob(Nodo *&lvent,FILE *&archVentasVend);

int main()
{
    FILE *archVent;
    FILE *VentVend;
    VentasVendedor ventvend;
    ArchivoVentas vent;
    Vendedor vend;
    Nodo *lVentas=NULL;
    Nodo *p;
    archVent=fopen("Ventas.dat","rb");
    fread(&vent,sizeof(ArchivoVentas),1,archVent);
    while(!feof(archVent))
    {
        //insertar(lVentas,vent);
        vend.codigo=vent.codVend;
        vend.lventas=NULL;
        p=buscarInsertar(lVentas,vend);
        insertar(p->info.lventas,vent);
        fread(&vent,sizeof(ArchivoVentas),1,archVent);
    }
    listar(lVentas);
    VentVend=fopen("VentasVendedor.dat","wb");
    puntob(lVentas,VentVend);
    getch();
}

Nodo* buscarInsertar(Nodo*&lista,Vendedor vend)
{
    Nodo*ant,*p=lista;
   while(p!=NULL && p->info.codigo<vend.codigo)
   {
       ant=p;
       p=p->sig;
   }
   if(p!=NULL && vend.codigo==p->info.codigo)
        return p;
   else
   {
       Nodo*n=new Nodo;
       n->info=vend;
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else
            lista=n;
        return n;
   }
}

void insertar(NodoSub*&lista,ArchivoVentas vent)  //ordenado por importe
{
    NodoSub*n,*p,*ant;
    n=new NodoSub;
    n->info=vent;
    p=lista;
    while(p!=NULL && p->info.importe < vent.importe)
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

void listar(Nodo *&lven)
{
    Nodo *p=lven;
    NodoSub *n=p->info.lventas;
    while(p!=NULL)
    {
        n=p->info.lventas;
        cout<<" CODIGO VENDEDOR: "<<p->info.codigo;
        while(n!=NULL)
        {
            cout<<" FACTURA: "<<n->info.factura<<" IMPORTE: "<<n->info.importe;
            n=n->sig;
        }
        cout<<endl;
        p=p->sig;
    }
}

//punto b
float cc1(NodoSub*lista)
{
    NodoSub*p=lista;
    float acum,cont,Codigo;
    while(p!=NULL)
    {
        acum=0;
        cont=0;
        Codigo=p->info.codVend;
        do
        {
            acum+=p->info.importe;
            cont++;
            p=p->sig;
        }while(p!=NULL&&p->info.codVend==Codigo);
        return acum;
    }

}

void puntob(Nodo *&lvent,FILE *&archVentasVend)
{
    VentasVendedor ventvend;
    Nodo *p=lvent;
    NodoSub *n;
    while(p!=NULL)
    {
        n=p->info.lventas;
        ventvend.codigo=p->info.codigo;
        ventvend.total=cc1(n);
        fwrite(&ventvend,sizeof(VentasVendedor),1,archVentasVend);
        p=p->sig;
    }
    fclose(archVentasVend);
}