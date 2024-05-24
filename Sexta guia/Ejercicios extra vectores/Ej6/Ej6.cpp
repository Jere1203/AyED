/*Hacer una función que dado un vector de números enteros y un número, devuelva la posición en la que está.*/
#include<iostream>
#include<conio.h>
using namespace std;
int posicion(int[],int,int);
int main()
{
    int i,tam,num;
    int vecA[tam];
    cout<<"Ingrese tamanio del vector\n";
    cin>>tam;
    cout<<"Ingrese datos del vector\n";
    for(i=0;i<tam;i++)
    {
        cin>>vecA[i];
    }
    cout<<"Ingrese valor para saber la ubicacion en el vector\n";
    cin>>num;
    cout<<"El numero ingresado se encuentra en la posicion "<<posicion(vecA,num,tam);
    getch();
}


int posicion(int vec[],int num,int tam)
{
    int i,pos;
    for(i=0;i<tam;i++)
    {
        if(vec[i]==num) pos=i+1; 
    }
    return pos;
}