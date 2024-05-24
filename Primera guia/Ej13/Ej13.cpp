/*En una empresa automotriz existen 3 áreas: Ensambladora, Pintura y Eléctrica. El
presupuesto anual de la empresa se reparte de la siguiente manera:
Área Presupuesto
Ensambladora 37%
Pintura 42%
Eléctrica 21%
Obtener la cantidad de dinero que recibirá cada área para un monto presupuestal que se
ingresa.*/
#include<stdio.h>
#include<conio.h>
#define ENSAMBLADORA 0.37
#define PINTURA 0.42
#define ELECTRICA 0.21

int main()
{
    float presup,presupEnsamb,presupPint,presupElec;
    scanf("%f",&presup);
    presupEnsamb=presup*ENSAMBLADORA;
    presupPint=presup*PINTURA;
    presupElec=presup*ELECTRICA;
    printf("El presupuesto para la ensambladora es %f.\nEl presupuesto para pintura es %f.\nEl presupuesto para electricidad es %f.",presupEnsamb,presupPint,presupElec);
    getch();
}