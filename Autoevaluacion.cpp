#include <iostream>
#include <string.h>
#include <string>
using namespace std;

struct Medico
{
   int matricula;
   int codigoE;
   int cantTotal;
};

struct Especialidad
{
    int codEsp;
    char nombreEsp[31];
};

struct Consulta
{
    int dia,mes, numHistCli;
    int matriculaCons;
};

struct MedicoFinal
{
    int matriculaFinal;
    int cantCons;
};


void cantidadConsultas(FILE * archC, Medico med[], int consultas[][12], int tam);
int consultaEspecialidad(Consulta c, Medico med[], int t);
void inicializar(int m[][12]);
void muestraTitulo();
void muestraEspecialidades(int m[][12], FILE * aEspecialidades);
void vectorMedicos(FILE *arch, Medico m[], int &tam);
void cargarArchivo(FILE * aNuevo, Medico med[], int tam);


int main()
{
    FILE * aMedicos;
    FILE * aConsultas;
    FILE * aEspecialidades;
    FILE * aNuevo;
    
    aMedicos= fopen("Medicos.dat", "rb");
    aConsultas= fopen("Consulta.dat", "rb");
    aEspecialidades = fopen("Especialidades.dat", "rb");
    aNuevo = fopen("ConsultasMedicos.dat", "wb");
    
    int consultas[10][12];
    int tam=0;
    
    Medico med[100];
    
    inicializar(consultas);
    vectorMedicos(aMedicos, med, tam);
    
    
    cantidadConsultas(aConsultas, med, consultas, tam);
    muestraEspecialidades(consultas, aEspecialidades);

    cargarArchivo(aNuevo, med, tam);
}

void cantidadConsultas(FILE * archC, Medico med[], int consultasM[][12], int tam)
{
    Consulta c;
    int historiaCli, cant, especialidad, columna, fila;
    
    fread(&c, sizeof(Consulta),1,archC);
    
    cout<<"Paciente de historia clinica       Cantidad Consultas "<<endl;
    
    while(!feof(archC))
    {
        cant=0;
        historiaCli= c.numHistCli;
        do
        {
           especialidad=consultaEspecialidad(c, med, tam);

           consultasM[especialidad-1001][c.mes - 1]+=1;
           cant++;
           fread(&c, sizeof(Consulta),1,archC);
           
        }while(c.numHistCli == historiaCli && !feof(archC));
        cout<<"       "<<historiaCli<<"                                "<<cant<<endl;
    }
}

void inicializar(int m[][12])
{
    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<12 ; j++)
        {
            m[i][j]=0;
        }
    }
}

void vectorMedicos(FILE *arch, Medico m[], int &tam)
{
    Medico med;

    
    fread(&med, sizeof(Medico), 1, arch);

    while(!feof(arch))
    {
        m[tam].matricula=med.matricula;
        m[tam].codigoE=med.codigoE;
        m[tam].cantTotal=0;
        tam++;
        fread(&med, sizeof(Medico), 1, arch);
    }    
}

int consultaEspecialidad(Consulta c, Medico med[], int t)
{
    int i=0;
    

    while(i<t && med[i].matricula != c.matriculaCons)
    {
        i++;
    }
    
    if(i==t)
    {
        return -1;
    }
    else
    { 
       med[i].cantTotal++; 
       return med[i].codigoE;
    }
}

void muestraTitulo()
{
    cout<<"                  1 2 3 4 5 6 7 8 9 10 11 12"<<endl;
}

void muestraEspecialidades(int m[][12], FILE * aEspecialidades)
{
    Especialidad e;

    fread(&e, sizeof(Especialidad),1,aEspecialidades);
    
    muestraTitulo();
    for(int i=0; i<10 ; i++)
    {
        cout<<e.codEsp<<" "<<e.nombreEsp<<" ";
        for(int j=0; j<12; j++)
        {
            cout<<m[i][j]<<" ";  
        }
        cout<<endl;
        fread(&e, sizeof(Especialidad),1, aEspecialidades);
    }
}

void cargarArchivo(FILE * aNuevo, Medico med[], int tam)
{
    MedicoFinal guardar;

    for(int i=0; i<tam; i++)
    {
        guardar.matriculaFinal=med[i].matricula;
        guardar.cantCons=med[i].cantTotal;

        fwrite(&guardar, sizeof(MedicoFinal),1,aNuevo);
    }
    
}