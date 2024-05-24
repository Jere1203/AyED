/*Hacer un algoritmo que lea 40 números y los muestre en orden inverso.*/
#include<iostream>
#include<conio.h>
#define MAX 5

using namespace std;

int main()
{
    int numero[MAX],inverso[MAX],i,j;
    cout<<"Ingrese serie de numeros\n";
    for(i=0;i<MAX;i++)
    {
        cin>>numero[i];
    }
    /*for(i=0;i<MAX;i++)
    {
        inverso[MAX-1-i]=numero[i];
    }*/
    i=0;
    for(j=MAX-1;j>=0;j--)
    {
        inverso[j]=numero[i];
        i++;
    }
    for(i=0;i<MAX;i++)
    {
        cout<<inverso[i];
    }
    getch();
}