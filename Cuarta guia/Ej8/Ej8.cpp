/*Desarrollar una función que dados el día, el mes y el año de una fecha correcta, devuelva la
misma en formato de entero de 8 dígitos con el formato AAAAMMDD*/
#include<iostream>
#include<conio.h>
using namespace std;
void cambio(int&,int&,int&);
int main()
{
    int dia,mes,anio;
    cout<<"Ingrese una fecha en formato DD/MM/AAAA\n";
    cin>>dia>>mes>>anio;
    cout<<"La fecha original es "<<dia<<"/"<<mes<<"/"<<anio;
    cambio(dia,mes,anio);
    cout<<"\nLa fecha invertida es "<<dia<<"/"<<mes<<"/"<<anio;
    getch();
}

void cambio(int &dia,int &mes, int &anio)
{
    int aux=dia;
    dia=anio;
    anio=aux;
}