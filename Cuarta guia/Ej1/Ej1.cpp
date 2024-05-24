/*Desarrollar una función que calcule el máximo común divisor de dos números enteros A, B
con el siguiente algoritmo:
1. Dividir A por B, y calcular el resto (0 < R < B)
2. Si R = 0, el MCD es B, si no seguir en 3.
3. Reemplazar A por B, B por R, y volver al paso 1.*/
#include<stdio.h>
#include<conio.h>
int calcMCD(int,int);

int main()
{
    int numA,numB,MCD;
    printf("Ingrese 2 numeros enteros\n");
    scanf("%d",&numA);
    scanf("%d",&numB);
    MCD=calcMCD(numA,numB);
    printf("El maximo comun divisor de ambos numeros es %d",MCD);
    getch();
}


int calcMCD(int A,int B)
{
    int MCD;
    int R;
    while(R!=0)
    {
        R=A%B;
        if(R==0) MCD=B;
        else
        A=B;
        B=R;
    }
    return MCD;
}