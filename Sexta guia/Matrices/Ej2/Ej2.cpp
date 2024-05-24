/*Dado un valor n (<=25), ingresar por filas una matriz cuadrada de n filas y columnas.
Desarrollar un algoritmo que determine e imprima los elementos de la diagonal principal o
secundaria según de cuál resulte mayor la sumatoria de elementos.*/
#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 3
void cargarMat(int[MAX][MAX]);
void mostrarMat(int [MAX][MAX]);
void sumDiag(int[MAX][MAX],int,int);
int main()
{
    int mat[MAX][MAX];
    int sumaPrinc=0,sumaSec=0;
    cargarMat(mat);
    mostrarMat(mat);
    sumDiag(mat,sumaPrinc,sumaSec);
    getch();
}

void cargarMat(int mat[MAX][MAX])
{
    for(int i=0;i<MAX;i++) //filas
    {
        for(int j=0;j<MAX;j++) //columnas
        {
            cout<<"Ingrese valor para posicion "<<i+1<<","<<j+1<<endl;
            cin>>mat[i][j];
        }
    }
}

void mostrarMat(int mat[MAX][MAX])
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sumDiag(int mat[MAX][MAX],int sumPrin,int sumSec)
{
    for(int i=0;i<MAX;i++)//fila
    {
        for(int j=0;j<MAX;j++)//columna
        {
            if(i==j)sumPrin+=mat[i][j];
        }
    }
    int j=MAX-1;
    for(int i=0;i<MAX;i++)//fila
    {
        sumSec+=mat[i][j];
        cout<<endl;
        j--;
    }
    if(sumPrin>sumSec)
    {
        for(int i=0;i<MAX;i++)
        {
            for(int j=0;j<MAX;j++)
            {
                if(i==j)cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        j=MAX-1;
        for(int i=0;i<MAX;i++)
        {
            cout<<mat[i][j];
            j--;
        }
    }
}

/*void sumDiagSec(int mat[MAX][MAX],int sum[MAX])
{
    int j=MAX-1;
    for(int i=0;i<MAX;i++)//fila
    {
        sum[i]+=mat[i][j];
        cout<<endl;
        j--;
    }
}*/