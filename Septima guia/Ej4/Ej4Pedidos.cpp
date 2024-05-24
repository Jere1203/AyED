/*Realice un listado con los pedidos que fueron satisfechos en su totalidad según el siguiente listado*/
#include<iostream>
#include<stdio.h>
#define MAX 2
using namespace std;
struct pedido
{
    unsigned nroped;
    unsigned codigo;
    unsigned cant;
    unsigned cliente;
};

void ingreso(pedido[]);
void sort(pedido ped[]);
void mostrar(pedido ped[]);
pedido ingresoVec();
void guardarArch(pedido[]);

int main()
{
    pedido ped[MAX]={0};
    ingreso(ped);
    sort(ped);
    mostrar(ped);
    guardarArch(ped);
    return 0;
}

void ingreso(pedido ped[])
{
    for(int i=0;i<MAX;i++)
    {
        ped[i]=ingresoVec();
    }
}

pedido ingresoVec()
{
    pedido ped;
    cout<<"Ingrese numero de pedido"<<endl;
    cin>>ped.nroped;
    cout<<"Ingrese numero de cliente"<<endl;
    cin>>ped.cliente;
    cout<<"Ingrese codigo del producto"<<endl;
    cin>>ped.codigo;
    cout<<"Ingrese cantidad del producto"<<endl;
    cin>>ped.cant;
    return ped;
}

void sort(pedido ped[])
{
    pedido aux;
    for(int i=1;i<MAX;i++)
    {
        for(int j=0;j<MAX-i;j++)
        {
            if(ped[j].codigo>ped[j+1].codigo)
            {
                aux=ped[j+1];
                ped[j+1]=ped[j];
                ped[j]=aux;
            }
        }
    }
}

void mostrar(pedido ped[])
{
    for(int i=0;i<MAX;i++)
    {
        cout<<"Codigo: "<<ped[i].codigo<<"\tCantidad: "<<ped[i].cant<<endl;
    }
}

void guardarArch(pedido ped[])
{
    FILE *aPed;
    aPed=fopen("PEDIDOS.DAT","wb");
    if(aPed!=NULL)
    {
        for(int i=0;i<MAX;i++)
        {
            fwrite(&ped[i],sizeof(pedido),1,aPed);
        }
        fclose(aPed);
    }
    else cout<<"ERROR"<<endl;
}