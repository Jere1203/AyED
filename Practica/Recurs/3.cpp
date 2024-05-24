/*Obtener a n como el producto de a, n veces.*/
#include<iostream>
using namespace std;
int prod(int,int);
int main()
{
    int a,n;
    cout<<"Ingrese valores a y n"<<endl;
    cin>>a>>n;
    cout<<prod(a,n)<<endl;
    return 0;
}

int prod(int a, int n)
{
    if(n==0) return 1;
    if(n==1) return a;
    if(n>1) return a*prod(a,n-1);
}