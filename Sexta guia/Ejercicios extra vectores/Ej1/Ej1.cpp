/*Realizar una función que reciba por parámetro dos vectores de números enteros de 5 elementos cada uno y
genere un vector de 10 posiciones con el contenido de ambos vectores uno a continuación del otro.*/
#include<iostream>
#include<conio.h>
using namespace std;
void unif(int[],int[]);

int main()
{
    int i,vecA[5],vecB[5];
    cout<<"Ingrese valores para el primer vector\n";
    for(i=0;i<5;i++)
    {
        cin>>vecA[i];
    }
    cout<<"Ingrese valores para el segundo vector\n";
    for(i=0;i<5;i++)
    {
        cin>>vecB[i];
    }
    unif(vecA,vecB);
    getch();
}

void unif(int A[],int B[])
{
    int vecUnif[10];
    int i=0;
    for(i=0;i<10;i++)
    {
        if(i<5) vecUnif[i]=A[i];
        if(i>=5 && i<10) vecUnif[i]=B[i-5];
    }
    for(i=0;i<10;i++)
    {
        cout<<vecUnif[i];
    }
}