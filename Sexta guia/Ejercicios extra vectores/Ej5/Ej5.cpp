/*Hacer una función que dado un vector de números enteros repetidos muestre todas las posiciones donde se
encuentra el menor elemento.*/
#include<iostream>
#include<conio.h>
#define MAX_V 5
using namespace std;
void ingresoDatos(int [],int);
void menor(int [],int);

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
    menor(A,tam);
}

void menor(int A[],int tam)
{
    bool prim=true;
    int i=0,menor,repMenor[tam];
    for(i=0;i<tam;i++)
    {
        if(prim == true)
        {
            menor=A[i];
            prim=false;
        }
        if(A[i]<menor)
        {
            menor=A[i];
        }
    }
    for(i=0;i<tam;i++)
    {
        repMenor[i]=0;
    }
    for(i=0;i<tam;i++)
    {
        if(A[i]==menor)
        {
            repMenor[i]=i+1;
        }
    }
    cout<<"El menor numero es "<<menor<<" y se repite en las posiciones ";
    for(i=0;i<tam;i++)
    {
        if(repMenor[i]!=0) cout<<' '<<repMenor[i];
    }
}