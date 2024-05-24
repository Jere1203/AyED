/*Realice un listado con los pedidos que fueron satisfechos en su totalidad según el siguiente listado:
b) actualizar el campo stock del archivo de producto, cada vez que acepte un pedido.
c) grabar un archivo binario con el mismo diseño que el archivo de pedidos, con aquellos pedidos que no
pueden ser satisfechos en su totalidad.*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct pedido
{
    unsigned nroped;
    unsigned codigo;
    unsigned cant;
    unsigned cliente;
};
struct producto
{
    unsigned codigo;
    unsigned stock;
};
void verifCompra(FILE *aPed,FILE *aProd,FILE *aNosatis);
void mostrar(pedido);
int main()
{
    FILE *aProd,*aPed,*aNosatis;
    aProd=fopen("PRODUCTOS.DAT","rb+");
    if(aProd!=NULL)
    {
        aPed=fopen("PEDIDOS.DAT","rb");
        if(aPed!=NULL)
        {
            aNosatis=fopen("NO_SATISFECHOS.DAT","wb");
            if(aNosatis!=NULL)
            {
                verifCompra(aPed,aProd,aNosatis);
                fclose(aNosatis);
            }
            else cout<<"ERROR"<<endl;
            fclose(aPed);
        }
        else cout<<"ERROR"<<endl;
        fclose(aProd);
    }
    else cout<<"ERROR"<<endl;
    return 0;
}

void verifCompra(FILE *aPed,FILE *aProd,FILE *aNosatis)
{
    pedido ped;
    producto prod;
    fread(&ped,sizeof(pedido),1,aPed);
    while(!feof(aPed))
    {
        fread(&prod,sizeof(producto),1,aProd);
        fseek(aProd,(ped.codigo-1)*sizeof(producto),SEEK_SET);
        if(prod.stock>=ped.cant)
        {
            mostrar(ped);
            prod.stock-=ped.cant;
            fseek(aProd,-sizeof(producto),SEEK_CUR);
            fwrite(&prod,sizeof(producto),1,aProd);
        }
        else
        {
            fwrite(&ped,sizeof(pedido),1,aNosatis);
        }
        fread(&ped,sizeof(pedido),1,aPed);
    }
}

void mostrar(pedido ped)
{
    cout<<"Pedidos satisfechos"<<endl<<"Numero de pedido: "<<ped.nroped<<"\tNumero de cliente: "<<ped.cliente<<"\tCodigo del producto: "<<ped.codigo<<"\tCantidad pedida: "<<ped.cant<<endl;
}