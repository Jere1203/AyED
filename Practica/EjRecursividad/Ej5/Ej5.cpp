/*Calcular el combinatorio de m números tomados de a n, donde la definición recursiva es:
m m m
C n = C n-1 * ( m –n + 1 ) y C 0 = 1*/
#include<iostream>
#include<conio.h>
using namespace std;
int comb(int,int);
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<comb(m,n)<<endl;
    getch();
}

int comb(int m,int n)
{
    if(n==0) return 1;
    else
    {
        return comb(m,n-1)*(m-n+1)/n;
    }
}