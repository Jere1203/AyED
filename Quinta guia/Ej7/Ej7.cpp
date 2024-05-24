/*Dado un número entero positivo imprimir su imagen especular (ej: de 123 su imagen es 321).*/
#include<iostream>
#include<conio.h>
using namespace std;
void espec(int);

int main()
{
    int n;
    cout<<"Ingrese un numero para conocer su imagen especular"<<endl;
    cin>>n;
    espec(n);
    getch();
}

void espec(int n)
{
    if(n<10) cout<<n;
    else
    {
        cout<<n%10;
        espec(n/10);
    }
}