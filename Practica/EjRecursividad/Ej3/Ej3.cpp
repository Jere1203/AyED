/*Obtener a n como el producto de a, n veces.*/
#include<iostream>
#include<conio.h>
using namespace std;
int prod(int,int);
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<prod(a,n)<<endl;
    getch();
}

int prod(int a,int n)
{
    if(n==0) return 1;
    if(n>0) return a*prod(a,n-1);
}