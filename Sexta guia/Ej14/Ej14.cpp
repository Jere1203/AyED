/*Se tiene un vector de productos (cada elemento tiene código, descripción y stock) y otro vector con
los productos recibidos de los proveedores (código, cantidad recibida), ambos ordenados por código
de producto. Se pide actualizar el stock del vector de productos.*/
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct productos
{
    unsigned int codigo;
    char desc[20];
    unsigned int stock;
};
struct proveedor
{
    unsigned int codigo;
    char desc[20];
    unsigned int stock;
};
void ingresoDatos(productos[],int);
void sort(productos[],int);
productos ingresoProd();
void apareo(productos prod[],int tam,proveedor prov[],int tam2);
void ingresoProv(proveedor prov[],int tam);
proveedor prodProv();
void sortProv(proveedor prov[],int tam);
int main()
{
    int max,maxprov;
    cout<<"Ingrese cantidad de productos\n";
    cin>>max;
    productos prod[max];
    proveedor prov[max];
    ingresoDatos(prod,max);
    sort(prod,max);
    cout<<"Ingrese cantidad de productos entrantes\n";
    cin>>maxprov;
    ingresoProv(prov,maxprov);
    sortProv(prov,maxprov);
    apareo(prod,max,prov,maxprov);
    getch();
}

void ingresoDatos(productos prov[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        prov[i]=ingresoProd();
    }
}

void ingresoProv(proveedor prov[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        prov[i]=prodProv();
    }
}   

proveedor prodProv()
{
    proveedor prov;
    cout<<"Ingrese codigo del producto\n";
    cin>>prov.codigo;
    cout<<"Ingrese cantidad de stock\n";
    cin>>prov.stock;
    cout<<"Ingrese descripicon del producto\n";
    cin>>prov.desc;
    return prov;
}

productos ingresoProd()
{
    productos prov;
    cout<<"Ingrese codigo del producto\n";
    cin>>prov.codigo;
    cout<<"Ingrese cantidad de stock\n";
    cin>>prov.stock;
    cout<<"Ingrese descripicon del producto\n";
    cin>>prov.desc;
    return prov;
}

void sort(productos prod[],int tam)
{
    int i,j;
    for(i=1;i<tam;i++)
    {
        for(j=0;j<tam-i;j++)
        {
            if(prod[j].codigo>prod[j+1].codigo)
            {
                int aux=prod[j+1].codigo;
                int aux2=prod[j+1].stock;
                char aux3[20];
                strcpy(aux3,prod[j+1].desc);
                prod[j+1].codigo=prod[j].codigo;
                prod[j+1].stock=prod[j].stock;
                strcpy(prod[j+1].desc,prod[j].desc);
                prod[j].codigo=aux;
                prod[j].stock=aux2;
                strcpy(prod[j].desc,aux3);
            }
        }
    }
}

void sortProv(proveedor prov[],int tam)
{
    int i,j;
    for(i=1;i<tam;i++)
    {
        for(j=0;j<tam-i;j++)
        {
            if(prov[j].codigo>prov[j+1].codigo)
            {
                int aux=prov[j+1].codigo;
                int aux2=prov[j+1].stock;
                char aux3[20];
                strcpy(aux3,prov[j+1].desc);
                prov[j+1].codigo=prov[j].codigo;
                prov[j+1].stock=prov[j].stock;
                strcpy(prov[j+1].desc,prov[j].desc);
                prov[j].codigo=aux;
                prov[j].stock=aux2;
                strcpy(prov[j].desc,aux3);
            }
        }
    }
}

void apareo(productos prod[],int tam,proveedor prov[],int tam2)
 {
     //ambos vectores tienen que estar ordenados
     int i=0,j=0;
     while(i<tam && j<tam2)
     {
         if(prod[i].codigo<prov[j].codigo)
         {
             cout<<prod[i].codigo<<"-"<<prod[i].desc<<"-"<<prod[i].stock<<endl;
             i++;
         }
         else
         {
             if(prod[i].codigo==prov[j].codigo)
             {
                cout<<prod[i].codigo<<"-"<<prod[i].desc<<"-"<<(prod[i].stock+prov[i].stock)<<endl;
                i++;
                j++;
             }
             else
             {
                cout<<prov[j].codigo<<"-"<<prov[j].desc<<"-"<<prov[j].stock<<endl;
                j++;
             }
         }
     }
     for(int k=i;k<tam;k++)
        cout<<prod[k].codigo<<"-"<<prod[k].desc<<"-"<<prod[k].stock<<endl;
     for(int k=j;k<tam2;k++)
        cout<<prov[k].codigo<<"-"<<prov[k].desc<<"-"<<prov[k].stock<<endl;

 }