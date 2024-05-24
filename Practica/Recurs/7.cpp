/*Dado un número entero positivo imprimir su imagen especular (ej: de 123 su imagen es 321).*/
#include<iostream>
using namespace std;
int espec(int);
int main()
{
    int nro;
    cin>>nro;
    cout<<espec(nro)<<endl;
    return 0;
}

int espec(int nro)
{
    if(nro<10) return nro;
    else
    {
        cout<<nro%10;
        espec(nro/10);
    }
}