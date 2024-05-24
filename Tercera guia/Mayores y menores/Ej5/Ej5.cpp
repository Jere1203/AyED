/*Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo
valores):
a) El valor máximo negativo
b) El valor mínimo positivo
d) El promedio de todos los valores.*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int num=1,i,maxNeg,minPos,contNeg=0,contPos=0,flagPrim=true;
    float prom;
    printf("Ingrese valores, para finalizar el ingreso ingrese 0\n");
    while(num!=0)
    {
        i++;
        scanf("%d",&num);
        if(flagPrim==true)
        {
            if(num<0) maxNeg=num;
            if(num>0) minPos=num;
            flagPrim=false;
        }
        /*if(num<0 && (i==1)) maxNeg=num;
        if(num>0 && (i==1)) minPos=num;*/
        if(num<=maxNeg && num<0)
        {
            maxNeg=num;
            contNeg++;
        } 
        if(num<minPos && num>0)
        {
            minPos=num;
            contPos++;
        } 
        prom+=(float)num;
    }
    prom/=i-1;
    if(contPos==0) printf("No se ingresaron numeros positivos\n");
    if(contNeg==0) printf("No se ingresaron numeros negativos\n");
    printf("El valor maximo negativo fue de %d, el minimo positivo fue %d, y el promedio de todos los numeros es de %f",maxNeg,minPos,prom);
    getch();
}