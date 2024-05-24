/*El máximo común divisor entre dos números A y B se define como:
MCD (A y B) = MCD (B y resto de A dividido B) si resto A dividido B es distinto a 0
MCD (A y B) = B si resto A dividido B es igual a 0*/
#include<iostream>
#include<conio.h>
using namespace std;
int MCD(int,int);

int main()
{
    int a,b;
    cout<<"Ingrese 2 numeros para conocer el MCD\n";
    cin>>a>>b;
    cout<<"El MCD de "<<a<<" y "<<b<<" es "<<MCD(a,b);
    getch();
}

int MCD(int a,int b)
{
    if(a%b==0) return b;
    else
    return MCD(b,a%b);
}