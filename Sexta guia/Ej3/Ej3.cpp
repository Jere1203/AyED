/*Hacer un algoritmo que lea 40 edades de alumnos y muestre por pantalla las edades que superen a
la edad promedio.*/

#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 5

int main()
{
    int edad[MAX],promEdad,masProm[MAX],i;
    cout<<"Ingrese edades\n";
    for(i=0;i<MAX;i++)
    {
        cin>>edad[i];
        promEdad+=edad[i];
    }
    promEdad/=MAX;
    for(i=0;i<MAX;i++)
    {
        if(edad[i]>promEdad) masProm[i]=edad[i];
    }
    cout<<"Las edades que superan al promedio son: ";
    for(i=0;i<MAX;i++)
    {
        if(masProm[i]>0) cout<<" "<<masProm[i];
    }
    getch();
}