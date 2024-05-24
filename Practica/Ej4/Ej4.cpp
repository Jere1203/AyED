/*Hacer una función que dado un vector de números enteros devuelva el mayor número almacenado en el vector
y la posición en la que se encuentra.*/
#include<iostream>
using namespace std;
int mayor(int[],int);
int buscar(int[],int,int);
int main()
{
    int nro[5] {2,6,2,7,5};
    int bus=mayor(nro,5);
    if(buscar(nro,bus,5)!=-1) cout<<"El numero mayor es "<<mayor(nro,5)<<" y se encuentra en la posicion "<<buscar(nro,bus,5)<<endl;
    return 0;
}

int mayor(int nro[],int tam)
{
    bool prim=true;
    int may=0;
    for(int i=0;i<tam;i++)
    {
        if(prim==true)
        {
            may=nro[i];
            prim=!prim;
        }
        if(nro[i]>may) may=nro[i];
    }
    return may;
}

int buscar(int nro[10],int bus,int tam)
{
    int i=0;
    while(i<tam && nro[i]!=bus)
    {
        i++;
    }
    if(i==tam) return -1;
    else return i;
}