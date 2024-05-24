/*Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere un
vector de 10 posiciones con el contenido de ambos vectores intercalados.*/
#include<iostream>
#include<conio.h>
#define MAX_V 5
#define MAX_F 10
using namespace std;
void unif(int[],int[]);

int main()
{
    int i,vecA[MAX_V],vecB[MAX_V];
    cout<<"Ingrese valores para el primer vector\n";
    for(i=0;i<MAX_V;i++)
    {
        cin>>vecA[i];
    }
    cout<<"Ingrese valores para el segundo vector\n";
    for(i=0;i<MAX_V;i++)
    {
        cin>>vecB[i];
    }
    unif(vecA,vecB);
    getch();
}

void unif(int A[5],int B[5])
{
    int vecUnif[MAX_F];
    int i=0,j=0;
    while(i<MAX_V)
    {
        vecUnif[j++]=A[i];
        vecUnif[j++]=B[i++];
    }
    for(i=0;i<MAX_F;i++)
    {
        cout<<vecUnif[i];
    }
}