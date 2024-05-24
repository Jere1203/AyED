/*Hacer una función que dado un vector de números enteros repetidos muestre todas las posiciones donde se
encuentra el menor elemento.*/
#include<iostream>
using namespace std;
void ingresoDatos(int[],int);
void sort(int[],int);
void Cctrol(int[],int);
int main()
{
    int nros[10] {7,3,4,3,2,4,6,8,0,7};
    sort(nros,10);
    cout<<"El menor es: "<<nros[0]<<endl;
    Cctrol(nros,10);
    return 0;
}

void sort(int nros[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam-i-1;j++)
        {
            if(nros[j]>nros[j+1])
            {
                int aux=nros[j];
                nros[j]=nros[j+1];
                nros[j+1]=aux;
            }
        }
    }
}

void Cctrol(int nros[],int tam)
{
    int i=0,cont,menor;
    while(i<tam)
    {
        menor=nros[0];
        cont=0;
        do
        {
            i++;
            cont++;
        }
        while(i<tam && nros[i]==menor);
        cout<<"El numero "<<nros[0]<<" se repite "<<cont<<" veces."<<endl;
    }
}