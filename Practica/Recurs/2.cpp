/*Obtener el producto de dos números a y b, enteros y positivos, calculado como la sumatoria de a,
b veces.*/
#include<iostream>
using namespace std;
int prod(int,int);
int main()
{
    int a,b;
    cout<<"Ingrese a y b para conocer su producto"<<endl;
    cin>>a>>b;
    cout<<prod(a,b);
    return 0;
}

int prod(int a,int b)
{
    if(b==0) return 0;
    if(b==1) return a;
    if(b>0) return a+prod(a,b-1);
}