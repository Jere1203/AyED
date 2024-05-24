/*Hacer un algoritmo que lea 30 notas las cargue un vector y luego muestre la nota máxima*/

#include<iostream>
#include<conio.h>
#define MAX 5

using namespace std;

int main()
{
    int notas[MAX],maxNota,i;
    bool primVal=true;
    cout<<"Ingrese 30 notas\n";
    for(i=0;i<MAX;i++)
    {
        cin>>notas[i];
    }
    for(i=0;i<MAX;i++)
    {
        if(primVal==true)
        {
            primVal=false;
            maxNota=notas[i];
        }
        if(notas[i]>maxNota) maxNota=notas[i];
    }
    cout<<"La mayor nota es "<<maxNota;
    getch();
}