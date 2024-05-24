/*En un Banco se procesan datos de las cuentas corrientes de los clientes. De cada cuenta se
conocen: número de cuenta, nombre del cliente y saldo actual. Se pide escribir un algoritmo que
permita informar por cada cuenta: número y estado (acreedor o deudor). También informar la
cantidad de cuentas con saldo deudor, con saldo acreedor y con saldo nulo. Para fin de datos
ingresar un número de cuenta negativo.*/
#include<stdio.h>
#include<conio.h>
/*
    cont[0] contador para cuentas deudoras
    cont[1] contador para cuentas acreedoras
    cont[2] contador para cuentas con saldo nulo
*/
int main()
{
    int cuenta,saldo,i,cont[3];
    char cliente[10];
    for(i=0;i<3;i++) {cont[i]=0;}
    while(1)
    {
        printf("Ingrese numero de cuenta, nombre del cliente y saldo actual\n");
        scanf("%d",&cuenta);
        if(cuenta>0)    
        {     
            scanf("%s %d",&cliente,&saldo);
            if(saldo<0) cont[0]++;
            if(saldo>0) cont[1]++;
            if(saldo==0) cont[2]++;
        }
        else break;
    }
    printf("En total se encontraron %d cuentas con saldo deudor, %d cuentas con saldo acreedor y %d cuentas con saldo nulo",cont[0],cont[1],cont[2]);
    getch();
}