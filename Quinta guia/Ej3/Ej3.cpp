/*Obtener a n como el producto de a, n veces.*/
#include<iostream>
#include<conio.h>

using namespace std;
int pot(int,int);

int main()
{
    int a,b;
    cout<<"Ingrese 2 valores para obtener potencia\n";
    cin>>a>>b;
    cout<<pot(a,b)<<endl;
    getch();
}

int pot(int a,int b)
{  
    if(b==1) return a;
    if(b==0) return 1;
    else
    return a*pot(a,b-1);
}