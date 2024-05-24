/*1) Informar cantidad de consultas realizadas por cada paciente.
2) Informar por cada especialidad: código y nombre de la especialidad y cantidad
de consultas de esa especialidad en cada mes.
3) Generar el archivo ”ConsultasMedico.dat” con registro por cada médico, con el
siguiente diseño:
- número de matrícula del médico (entero)
- cantidad total de consultas realizadas en el año anterior.*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct medico
{
    int nromatricula,codespacialidad,totCons;
    char nombre [30];
};
struct especialidad
{
    int codesp;
    char nomesp [30];
};
struct consultas
{
    int dia,mes,nrohistpac,nromatmed;
};
struct MedicoP3
{
    int matr;
    int cantCons;
};
void inic(int cons[][12]);
void ccontrol(FILE*aCons,medico Vm[],int tam,int matCon[][12]);
void VecMed(FILE *aMed,medico Vm[],int &tam);
int main()
{
    FILE *aMed,*aEspec,*aCons,*aConsMed;
    int cons[10][12];
    medico med[100];
    int tam=0;
    inic(cons);
    aMed=fopen("Medicos.dat","rb");
    aEspec=fopen("Especialidades.dat","rb");
    aCons=fopen("Consultas.dat","rb");
    aConsMed=fopen("ConsultasMedico.dat","wb");
    VecMed(aMed,med,tam);
    ccontrol(aCons,med,tam,cons);
    P3(aConsMed,med,tam);
    fclose(aMed);
    fclose(aEspec);
    fclose(aCons);
    fclose(aConsMed);
    getch();
}

void ccontrol(FILE*aCons,medico Vm[],int tam,int matCon[][12])
{
    //corte control con struct consultas.
    consultas con;
    int sum,pac,cont;
    fread(&con,sizeof(consultas),1,aCons);
    while(!feof(aCons))
    {
        pac=con.nrohistpac;
        sum=0;
        cont=0;
        do
        {
            int fila=buscEs(Vm,tam,con.nromatmed);
            matCon[fila-1001][con.mes-1]++;
            sum+=con.nrohistpac;
            cont++;
            fread(&con,sizeof(consultas),1,aCons);
        }while(!feof(aCons) && con.nrohistpac==pac);
        cout<<pac<<" - "<<cont<<" veces."<<endl;
    }
}
int buscEs(medico med[],int tam,int matr)
{
    int i=0;
    while(i<tam && med[i].nromatricula != matr)
    {
        i++;
    }
    if(i==tam) return -1;
    else
    {
        med[i].totCons++;
        return med[i].codespacialidad;
    } 
}


void inic(int cons[][12])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<12;j++)
        {
            cons[i][j]=0;
        }
    }
}
void VecMed(FILE *aMed,medico Vm[],int &tam)
{
    medico med;
    fread(&med,sizeof(medico),1,aMed);
    while(!feof(aMed))
    {
        Vm[tam].nromatricula=med.nromatricula;
        Vm[tam].codespacialidad=med.codespacialidad;
        Vm[tam].totCons=0;
        tam++;
        fread(&med,sizeof(medico),1,aMed);
    }
}

void P3(FILE *aConsMed,medico Vm[],int tam)
{
    MedicoP3 medp3;
    for(int i=0;i<tam;i++)
    {
        medp3.cantCons=Vm[i].totCons;
        medp3.matr=Vm[i].nromatricula;
        fwrite(&medp3,sizeof(MedicoP3),1,aConsMed);
    }
}