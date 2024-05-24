/*Rehacer el ejercicio 8 con un vector de struct.
a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
b) Dado un código de producto informar su precio.*/
#include<iostream>
#include<conio.h>
using namespace std;

struct producto
    {
        unsigned int codigo;
        unsigned int precio;
    };
producto ingresoCodigo();
void ingresoDatos(producto[],int);
void ordenar(producto[],int);
void mostrar(producto[],int);
int buscar(producto[],int,int);

int main()
{   
    int max,busc;
    cout<<"Ingrese max cantidad de prod.\n";
    cin>>max;
    producto productos[max];
    ingresoDatos(productos,max);
    ordenar(productos,max);
    mostrar(productos,max);
    cout<<"\nIngrese un codigo para saber el precio\n";
    cin>>busc;
    cout<<"\nEl producto con el codigo "<<busc<<" tiene un precio de: $"<<productos[buscar(productos,max,busc)].precio;
    getch();
}

producto ingresoCodigo()
{
    producto prod;
    cout<<"Ingrese codigo del producto\n";
    cin>>prod.codigo;
    cout<<"Ingrese precio del producto\n";
    cin>>prod.precio;
    return prod;
}

void ingresoDatos(producto prod[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        prod[i]=ingresoCodigo();
    }
}

void ordenar(producto prod[],int tam)
{
    int i=1,j=0;
    for(i=1;i<tam;i++)
    {
        for(j=0;j<tam-1;j++)
        {
            if(prod[j].precio<prod[j+1].precio)
            {
                int aux1=prod[j+1].precio;
                int aux2=prod[j+1].codigo;
                prod[j+1].precio=prod[j].precio;
                prod[j+1].codigo=prod[j].codigo;
                prod[j].precio=aux1;
                prod[j].codigo=aux2;
            }
        }
    }
}

void mostrar(producto prod[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        cout<<"\nProducto: "<<prod[i].codigo<<" Precio: "<<prod[i].precio;
    }
}

int buscar(producto prod[],int tam,int busc)
{
{
    unsigned i=0;
    while(i<tam && prod[i].codigo!=busc)
        i++;
    if(i==tam)
        return -1;
    else
        return i;
}
}