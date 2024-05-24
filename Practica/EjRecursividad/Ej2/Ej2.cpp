/*Obtener el producto de dos números a y b, enteros y positivos, calculado como la sumatoria de a,
b veces.*/
#include<iostream>
#include<conio.h>
using namespace std;
int sum(int,int);
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    cout<<sum(a,b)<<endl;
    getch();
}

int sum(int a, int b)
{
    if(b==1) return a;
    if(b==0) return 0;
    else
    return a+sum(a,b-1);
}