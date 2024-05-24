/*Dados dos valores, FILA (<=30) y COLUM (<=25), ingresar por filas todos los componentes de una matriz de
FILA filas y COLUM columnas. Desarrollar un programa que:
✓ Imprima la matriz por columna.
✓ Calcule e imprima el valor promedio de los componentes de la matriz.
✓ Genere e imprima un vector donde cada componente sea la suma de la columna homóloga.
✓ Genere e imprima un vector donde cada componente sea el valor máximo de cada fila.*/
#include<iostream>
#include<conio.h>
using namespace std;
#define FILA 2
#define COLUM 3
void cargarMatriz(int mat[FILA][COLUM]);
void mostrarMatriz(int mat[FILA][COLUM]);
float prom(int mat[FILA][COLUM]);
void sumaHomolog(int sum[],int matr[FILA][COLUM]);
void inicMat(int matriz[FILA][COLUM]);
void maxFila(int max[],int mat[FILA][COLUM]);
int main()
{
    int matriz[FILA][COLUM];
    int sumHom[COLUM];
    int maxFil[FILA];
    inicMat(matriz);
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    sumaHomolog(sumHom,matriz);
    maxFila(maxFil,matriz);
    cout<<"El promedio de cada componente en la matriz es "<<prom(matriz);
    getch();
}

void cargarMatriz(int mat[FILA][COLUM])
{
    for(int j=0;j<COLUM;j++)
    {
        for(int i=0;i<FILA;i++)
        {
            cout<<"Ingrese numero para la posicion "<<i+1<<","<<j+1<<endl;
            cin>>mat[i][j];
        }
    }
}

void mostrarMatriz(int mat[FILA][COLUM])
{
    for(int j=0;j<FILA;j++)
    {
        for(int i=0;i<COLUM;i++)
        {
            cout<<mat[j][i]<<" ";
        }
        cout<<endl;
    }
}

float prom(int mat[FILA][COLUM])
{
    float prom=0;
    for(int j=0;j<COLUM;j++)
    {
        for(int i=0;i<FILA;i++)
        {
            prom+=(float)mat[i][j];
        }
    }
    prom/=(FILA*COLUM);
    return prom;
}

void sumaHomolog(int sum[],int matr[FILA][COLUM])
{
    int aux=0;
    for(int j=0;j<COLUM;j++)
    {
        aux=0;
        for(int i=0;i<FILA;i++)
        {
            aux+=matr[i][j];
        }
        sum[j]=aux;
    }
    cout<<"La suma de las columnas homologas es:\n";
    for(int i=0;i<COLUM;i++)
    {
        cout<<sum[i]<<" ";
    }
    cout<<endl;
}

void inicMat(int mat[FILA][COLUM])
{
    for(int j=0;j<COLUM;j++)
    {
        for(int i=0;i<FILA;i++)
        {
            mat[i][j]=0;
        }
    }
}

void maxFila(int max[],int mat[FILA][COLUM])
{
    bool prim=true;
    for(int j=0;j<COLUM;j++)
    {
        for(int i=0;i<FILA;i++)
        {
            if(prim==true)
            {
                prim=false;
                max[j]=mat[j][i];
            }
            if (mat[j][i]>max[j])max[j]=mat[j][i];
        }
        prim=true;
    }
    for(int i=0;i<FILA;i++)
    {
        cout<<"El valor maximo de la fila "<<i+1<<" es "<<max[i]<<endl;
    }
}