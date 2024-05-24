/*Obtener el producto de dos números a y b, enteros y positivos, calculado como la sumatoria de a,
b veces.*/
#include<iostream>
#include<conio.h>

using namespace std;
int producto (int,int);

int main()
{
    int a,b,prod;
    cout<<"Ingrese 2 valores\n";
    cin>>a;
    cin>>b;
    cout<<producto(a,b)<<endl;
    getch();
}

int producto(int a,int b)
{  
    if(b==1) return a;
    if(b==0) return 0;
    else
    return a+producto(a,b-1);
}