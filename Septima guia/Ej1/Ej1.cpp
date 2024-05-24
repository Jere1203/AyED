/*Se dispone de un conjunto de inscripciones de alumnos a examen en el mes de mayo.
Cada inscripción tiene los siguientes datos: nombre y apellido, número de legajo, código de materia, día, mes y año
del examen. Los datos finalizan con un número de legajo igual a cero.
Desarrollar un programa que a partir del ingreso de las inscripciones por teclado, genere un archivo binario de
inscripción de alumnos a exámenes finales DIAFINALES.DAT, según el siguiente diseño:
a.1 Nro. de legajo          a.2 Código de materia
a.3 Día del examen          a.4 Mes del examen
a.5 Año del examen          a.6 Nombre-Apellido*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct examen
{
    unsigned int leg;
    unsigned int mat;
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;
    char alumno[20]; 
};
int main()
{
    FILE *f;
    f=fopen("DIAFINALES.DAT","wb");
    if(f==NULL)
    {
        cout<<"Imposible abrir el archivo"<<endl;
    }
    else
    {
        examen alum;
        int i=0;
        cout<<"Ingrese legajo"<<endl;
        cin>>alum.leg;
        while(alum.leg!=0)
        {
            cout<<"Ingrese nombre"<<endl;
            fflush(stdin);
            cin.getline(alum.alumno,20);
            cout<<"Ingrese codigo"<<endl;
            cin>>alum.mat;
            cout<<"Ingrese fecha en formato DD/MM/AA"<<endl;
            cin>>alum.dia>>alum.mes>>alum.anio;
            fwrite(&alum,sizeof(examen),1,f);
            cout<<"Ingrese legajo (legajo 0 finaliza el ingreso)"<<endl;
            cin>>alum.leg;
        }
        fclose(f);
    }
    return 0;
}