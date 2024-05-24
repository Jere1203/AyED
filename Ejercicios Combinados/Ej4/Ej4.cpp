/*En un club deportivo barrial se quiere hacer un programa para obtener datos
estadísticos de los atletas que compitieron en el año 2019 en las 15 actividades
deportivas que se practican en el mismo.
Se tiene el archivo “Competidores.dat”, con cada una de las participaciones de los
atletas competencias, sin orden, donde cada registro tiene el siguiente formato:
Código de actividad (1..15)
Número de socio del atleta
Fecha de la competencia (struct dia, mes, anio)
Resultado (int)
Se pide:
a) Informar por cada actividad, por cada mes, cada uno de los atletas que
compitieron y el resultado obtenido, ordenado por código de actividad, por
mes y por número de socio.
b) Informar por cada mes del año el total de atletas que compitieron en cada
actividad.
c) Informar en qué actividad deportiva hubo más de un primer puesto.*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct competidor
{
    int codAct,nroSoc,dia,mes,anio,result;
};
struct Nodo
{
    competidor info;
    Nodo*sig;
};
void cargaArch(FILE *&ArchComp,Nodo *matComp[][12]);
void listarAct(Nodo *matAct[][12]);
void listarPart(Nodo*lista,int &contPrimer, int &contA);
void insertar(Nodo*&lista,competidor c);
void inicMat(Nodo *mat[][12]);
int main()
{
    FILE *archComp;
    archComp=fopen("Competidores.dat","rb");
    Nodo *matComp[15][12];
    inicMat(matComp);
    cargaArch(archComp,matComp);
    listarAct(matComp);
    getch();
}

void inicMat(Nodo *mat[][12])
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<12;j++)
        {
            mat[i][j]=NULL;
        }
    }
}

void insertar(Nodo*&lista,competidor c)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=c;
    p=lista;
    while(p!=NULL && p->info.codAct<c.codAct)
    {
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=lista)
        ant->sig=n;
    else
        lista=n;
}

void cargaArch(FILE *&ArchComp,Nodo *matComp[][12])
{
    competidor comp;
    fread(&comp,sizeof(competidor),1,ArchComp);
    while(!feof(ArchComp))
    {
        insertar(matComp[comp.codAct-1][comp.mes-1],comp);
        fread(&comp,sizeof(competidor),1,ArchComp);
    }
}
/*a) Informar por cada actividad, por cada mes, cada uno de los atletas que
compitieron y el resultado obtenido, ordenado por código de actividad, por
mes y por número de socio.*/
void listarAct(Nodo *matAct[][12])
{
    int contPrimer=0,contA=0;
    for(int i=0;i<15;i++)
    {
        contA=contPrimer=0;
        cout<<"==================================="<<endl;
        cout<<"Actividad: "<<i+1<<endl;
        for(int j=0;j<12;j++)
        {
            cout<<"Mes: "<<j+1<<endl;
            listarPart(matAct[i][j],contPrimer,contA);
        }
        cout<<"CANTIDAD DE PARTICIPANTES: "<<contA<<endl;
        if(contPrimer>1) cout<<"HUBO MAS DE UN GANADOR"<<endl;
    }
}

void listarPart(Nodo*lista,int &contPrimer, int &contA)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        if(p->info.result==1) contPrimer++;
        contA++;
        cout<<"CODIGO DE ATLETA: "<<p->info.nroSoc<<" RESULTADO: "<<p->info.result<<endl<<endl;
        p=p->sig;
    }
}
/*b) Informar por cada mes del año el total de atletas que compitieron en cada
actividad.*/
/*c) Informar en qué actividad deportiva hubo más de un primer puesto.*/