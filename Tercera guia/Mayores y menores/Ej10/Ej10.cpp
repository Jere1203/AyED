/*Una compañía aérea desea emitir un listado con los movimientos mensuales de sus M vuelos al
exterior.
Para ello cuenta con la siguiente información:
De cada vuelo realizado el número de vuelo, destino, y cantidad de asientos.
De cada pasajero el número de pasaporte y el importe que abonó por el pasaje en dólares.
La información de los pasajeros de cada vuelo finaliza con un número de pasaporte igual a cero.
Se pide emitir el siguiente listado:
Nro. de Vuelo .......... Destino: ...........
Nro. de Pasaporte Importe en u$s
............. .............
............. .............
Total recaudado del vuelo: .........
Cantidad de asientos libres: .........
Número de vuelo que más recaudó: ........*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int num=1,cantAs=0,pas=1,importe=0,i=0,totRec=0,mayRec=0,asLibres=0,cantPas=0,numMayRec;
    char destino[10];
    bool prim=true;
    while(num!=0)
    {
        printf("\nIngrese numero de vuelo\n");
        scanf("%d",&num);
        if(num==0) break;
        if(prim==true)
        {
            mayRec=totRec;
            numMayRec=num;
        }
        printf("Ingrese destino\n");
        scanf("%s",&destino);
        printf("Ingrese cantidad de asientos\n");
        scanf("%d",&cantAs);
        for(i=0;i<cantAs;i++)
        {
            printf("\nIngrese numero de pasaporte\n");
            scanf("%d",&pas);
            if(pas==0) break;
            printf("Ingrese importe abonado\n");
            scanf("%d",&importe);
            totRec+=importe;
            cantPas++;
            printf("\nNumero de vuelo: %d\tDestino: %s\nNro de pasaporte: %d\tImporte (en dolares): %d\n",num,destino,pas,importe);
        }
        if(totRec>mayRec)
        {
            numMayRec=num;
        } 
        asLibres=cantAs-cantPas;
        printf("\nTotal recaudado: %d\nCantidad de asientos libres: %d\nVuelo que mas recaudo: %d\n",totRec,asLibres,numMayRec);
        totRec=0;
        cantPas=0;
    }
    getch();    
}