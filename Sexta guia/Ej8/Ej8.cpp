/*Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
b) Dado un código de producto informar su precio.*/
#include<iostream>
#include<conio.h>
void sort(int[],int[],int&);
void mostrar(int[],int[],int&);
int buscar(int[],int[],int&,int);
using namespace std;
int main()
{
    int codigo[20];
    int precio[4],i=0,buscarCod;
    while(codigo!=0)
    {
        cout<<"Ingrese codigo del producto.\n";
        cin>>codigo[i];
        if(codigo[i]==0) break;
        cout<<"Ingrese precio del producto.\n";
        cin>>precio[i];
        i++;
    }
    sort(codigo,precio,i);
    cout<<"\nIngrese codigo para buscar precio.\n";
    cin>>buscarCod;
    cout<<"\nEl codigo "<<buscarCod<<" tiene un precio de: "<<precio[buscar(codigo,precio,i,buscarCod)];
    getch();
}

void sort(int codigo[],int precio[],int &n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(precio[i]<precio[j])
            {
                int a=precio[i];
                precio[i]=precio[j];
                precio[j]=a;
                
                int b=codigo[i];
                codigo[i]=codigo[j];
                codigo[j]=b;
            } 
        }
    }
    mostrar(codigo,precio,n);
}

void mostrar(int codigo[],int precio[],int &n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"\nCodigo: "<<codigo[i]<<"\n"<<"Precio: "<<precio[i];
    }
}

int buscar(int codigo[],int precio[],int &n,int buscarCod)
{
    for(int i=0;i<n;i++)
    {
        if(buscarCod==codigo[i]); return i;
    }
}