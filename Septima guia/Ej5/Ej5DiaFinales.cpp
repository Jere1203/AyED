/*Se dispone un archivo binario de inscripción de alumnos a exámenes finales MAESTROFINALES.DAT y otro con
las inscripciones del día de hoy DIAFINALES.DAT, ambos ordenados ascendente por número de legajo y código
materia y con el siguiente diseño:
a.1Nro de legajo a.2 Código de materia a.3 ApellidoNombre
Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales FINALESACT.DAT
resultante del apareo de los dos archivos anteriores, con el mismo orden y diseño.*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct alumno
{
    unsigned nroleg;
    unsigned codmat;
    char nomyap[20];
};

int main()
{
    FILE *aDia;
    aDia=fopen("DIAFINALES.DAT","wb");
    if(aDia!=NULL)
    {
        alumno alum;
        cout<<"Ingrese numero de legajo: "<<endl;
        cin>>alum.nroleg;
        while(alum.nroleg!=0)
        {
            cout<<"Ingrese codigo de materia: "<<endl;
            cin>>alum.codmat;
            cout<<"Ingrese nombre y apellido: "<<endl;
            fflush(stdin);
            cin.getline(alum.nomyap,20);
            fwrite(&alum,sizeof(alumno),1,aDia);
            cout<<"Ingrese numero de legajo"<<endl;
            cin>>alum.nroleg;
        }
        fclose(aDia);
    }
    else cout<<"ERROR"<<endl;
    getch();
}