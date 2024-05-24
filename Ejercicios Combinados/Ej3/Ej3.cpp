/*Idem 2) 
a) Imprima un listado ordenado por código de vendedor, con código de vendedor
y el detalle de cada venta, ordenadas de mayor a menor por importe.
b) Genere el archivo “VentasVendedor.dat” ordenado por código de vendedor,
con código de vendedor y el importe total de ventas.

En el comercio hay 10 vendedores cuyo código de vendedor es un número
del 1 al 10.*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct ArchivoVentas
{
    int factura, codVend;
    float importe;
};

struct Nodo
{
    ArchivoVentas info;
    Nodo*sig;
};
struct VentasVendedor
{
    int codigo;
    float total;
};



void insertar(Nodo*&lista,ArchivoVentas &vent);
void listar(Nodo *lven[]);
float cc1(Nodo*lista);
void puntob(Nodo *&lvent,FILE *&archVentasVend);
void inicializarListas(Nodo*lVent[]);
void cargarListas(Nodo *lVent[],FILE *&archVent);
void listarVendedores(Nodo *&lven);
int main()
{
    FILE *archVent;
    FILE *VentVend;
    VentasVendedor ventvend;
    ArchivoVentas vent;
    Nodo *lVentas[10];
    Nodo *p;
    inicializarListas(lVentas);
    archVent=fopen("Ventas.dat","rb");
    cargarListas(lVentas,archVent);
    listar(lVentas);
    VentVend=fopen("VentasVendedor.dat","wb");
    for(int i=0;i<10;i++)
    {
        puntob(lVentas[i],VentVend);
    }
    fclose(VentVend);
    getch();
}

void inicializarListas(Nodo*lVent[])
{
    for(int i=0;i<10;i++)
    {
        lVent[i]=NULL;
    }
}

void cargarListas(Nodo *lVent[],FILE *&archVent)
{
    ArchivoVentas vent;
    fread(&vent,sizeof(ArchivoVentas),1,archVent);
    while(!feof(archVent))
    {
        insertar(lVent[vent.codVend-1],vent);
        fread(&vent,sizeof(ArchivoVentas),1,archVent);
    }
}

void insertar(Nodo*&lista,ArchivoVentas &vent)  //ordenado por importe
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=vent;
    p=lista;
    while(p!=NULL && p->info.importe > vent.importe)
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

void listar(Nodo *lven[])
{
    cout<<"========================PUNTO A========================"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"VENDEDOR: "<<i+1<<endl;
        listarVendedores(lven[i]);
    }
}

void listarVendedores(Nodo *&lven)
{
    Nodo *p=lven;
    while(p!=NULL)
    {
        cout/*<<" CODIGO: "<<lven->info.codVend*/<<"FACTURA: "<<p->info.factura<<" IMPORTE: "<<p->info.importe<<endl;
        p=p->sig;
    }
}

//punto b
float cc1(Nodo*lista)
{
    Nodo*p=lista;
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
    if(p!=NULL)
    {
        ventvend.total=cc1(p);
        ventvend.codigo=p->info.codVend;
        fwrite(&ventvend,sizeof(VentasVendedor),1,archVentasVend);
    }
}