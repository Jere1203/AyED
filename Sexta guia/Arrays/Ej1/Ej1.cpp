/*Un negocio de ropa, vende sus artículos en distintos talles. Para realizar la facturación se ingresan los precios de cada
artículo y talle que vende:
código de articulo (1..100)
talle (1..5)
precio

También se dispone de un conjunto de ventas a facturar, que se ingresan por teclado con los siguientes
datos:
código de artículo (1..100)
talle (1..5)
unidades vendidas
Las ventas finalizan con un código de artículo negativo.
Desarrollar un algoritmo que:
a) informe el precio de la venta, considerando un descuento del 10% si las unidades vendidas son superiores a
tres más el 21% del IVA.
b) al final del proceso emita el siguiente listado, ordenado por artículo y talle ascendente:
Código de Artículo 999
Talle Unidades Vendidas
9 99
9 99
Total unidades vendidas artículo 9999999
………………………………………..
Total general de unidades vendidas 9999999*/
#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;
void inicVector(int vec[]);
void ingresoCod(int cod[]);
void cargarProd(int m[][5],int cf,int cc);
void cargarVent(int m[][5],int cf,int cc);

int main()
{
    int matrizProd[MAX][5];
    int matrizVent[MAX][5];
    int codigo[MAX];
    int codigoVent[MAX];
    inicVector(codigo);
    inicVector(codigoVent);
    ingresoCod(codigo);
    ingresoCod(codigoVent);
    cargarProd(matrizProd,MAX,5);
    cargarVent(matrizVent,MAX,5);
}

void cargarProd(int m[][5],int cf,int cc)
{
    for(int j=0;j<cc;j++)
    {
        for(int i=0;i<cf;i++)
        {
            cout<<"Ingresar precio en la posicion "<<i<<","<<j<<endl;
            cin>>m[i][j];
        }
    }
}

void cargarVent(int m[][5],int cf,int cc)
{
    for(int j=0;j<cc;j++)
    {
        for(int i=0;i<cf;i++)
        {
            cout<<"Ingresar precio en la posicion "<<i<<","<<j<<endl;
            cin>>m[i][j];
        }
    }
}

void inicVector(int vec[])
{
    for(int i=0;i<100;i++)
    {
        vec[i]=0;
    }
}

void ingresoCod(int cod[])
{
    for(int i=0;i<MAX;i++)
    {
        cout<<"Ingrese codigo de la prenda\n"<<endl;
        cin>>cod[i];
    }
}