/*Confeccionar un programa que pueda determinar el importe a pagar por una prestación
médica según su código. Los importes se cobran según la siguiente tabla :
Código Importe $
A 200
D 400
F 600
M 1500
T 15000
Por cada prestación se debe ingresar el número de historia del paciente y el código de la
prestación. Se debe emitir un ticket para cada uno, con el número de la historia, el código y el
importe a pagar.*/

#include<stdio.h>
#include<conio.h>
#define A 200
#define D 400
#define F 600
#define M 1500
#define T 15000

int main()
{
    int paciente;
    char prestacion;
    printf("Ingrese DNI del paciente y codigo de prestacion\n");
    scanf("%d %c",&paciente,&prestacion);
    switch (prestacion)
    {
    case 'A':
        printf("PACIENTE: %d    CODIGO: %c  IMPORTE: $%d",paciente,prestacion,A);
        break;
    case 'D':
        printf("PACIENTE: %d    CODIGO: %c  IMPORTE: $%d",paciente,prestacion,D);
        break;
    
    case 'F':
        printf("PACIENTE: %d    CODIGO: %c  IMPORTE: $%d",paciente,prestacion,F);
        break;

    case 'M':
        printf("PACIENTE: %d    CODIGO: %c  IMPORTE: $%d",paciente,prestacion,M);
        break;

    case 'T':
        printf("PACIENTE: %d    CODIGO: %c  IMPORTE: $%d",paciente,prestacion,T);
        break;
    }
    getch();
}