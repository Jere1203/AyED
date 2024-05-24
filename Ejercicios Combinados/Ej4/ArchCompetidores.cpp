/*En un club deportivo barrial se quiere hacer un programa para obtener datos
estadísticos de los atletas que compitieron en el año 2019 en las 15 actividades
deportivas que se practican en el mismo.
Se tiene el archivo “Competidores.dat”, con cada una de las participaciones de los
atletas competencias, sin orden, donde cada registro tiene el siguiente formato:
Código de actividad (1..15)
Número de socio del atleta
Fecha de la competencia (struct dia, mes, anio)
Resultado (int)*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct competidor
{
    int codAct,nroSoc,dia,mes,anio,result;
};

int main()
{
    FILE *ArchComp;
    competidor comp;
    ArchComp=fopen("Competidores.dat","wb");
    cout<<"CODIGO: "<<endl;
    cin>>comp.codAct;
    while(comp.codAct!=0)
    {
        cout<<"SOCIO: "<<endl;
        cin>>comp.nroSoc;
        cout<<"DIA: "<<endl;
        cin>>comp.dia;
        cout<<"MES: "<<endl;
        cin>>comp.mes;
        cout<<"ANIO: "<<endl;
        cin>>comp.anio;
        cout<<"RESULTADO: "<<endl;
        cin>>comp.result;
        fwrite(&comp,sizeof(competidor),1,ArchComp);
        cout<<"CODIGO: "<<endl;
        cin>>comp.codAct;
    }
    fclose(ArchComp);
    getch();
}