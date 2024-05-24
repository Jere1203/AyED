/*Dado un valor n devolver el término n de la serie de Fibonacci (1, 1, 2, 3, 5, 8, 13,....)*/
#include<iostream>
#include<conio.h>
using namespace std;
int fibonacci(int);

int main()
{
    int n;
    cout<<"Ingrese un numero para obtener el correspondiende de la serie de Fibonacci"<<endl;
    cin>>n;
    cout<<"El numero " <<n<<" corresponde al " <<fibonacci(n)<<" en la serie de Fibonacci"<<endl;
    getch();
}

int fibonacci(int n)
{
    if(n<=2) return 1;
    else
    return fibonacci(n-1)+fibonacci(n-2);
}