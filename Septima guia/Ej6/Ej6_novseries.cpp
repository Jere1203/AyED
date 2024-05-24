/*Una empresa de canales por cable desea actualizar el archivo de series que emite por sus distintos canales, con
material nuevo. Para ello posee los siguientes archivos:

otro archivo de novedades de series, NovSeries.dat, con el mismo diseño y orden que el archivo anterior, que
contiene las novedades a incorporar.
Se pide desarrollar la metodología necesaria para escribir un algoritmo que Grabe un archivo maestro de series
actualizado, ActSeries.dat, con el mismo diseño y orden que los anteriores*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct series
{
    unsigned Id_serie;
    char titulo[20];
    char genero[10];
};

int main()
{
    FILE *aNov;
    aNov=fopen("NovSeries.DAT","wb");
    if(aNov!=NULL)
    {
        series serie;
        cout<<"Ingrese id de la serie (ingrese 0 para finalizar el ingreso)"<<endl;
        cin>>serie.Id_serie;
        while(serie.Id_serie<0) cin>>serie.Id_serie;
        while(serie.Id_serie>0)
        {
            cout<<"Ingrese titulo de la serie"<<endl;
            fflush(stdin);
            cin.getline(serie.titulo,50);
            cout<<"Ingrese genero de la serie"<<endl;
            cin>>serie.genero;
            fwrite(&serie,sizeof(series),1,aNov);
            cout<<"Ingrese id de la serie (ingrese 0 para finalizar el ingreso)"<<endl;
            cin>>serie.Id_serie;
        }
    }
    else cout<<"ERROR"<<endl;
    getch();
}