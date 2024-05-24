/*Dado un conjunto de triángulos representados por sus lados lado1, lado2 y lado3 dados como
datos, determinar e imprimir la cantidad de triángulos equiláteros, isósceles y escalenos. El
ingreso de datos finaliza cuando un lado es nulo.*/
#include<stdio.h>
#include<conio.h>
/*
cantTriang[0]   escaleno
cantTriang[1]   isosceles
cantTriang[2]   equilatero
*/
int main()
{
    int lado1=1,lado2=1,lado3=1,i,cantTriang[3];
    printf("Ingrese valores para los lados de un triangulo\n");
    for(i=0;i<3;i++)
    {
        cantTriang[i]=0;
    }
    for(i=0;lado1!=0 && lado2!=0 && lado3!=0;i++)
    {
        scanf("%d %d %d",&lado1,&lado2,&lado3);
        if(lado1!=0 && lado2!=0 && lado3!=0)
        {
            if(lado1!=lado2&&lado1!=lado3&&lado2!=lado3) cantTriang[0]++;   //Escaleno
    
            if(lado1==lado2||lado1==lado3||lado2==lado3)
            {
                if(lado1!=lado2||lado1!=lado3||lado2!=lado3) cantTriang[1]++;   //Isosceles
            } 
        
            if(lado1==lado2&&lado1==lado3&&lado2==lado3) cantTriang[2]++;   //Equilatero
        }
        else
        {
            break;
        }
        
    }
    printf("En total hay %d triangulos escalenos, %d triangulos isosceles y %d triangulos equilateros\n",cantTriang[0],cantTriang[1],cantTriang[2]);
    getch();
}