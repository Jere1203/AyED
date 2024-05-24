/*Mostrar n veces una línea de texto.*/
#include<iostream>
#include<conio.h>
using namespace std;
void rec(int);
int main()
{
    int n;
    cin>>n;
    rec(n);
    getch();
}

void rec(int n)
{
    if(n>0 && n!=0)
    {
        cout<<"Hola Mundo"<<endl;
        return rec(n-1);
    }
}