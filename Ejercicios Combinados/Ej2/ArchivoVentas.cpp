/*Dado el archivo VENTAS.DAT, ordenado por número de factura, con la siguiente
estructura de registro:
Número de factura (int)
Código de vendedor (int)
Importe (float)*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct ArchivoVentas
{
    int factura, codVend;
    float importe;
};

int main()
{
    FILE *aVentas;
    ArchivoVentas vent;
    aVentas=fopen("Ventas.dat","wb");
    cout<<"NUM FACTURA: "<<endl;
    cin>>vent.factura;
    while(vent.factura!=0)
    {
        cout<<"CODIGO: "<<endl;
        cin>>vent.codVend;
        cout<<"IMPORTE: "<<endl;
        cin>>vent.importe;
        fwrite(&vent,sizeof(ArchivoVentas),1,aVentas);
        cout<<"NUM FACTURA: "<<endl;
        cin>>vent.factura;
    }
    fclose(aVentas);
    getch();
}