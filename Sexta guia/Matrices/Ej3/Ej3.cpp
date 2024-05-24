/*Hacer una función que dada una matriz cuadrada calcule y devuelva la sumatoria del triángulo
superior con respecto a la diagonal principal*/
#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 2
void cargarMat(int[MAX][MAX]);
void mostrarMat(int [MAX][MAX]);
int sumDiag(int [MAX][MAX]);
int main()
{
    int mat[MAX][MAX];
    cargarMat(mat);
    mostrarMat(mat);
    cout<<"La sumatoria de la diagonal superior es: "<<sumDiag(mat)<<endl;
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
    char a=218;
    char b=179;
    char c=192;
    char d=191;
    char e=217;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        
    }
}

int sumDiag(int mat[MAX][MAX])
{
    int sum=0;
    for(int i=0;i<MAX;i++)//fila
    {
        for(int j=0;j<MAX;j++)
        {
            if(i<=j)sum+=mat[i][j];
        }
    }
    return sum;
}