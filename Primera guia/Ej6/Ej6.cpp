/*Dado el radio de un círculo, informar el diámetro, el perímetro y la superficie del mismo.*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159265359

int main()
{
    float radio,perimetro,superficie,diametro;
    scanf("%f",&radio);
    diametro=2*radio;
    perimetro=2*PI*radio;
    superficie=PI*pow(radio,2);
    printf("El circulo de radio %f tiene como diametro %f, perimetro %f y superficie %f",radio,diametro,perimetro,superficie);
    getch();
}