/*El máximo común divisor entre dos números A y B se define como:
MCD (A y B) = MCD (B y resto de A dividido B) si resto A dividido B es distinto a 0
MCD (A y B) = B si resto A dividido B es igual a 0*/
#include<iostream>
using namespace std;
int MCD(int,int);
int main()
{
    int a,b;
    cout<<"Ingrese valores a y b"<<endl;
    cin>>a>>b;
    cout<<MCD(a,b)<<endl;
    return 0;
}

int MCD(int a,int b)
{
    if(a%b!=0) return MCD(b,a%b);
    else
    return b;
}