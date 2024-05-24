#include<iostream>
#include<conio.h>

using namespace std;
int cuadrante(int,int);
int puntaje(int);
int mayor(int[],int);

int main()
{
    char nombre[10],flag;
    int x[5],y[5],maxPart,i,j,mayPunt,contCent=0,contX=0,contY=0;
    cout<<"Ingrese cantidad de participantes\n";
    cin>>maxPart;
    string part[maxPart];
    int puntaje[maxPart];
    for(i=0;i<maxPart;i++)
    {
        puntaje[i]=0;
    }
    for(i=0;i<maxPart;i++)
    {
        cout<<"Ingrese nombre del participante\n";
        cin>>nombre;
        part[i]=nombre;
        for(j=0;j<5;j++)
        {
            cout<<"Ingrese coord. x del tiro\n";
            cin>>x[j];
            cout<<"Ingrese coord. y del tiro\n";
            cin>>y[j];
            if(x[j]==0&&y[j]==0) contCent++;
            if(x[j]==0) contX++;
            if(y[j]==0) contY++;
            puntaje[i]+=cuadrante(x[j],y[j]);
        }
        cout<<"Hay mas participantes?\n";
        cin>>flag;
        if(flag=='N'||flag=='n') break;
    }
    for(i=0;i<maxPart;i++)
    {
        cout<<"\nParticipante: "<<part[i]<<"\nPuntaje: "<<puntaje[i];
    }
    mayPunt=mayor(puntaje,maxPart);
    cout<<"\nEl ganador es: "<<part[mayPunt]<<" con "<<puntaje[mayPunt]<<" puntos.\n";
    cout<<"Hubieron "<<contCent<<" tiros al centro, "<<contX<<" tiros sobre el eje X y "<<contY<<" sobre el eje Y.\n";
    getch();
}

int cuadrante(int x,int y)
{
    int cualCuad,punt;
    punt=0;
    if(x==0&&y==0)cualCuad=0;
    if(x>0)
    {
        if(y>0) cualCuad=1;
        if(y<0) cualCuad=4;
    }
    if(x<0)
    {
        if(y>0)cualCuad=2;
        if(y<0)cualCuad=3;
    }
    punt=puntaje(cualCuad);
    return punt;
}

int puntaje(int cuad)
{
    int punt;
    punt=0;
    switch (cuad)
    {
    case 1:
    case 2:
        punt+=50;
        break;
    case 3:
    case 4:
        punt+=40;
        break;
    case 0:
        punt+=100;
        break;
    }
    return punt;
}

int mayor(int puntaje[],int part)
{
    int mayorPunt=0;
    int i;
    for(i=0;i<part;i++)
    {
        if(puntaje[i]>mayorPunt) mayorPunt=i;
    }
    return mayorPunt;
}