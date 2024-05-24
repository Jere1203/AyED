/*Dado un número entero positivo entre 1 y 3999 informar su correspondiente número Romano.*/
#include<stdio.h>
#include<conio.h>
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

int main()
{
    unsigned int nro;
    int miles,centena,decena,unidad,i;
    printf("Ingrese un numero entero positivo\n");
    scanf("%d",&nro);
    miles=nro/1000;
    centena=(nro/100)-(miles*10);
    decena=(nro/10)-((centena*10)+miles*100);
    unidad=nro%10;

    for(i=0;i<miles;i++)
    {
        printf("M");
    }
    switch (centena)
    {
        case 1:
        case 2:
        case 3:
            for(i=0;i<centena;i++)
            {
                printf("C");
            }
            break;
        
        case 4:
            for(i=0;i<1;i++)
            {
                printf("CD");
            }
        
        case 5:
            printf("D");
            break;
        
        case 6:
        case 7:
        case 8:
            printf("D");
            for(i=5;i<centena;i++)
            {
                printf("C");
            }
        break;
        
        case 9:
            printf("CM");
        break;
    }
    
    switch (decena)
    {
        case 1:
        case 2:
        case 3:
            for(i=0;i<decena;i++)
            {
                printf("X");
            }
            break;
        case 4:
            printf("XL");
            break;
        case 5:
            printf("L");
            break;
        case 6:
        case 7:
        case 8:
        
            printf("L");
            for(i=5;i<decena;i++)
            {
                printf("X");
            }
            break;

        case 9:
            printf("XC");
            break;
    }

    switch (unidad)
    {
        case 1:
        case 2:
        case 3:
            for(i=0;i<unidad;i++)
            {
                printf("I");
            }
            break;

        case 4:
            printf("IV");
            break;

        case 5:
            printf("V");
            break;

        case 6:
        case 7:
        case 8:
            printf("V");
            for(i=5;i<unidad;i++)
            {
                printf("I");
            }
            break;
        case 9:
            printf("IX");
            break;
    }
    getch();
}