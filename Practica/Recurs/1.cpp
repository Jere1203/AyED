/*Mostrar n veces una línea de texto*/
#include<iostream>
using namespace std;
int recurs(int);
int main()
{
    cout<<"Ingrese valor n"<<endl;
    int n;
    cin>>n;
    recurs(n);
    return 0;
}

int recurs(int n)
{
    if(n>0)
    {
        cout<<"> Hola mundo"<<endl;
        return recurs(n-1);
    }
}