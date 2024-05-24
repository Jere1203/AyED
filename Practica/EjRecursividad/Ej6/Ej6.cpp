/*El máximo común divisor entre dos números A y B se define como:
MCD (A y B) = MCD (B y resto de A dividido B) si resto A dividido B es distinto a 0
MCD (A y B) = B si resto A dividido B es igual a 0*/
#include<iostream>
#include<conio.h>
using namespace std;
int mcd(int,int);
int main()
{
    int A,B;
    cin>>A>>B;
    cout<<mcd(A,B)<<endl;
    getch();
}

int mcd(int A,int B)
{
    if(A%B!=0) return mcd(B,A%B);
    else
    return B;
}