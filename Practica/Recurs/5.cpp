/*Calcular el combinatorio de m números tomados de a n, donde la definición recursiva es:*/
#include<iostream>
using namespace std;
int comb(int,int);
int main()
{
    int m,n;
    cout<<"Ingrese n,m"<<endl;
    cin>>m>>n;
    cout<<comb(m,n)<<endl;
    return 0;
}

int comb(int m,int n)
{
    if(n==0) return 1;
    else
    return comb(m,n-1)*(m-n+1)/n;
}