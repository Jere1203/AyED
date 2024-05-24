/*Dado un valor n devolver el término n de la serie de Fibonacci (1, 1, 2, 3, 5, 8, 13,….)*/
#include<iostream>                                              //1  2  3  4  5  6  7 
#include<conio.h>
using namespace std;
int fibonacci(int);
int main()
{
    unsigned long int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    getch();
}

int fibonacci(int n)
{
    if(n<=2) return 1;
    else
    return fibonacci(n-1)+fibonacci(n-2);
}