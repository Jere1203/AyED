/*Escriba un programa que permita ingresar la tirada de un par de dados 50 veces y muestre una lista
donde se vea cuántas veces se dio cada uno de los resultados posibles. Por cada tirada se deberán
ingresar 2 valores, cada uno representa el valor de un dado. El formato de la salida debe ser el
siguiente:
2 salió ... veces
3 salió ... veces
.
.
12 salió ... veces*/
#include<iostream>
#include<conio.h>
#define MAX 5
#define MAX_RES 11
using namespace std;

int main()
{
    int dado1,dado2, contSum[11];
    /*contSum[0] cont 2
    contSum[1] cont 3
    contSum[2] cont 4
    contSum[3] cont 5
    contSum[4] cont 6
    contSum[5] cont 7
    contSum[6] cont 8
    contSum[7] cont 9
    contSum[8] cont 10
    contSum[9] cont 11
    contSum[10] cont 12*/
    for(int i=0;i<MAX_RES;i++)
    {
        contSum[i]=0;
    }
    for(int i=0;i<MAX;i++)
    {
        cin>>dado1;
        cin>>dado2;
        contSum[(dado1+dado2)-2]++;
    }
    for(int i=0;i<MAX_RES;i++)
    {
        cout<<i+2<<" salio "<<contSum[i]<<" veces.\n";
    }
    getch();
}