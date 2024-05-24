/*Dado el archivo binario generado en el ejercicio 1, desarrolle un programa que solicitando por teclado un código de
materia permita seleccionar todos los registros de alumnos que se anotaron para rendirla y los grabe en otro archivo
(MATFINALES.DAT), con el mismo diseño.*/
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
    examen alum;
    int busc;
    cout<<"Ingrese codigo de materia para buscar"<<endl;
    cin>>busc;
    FILE*arch;
    arch=fopen("D:/Users/Jeremias/Escritorio/Trabajos UTN/Algoritmos y estructura de datos/Septima guia/Ej1/DIAFINALES.DAT","rb");
    if(arch==NULL) cout<<"ERROR"<<endl;
    else
    {
        FILE *f;
        f=fopen("MATFINALES.DAT","wb");
        if(arch==NULL) cout<<"ERROR"<<endl;
        else
        {
            fread(&alum,sizeof(examen),1,arch);
            while(!feof(arch))
            {
                if(busc==alum.mat)
                {
                    fwrite(&alum,sizeof(examen),1,f);   
                    fread(&alum,sizeof(examen),1,arch);
                }
                else
                fread(&alum,sizeof(examen),1,arch);
            }
        }
        fclose(f);
    }
    fclose(arch);
    return 0;
}