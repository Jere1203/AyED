/*Hacer una función que dado un vector de números enteros y un número, devuelva la posición en la que está.*/
#include<iostream>
using namespace std;
int buscar(int[],int,int);
void sort(int[],int);
int main()
{
    int vec[10] {1,6,3,4,8,7,1,2,9,7};
    cout<<"Ingrese un numero para buscar"<<endl;
    int busc;
    cin>>busc;
    sort(vec,10);
    if(buscar(vec,busc,10)!=-1) cout<<"El numero ingresado se encuentra en la posicion "<<buscar(vec,busc,10)<<endl;
    else
    cout<<"El numero ingresado no se encuentra dentro del vector."<<endl;
    return 0;
}

void sort(int vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(vec[j]>vec[j+1])
            {
                int aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }
        }
    }
}

int buscar(int vec[],int bus,int tam)
{
    int desde=0,hasta=tam-1,medio;
    while(desde<=hasta && vec[medio]!=bus)
    {
        medio=(desde+hasta)/2;
        if(bus<medio)
        {
            hasta=medio-1;
        }
        else
        desde=medio+1;
    }
    if(vec[medio]==bus) return medio;
    else
    {
        return -1;
    }
}