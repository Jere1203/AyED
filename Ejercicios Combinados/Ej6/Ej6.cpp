/*La ciudad de Buenos Aires requiere un estudio estadístico de infracciones
realizadas por los vehículos en sus calles. Para ello cuenta con un archivo de
infracciones “Infracciones.dat”, ordenado por fecha de la infracción creciente, con
el siguiente diseño:
Patente (7 caracteres)
Fecha de Infracción (int, aammdd)
Código de infracción (int, 1 a 100)
Se desea obtener un listado ordenado por código de infracción decreciente con las
patentes que cometieron más de una vez la misma infracción.*/

//vector de listas de patentes con cada codigo de infraccion

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
struct infracciones
{
    char patente[7];
    int fecha,codInfra;
};
struct Patentes
{
    char pat[7];
    int contInfra;
};
struct NodoInfra
{
    Patentes info;
    NodoInfra *sig;
};
void listarPat(NodoInfra *lista,int &i);
void listar(NodoInfra *lista[]);
void buscarInsertar(NodoInfra*&lista,infracciones &inf);
void cargarListas(FILE *&aInfra,NodoInfra *lInfra[]);

int main()
{
    FILE *aInfra;
    NodoInfra *lInfra[100];
    aInfra=fopen("Infracciones.dat","rb");
    for(int i=0;i<100;i++)
    {
        lInfra[i]=NULL;
    }
    cargarListas(aInfra,lInfra);
    listar(lInfra);
    getch();
}

void cargarListas(FILE *&aInfra,NodoInfra *lInfra[])
{
    infracciones inf;
    fread(&inf,sizeof(infracciones),1,aInfra);
    while(!feof(aInfra))
    {
        buscarInsertar(lInfra[inf.codInfra-1],inf);
        fread(&inf,sizeof(infracciones),1,aInfra);
    }
}

void buscarInsertar(NodoInfra*&lista,infracciones &inf)
{
    NodoInfra*ant,*p=lista;
    while(p!=NULL && (strcmp(p->info.pat,inf.patente)<0))
    {
        ant=p;
        p=p->sig;
    }
    if(p!=NULL && (strcmp(p->info.pat,inf.patente)==0)) p->info.contInfra++;
    else
    {
        NodoInfra*n=new NodoInfra;
        n->info.contInfra=1;
        strcpy(n->info.pat,inf.patente);
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else
            lista=n;
    }
}

void listar(NodoInfra *lista[])
{
    for(int i=99;i>=0;i--)
    {
        listarPat(lista[i],i);
    }
}

void listarPat(NodoInfra *lista,int &i)
{
    NodoInfra *p=lista;
    while(p!=NULL)
    {
        if(p!=NULL && p->info.contInfra>=2) cout<<"INFRACCION: "<<i+1<<endl; cout<<"PATENTE: "<<p->info.pat<<endl; 
        p=p->sig;
    }
}