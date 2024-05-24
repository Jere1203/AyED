/*Dado un valor n devolver el término n de la serie de Fibonacci (1, 1, 2, 3, 5, 8, 13,….)*/
#include<iostream>
using namespace std;
int fib(int);
int main()
{
    cout<<"Ingrese un valor n"<<endl;
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}

int fib(int n)
{
    if(n<3) return 1;
    if(n>=3) return (fib(n-1)+fib(n-2));
}