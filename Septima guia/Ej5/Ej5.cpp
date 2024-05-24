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
void apareo(FILE*,FILE*,FILE*);
int main()
{
    FILE *aAct,*aMaestro,*aDia;
    aAct=fopen("FINALESACT.DAT","wb");
    if(aAct!=NULL)
    {
        aMaestro=fopen("MAESTROFINALES.DAT","rb");
        if(aMaestro!=NULL)
        {
            aDia=fopen("DIAFINALES.DAT","rb");
            if(aDia!=NULL)
            {
                apareo(aAct,aMaestro,aDia);
            }
            else cout<<"ERROR"<<endl;
            fclose(aDia);
        }
        else cout<<"ERROR"<<endl;
        fclose(aMaestro);
    }
    else cout<<"ERROR"<<endl;
    fclose(aAct);
    getch();
}

void apareo(FILE *aAct,FILE *aMaestro,FILE *aDia)
{
    alumno al1,al2;
    fread(&al1,sizeof(alumno),1,aMaestro);
    fread(&al2,sizeof(alumno),1,aDia);
    while(!feof(aMaestro) && !feof(aDia))
    {
        if(al1.nroleg<al2.nroleg)
        {
            cout<<al1.nroleg<<endl;
            fwrite(&al1,sizeof(alumno),1,aAct);
            fread(&al1,sizeof(alumno),1,aMaestro);
        }
        else
        {
            if(al1.nroleg==al2.nroleg)
            {
                cout<<al1.nroleg<<endl;
                fwrite(&al1,sizeof(alumno),1,aAct);
                fwrite(&al2,sizeof(alumno),1,aAct);
                fread(&al1,sizeof(alumno),1,aMaestro);
                fread(&al2,sizeof(alumno),1,aDia);
            }
            else
            {
                cout<<al2.nroleg<<endl;
                fwrite(&al2,sizeof(alumno),1,aAct);
                fread(&al2,sizeof(alumno),1,aDia);
            }
        }
    }
    while(!feof(aMaestro))
    {
        cout<<al1.nroleg<<endl;
        fread(&al1,sizeof(alumno),1,aMaestro);
        fwrite(&al1,sizeof(alumno),1,aAct);
    }
    while(!feof(aDia))
    {
        cout<<al2.nroleg<<endl;
        fread(&al2,sizeof(alumno),1,aDia);
        fwrite(&al2,sizeof(alumno),1,aAct);
    }
}