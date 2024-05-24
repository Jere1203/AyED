/*Hacer un algoritmo que calcule e informe el factorial de números positivos ingresados por teclado.
El lote de números finaliza con cero.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    unsigned int nro,i,factous=0;
    printf("Ingrese numeros positivos para conocer sus factoriales o ingrese 0 para finalizar\n");
    for(i=0;1;i++)
    {
        scanf("%d",&nro);
        if(nro!=0)
        {
            factous=nro;
            for(int j=nro-1;j>0;j--)
            {
                factous*=(nro-j);
            }
            printf("El factorial de %d es %d\n",nro,factous);
        }
        else
        break;
    }
    getch();
}