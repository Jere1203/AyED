/*Se pide desarrollar la metodología necesaria para escribir un algoritmo que emita un listado ordenado por código de
libro, con un renglón por cada libro que tenga faltante en stock sea en depósito, local o en ambos lugares, con el
siguiente formato:
        Libros faltantes
Código                      Observación
9999                        Falta en depósito
9999                        Falta en local
9999                        Falta en local y en depósito
Total de libros en falta: 999*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct local
{
    unsigned codLibro;
    char titulo[30];
    char autor[20];
    char edit[20];
    unsigned stock;
    char genero[10];
};
struct deposito
{
    unsigned codLibro;
    unsigned stock;
};
void apareo(FILE*,FILE*);
int main()
{
    FILE *aLocal, *aDepo;
    aLocal=fopen("StockEnLocal.dat","rb");
    if(aLocal!=NULL)
    {
        aDepo=fopen("StockEnDeposito.dat","rb");
        if(aDepo!=NULL)
        {
            apareo(aLocal,aDepo);
        }
        else cout<<"ERROR"<<endl;
        fclose(aDepo);
    }
    else cout<<"ERROR"<<endl;
    fclose(aLocal);
    getch();
}

void apareo(FILE*aLocal,FILE*aDepo)
{
    local libroslocal;
    deposito librosdepo;
    fread(&libroslocal,sizeof(local),1,aLocal);
    fread(&librosdepo,sizeof(deposito),1,aDepo);
    while(!feof(aLocal) && !feof(aDepo))
    {
        
    }
}