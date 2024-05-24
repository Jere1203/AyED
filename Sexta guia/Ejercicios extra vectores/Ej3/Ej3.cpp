/*Hacer una función que reciba un vector de números enteros y lo copie en otro en orden inverso.*/
#include<iostream>
#include<conio.h>
#define MAX_V 5
using namespace std;
void copVec(int[]);

int main()
{
    int i,vecA[MAX_V],vecB[MAX_V];
    cout<<"Ingrese valores para el vector\n";
    for(i=0;i<MAX_V;i++)
    {
        cin>>vecA[i];
    }
    copVec(vecA);
    getch();
}

void copVec(int A[])
{
    int B[MAX_V];
    int i=0,j=0;
    for(i=MAX_V-1;i>=0;i--)
    {
        B[i]=A[j];
        j++;
    }
    cout<<"El vector inverso es: ";
    for(i=0;i<MAX_V;i++)
    {
        cout<<B[i];
    }
}