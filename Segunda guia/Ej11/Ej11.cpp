/*Un negocio vende distintos artículos identificados por un código, según se muestra:
.código 1; 10 ; 100: l0 pesos la unidad
.código 2; 22; 222: 7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
.código 3; 33: 3 pesos la unidad. Si la compra es por más de 10 unidades se hace un
descuento del 10% sobre el total.
.código 4; 44: 2 peso la unidad.
Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a
comprar y se informe el importe de la compra:
ARTÍCULO xxxxx CANTIDAD xxxx IMPORTE A PAGAR $ xxxx.xx*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int codigo,cant,dec,un;
    float precio;
    printf("Ingrese el codigo y cantidad\n");
    scanf("%d %d",&codigo,&cant);
    switch (codigo)
    {
    case 1:
    case 10:
    case 100:
        precio=10*cant;
        break;
    
    case 2:
    case 22:
    case 222:
        dec=cant/10;
        un=cant%10;
        if(cant>10)
        {
            precio=dec*65;
            precio=precio+(7*un);
        }
        else precio=cant*7;
        break;

    case 3:
    case 33:
        precio=3*cant;
        if(cant%10==0) precio=precio*0.90;
        break;

    case 4:
    case 44:
        precio=2*cant;
        break;
    }
    printf("ARTICULO: %d CANTIDAD: %d IMPORTE A PAGAR: $%f",codigo,cant,precio);
    getch();
}