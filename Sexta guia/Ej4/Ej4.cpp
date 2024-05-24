/*Desarrollar un programa que permita:
- Cargar un vector de 50 valores enteros
- Mostrar por pantalla el contenido del vector
- Obtener el mayor valor entero contenido en el vector y su posición en el mismo
- Obtener el menor valor entero contenido en el vector y su posición en el mismo.
Analizar y describir los cambios necesarios para resolver el mismo problema considerando a lo
sumo 50 valores enteros.*/
#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 50

int main()
{
    int vec[MAX],i,mayorVal,mayorPos,menorVal,menorPos;
    bool prim=true;
    cout<<"Ingrese valores\n";
    for(i=0;i<MAX;i++)
    {
        cin>>vec[i];
        if(prim==true)
        {
            prim=false;
            mayorVal=vec[i];
            mayorPos=i;
            menorVal=vec[i];
            menorPos=i;
        }
    }
    cout<<"Contenido del vector: ";
    for(i=0;i<MAX;i++)
    {
        cout<<vec[i];
    }
    for(i=0;i<MAX;i++)
    {
        if(vec[i]>mayorVal)
        {
            mayorVal=vec[i];
            mayorPos=i;
        }
        if(vec[i]<menorVal)
        {
            menorVal=vec[i];
            menorPos=i;
        }
    }
    cout<<"\nEl mayor valor es "<<mayorVal<<" y se encuentra en la posicion "<<mayorPos;
    cout<<"\nEl menor valor es "<<menorVal<<" y se encuentra en la posicion "<<menorPos;
    getch();
}