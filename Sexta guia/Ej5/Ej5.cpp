/*Dado un conjunto desordenado de valores enteros comprendidos entre 1 y 500, sin repetición, que
finaliza con cero, desarrollar un algoritmo que:
. Imprima un listado ordenado de aquellos valores enteros que se encuentran en el conjunto
. Imprima un listado ordenado de aquellos valores enteros que no se encuentran en el conjunto.*/
#include<iostream>
#include<conio.h>
#define MAX 5
using namespace std;
void sort(int[]);
int main()
{
    int valores[MAX],i;
    for(i=0;i<MAX;i++)
    {
        valores[i]=0;
    }
    for(i=0;i<MAX;i++)
    {
        cin>>valores[i];
        if(valores[i]==0) break;
    }
    sort(valores);
}

void sort(int array[])
{
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=i+1;j<MAX;j++)
        {
            if(array[i]>array[j])
            {
                int a=array[i];
                array[i]=array[j];
                array[j]=a;
            } 
        }
    }
    for(i=0;i<MAX;i++)
    {
        if(array[i]!=0)
        {
            cout<<array[i]<<" pertentece al conjunto"<<"\n";
        } 
        if(array[i]==0) cout<<i<<" no pertentece al conjunto"<<"\n";

    }
    getch();
}