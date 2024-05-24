/*Dado un número N (<20), y dos vectores A y B de N elementos que contenga valores entre 0..9
que representan números naturales muy largos
a) genere e informe un tercer vector SUMA de N+1 elementos que sea el resultante de la suma de
los dos números.
b) genere e informe un tercer vector RESTA de N elementos que sea el resultante de la resta de
los dos números.*/
#include<iostream>
#include<conio.h>

using namespace std;
void ingresoDatos(int[],int[],int);

int main()
{
    int N;
    cout<<"Ingrese numero N\n";
    cin>>N;
    if(N>=20) getch();
    int A[N];
    int B[N];
    ingresoDatos(A,B,N);
    int sum[N+1];
    for(int i=0;i<N+1;i++)
    {
        sum[i]=A[i]+B[i];
    }
    int res[N];
    for(int i=0;i<N;i++)
    {
        res[i]=A[i]-B[i];
    }
    cout<<"\nEl vector suma es ";
    for(int i=0;i<N+1;i++)
    {
        cout<<sum[i];
    }
    cout<<"\nEl vector resta es ";
    for(int i=0;i<N;i++)
    {
        cout<<res[i];
    }
    getch();
}

void ingresoDatos(int A[],int B[],int tam)
{
    cout<<"Ingrese valores para A y B\n";
    for(int i=0;i<tam;i++)
    {
        cin>>A[i]>>B[i];
    }
}