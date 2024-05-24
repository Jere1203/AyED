/*Dado un archivo binario de productos que contiene 100 registros, y cada registro corresponde a un producto que está
codificado del 1 a 100, ordenado por código de producto con el siguiente diseño:
código de producto (1..100) stock
y otro archivo binario de pedidos, con el siguiente diseño:
número de pedido número de cliente
código de producto (1..100) cantidad pedida
Se pide desarrollar un algoritmo que:
a) Realice un listado con los pedidos que fueron satisfechos en su totalidad según el siguiente listado
Pedidos Satisfechos
Número de pedido Número de Cliente Código de Producto Cantidad pedida
9999 999999 999 9999
9999 999999 999 9999
b) actualizar el campo stock del archivo de producto, cada vez que acepte un pedido.
c) grabar un archivo binario con el mismo diseño que el archivo de pedidos, con aquellos pedidos que no
pueden ser satisfechos en su totalidad*/
#include<iostream>
#include<stdio.h>
#define MAX 2
using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

void ingreso(Producto[]);
void sort(Producto prod[]);
void mostrar(Producto pr[]);
Producto ingresoVec();
void guardarArch(Producto[]);

int main()
{
    Producto prod[MAX]={0};
    ingreso(prod);
    sort(prod);
    mostrar(prod);
    guardarArch(prod);
    return 0;
}

void ingreso(Producto prod[])
{
    for(int i=0;i<MAX;i++)
    {
        prod[i]=ingresoVec();
    }
}

Producto ingresoVec()
{
    Producto pr;
    cout<<"Ingrese codigo del producto"<<endl;
    cin>>pr.codigo;
    cout<<"Ingrese stock del producto"<<endl;
    cin>>pr.stock;
    return pr;
}

void sort(Producto prod[])
{
    Producto aux;
    for(int i=1;i<MAX;i++)
    {
        for(int j=0;j<MAX-i;j++)
        {
            if(prod[j].codigo>prod[j+1].codigo)
            {
                aux=prod[j+1];
                prod[j+1]=prod[j];
                prod[j]=aux;
            }
        }
    }
}

void mostrar(Producto pr[])
{
    for(int i=0;i<MAX;i++)
    {
        cout<<"Codigo: "<<pr[i].codigo<<"\tStock: "<<pr[i].stock<<endl;
    }
}

void guardarArch(Producto prod[])
{
    FILE *aProd;
    aProd=fopen("PRODUCTOS.DAT","wb");
    if(aProd!=NULL)
    {
        for(int i=0;i<MAX;i++)
        {
            fwrite(&prod[i],sizeof(Producto),1,aProd);
        }
        fclose(aProd);
    }
    else cout<<"ERROR"<<endl;
}