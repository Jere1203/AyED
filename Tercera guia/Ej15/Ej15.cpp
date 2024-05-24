/*Ingresar edades comprendidas entre 18 y 22, e imprimir cuántas veces se ingresó cada una de estas
edades. El lote finaliza con una edad igual a cero.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int i,nro,cont[5];
    //cont[0] es para el 18
    //cont[1] es para el 19
    //cont[2] es para el 20
    //cont[3] es para el 21
    //cont[4] es para el 22
    printf("Ingrese numeros comprendidos entre 18 y 22\n");
    for(i=0;i<5;i++)
    {
        cont[i]=0;
    }
    for(i=0;nro!=0;i++)
    {
        scanf("%d",&nro);
        if(nro!=0 && (nro>=18 && nro<=22))
        {
            if(nro==18) cont[0]++;
            if(nro==19) cont[1]++;
            if(nro==20) cont[2]++;
            if(nro==21) cont[3]++;
            if(nro==22) cont[4]++;
        }
    }
    printf("Se ingreso %d veces el numero 18, %d veces el numero 19, %d veces el numero 20, %d veces el numero 21 y %d veces el numero 22\n",cont[0],cont[1],cont[2],cont[3],cont[4]);
    getch();
}