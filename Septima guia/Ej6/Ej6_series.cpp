/*Una empresa de canales por cable desea actualizar el archivo de series que emite por sus distintos canales, con
material nuevo. Para ello posee los siguientes archivos:
a) un archivo maestro de series, Series.dat, con un registro con los datos de las series, ordenado ascendente por
Id_Serie, con el siguiente diseño:
a.1) Id_Serie a.2) Título de la serie a.3) Genero*/
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
    FILE *aSeries;
    aSeries=fopen("Series.DAT","wb");
    if(aSeries!=NULL)
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
            fwrite(&serie,sizeof(series),1,aSeries);
            cout<<"Ingrese id de la serie (ingrese 0 para finalizar el ingreso)"<<endl;
            cin>>serie.Id_serie;
        }
    }
    else cout<<"ERROR"<<endl;
    fclose(aSeries);
    getch();
}