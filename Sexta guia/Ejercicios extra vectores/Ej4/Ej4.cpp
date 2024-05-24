/*Hacer una función que dado un vector de números enteros devuelva el mayor número almacenado en el vector
y la posición en la que se encuentra.*/
#include<iostream>
#include<conio.h>
#define MAX_V 5
using namespace std;
void ingresoDatos(int [],int);
void mayor(int [],int);

int main()
{
    int i,tam;
    cout<<"Ingrese tamanio del vector\n";
    cin>>tam;
    int A[tam];
    ingresoDatos(A,tam);
    getch();
}

void ingresoDatos(int A[],int tam)
{
    int i=0;
    cout<<"Ingrese datos del vector\n";
    for(i=0;i<tam;i++)
    {
        cin>>A[i];
    }
    mayor(A,tam);
}

void mayor(int A[],int tam)
{
    bool prim=true;
    int i=0,mayor,posMayor;
    for(i=0;i<tam;i++)
    {
        if(prim == true)
        {
            mayor=A[i];
            posMayor=i;
            prim=false;
        }
        if(A[i]>mayor)
        {
            mayor=A[i];
            posMayor=i;
        }
    }
    cout<<"El mayor numero es "<<mayor<<" en la posicion "<<posMayor+1;

}