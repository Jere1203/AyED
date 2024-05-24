/*Mostrar n veces una línea de texto.*/
#include<iostream>
#include<conio.h>

using namespace std;
void mensaje(string,int);

int main()
{
    mensaje("Hola mundo",2);
    getch();
}

void mensaje(string texto,int n)
{
    if(n!=0 && n>0)
    {
        cout<<texto<<endl;
        mensaje(texto,n-1);
    }
}