/*Dados dos valores, m (<=30) y n (<=25), ingresar por filas todos los componentes de una matriz de
m filas y n columnas. Desarrollar un programa que:
✓ Imprima la matriz por columna.
✓ Calcule e imprima el valor promedio de los componentes de la matriz.
✓ Genere e imprima un vector donde cada componente sea la suma de la columna homóloga.
✓ Genere e imprima un vector donde cada componente sea el valor máximo de cada fila.*/
#include<iostream>
using namespace std;
void cargarMat(int[][25],int,int);
void mostrarMat(int[][25],int,int);
float promMat(int[][25],int,int);
void incic(int v[],int tam);
void sumHomol(int [][25],int,int);
void maxFila(int [][25],int,int);
int main()
{
    int mat[30][25];
    int maxf,maxc;
    cout<<"Elija valor maximo para filas y columnas"<<endl;
    cin>>maxf>>maxc;
    cargarMat(mat,maxf,maxc);
    mostrarMat(mat,maxf,maxc);
    cout<<"El promedio de los componentes es: "<<promMat(mat,maxf,maxc)<<endl;
    sumHomol(mat,maxf,maxc);
    maxFila(mat,maxf,maxc);
    return 0;
}

void incic(int v[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        v[i]=0;
    }
}

void cargarMat(int mat[][25],int maxf,int maxc)
{
    for(int i=0;i<maxf;i++)
    {
        for(int j=0;j<maxc;j++)
        {
            cout<<"Elija valor para "<<i+1<<","<<j+1<<endl;
            cin>>mat[i][j];
        }
    }
}

void mostrarMat(int mat[][25],int maxf,int maxc)
{
    for(int i=0;i<maxf;i++)
    {
        for(int j=0;j<maxc;j++)
        {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}

float promMat(int mat[][25],int maxf,int maxc)
{
    float prom=0;
    for(int i=0;i<maxf;i++)
    {
        for(int j=0;j<maxc;j++)
        {
            prom+=mat[i][j];
        }
    }
    return prom/=(maxf*maxc);
}

void sumHomol(int mat[][25],int maxf,int maxc)
{
    int suma[maxc];
    incic(suma,maxc);
    for(int i=0;i<maxf;i++)
    {
        for(int j=0;j<maxc;j++)
        {
            suma[j]+=mat[i][j];
        }
    }
    cout<<"La suma homologa de las columnas es"<<endl;
    for(int i=0;i<maxc;i++)
    {
        cout<<suma[i]<<" ";
    }
    cout<<endl;
}

void maxFila(int mat[][25],int maxf,int maxc)
{
    int max[maxf];
    incic(max,maxf);
    bool prim;
    for(int i=0;i<maxf;i++)
    {
        for(int j=0;j<maxc;j++)
        {
            if(prim==true)
            {
                max[i]=mat[i][j];
                prim=!prim;
            }
            if(mat[i][j]>max[i]) max[i]=mat[i][j];
        }
    }
    for(int i=0;i<maxf;i++)
    {
        cout<<"El maximo valor en la fila "<<i+1<<" es: "<<max[i]<<endl;
    }
}