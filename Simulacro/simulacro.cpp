#include<iostream>
#include<conio.h>
#include<string.h>
#define MAX 2
using namespace std;
int cuadrante(int,int);
int puntaje(int);

int main()
{
    char nombre[10],flag='s',mayorNom[10];
    int x,y,i,cualCuadrante[MAX],puntos=0,cont_centro=0,mayorPunt=0,cantEjex=0,cantEjey=0;
    bool prim=true;
    while(flag=='s'||flag=='S')
    {
        cout<<"Ingrese nombre del participante\n";
        cin>>nombre;
        cout<<"Ingrese coordenadas x e y de cada disparo\n";
        for(i=0;i<MAX;i++)
        {
            cin>>x>>y;
            if(x==0&&y==0)cont_centro++;
            cualCuadrante[i]=cuadrante(x,y);
            if(cualCuadrante[i]==1 || cualCuadrante[i]==2) cantEjex++;
            if(cualCuadrante[i]==1 || cualCuadrante[i]==4) cantEjey++;
        }
        for(i=0;i<MAX;i++)
        {
            puntos+=puntaje(cualCuadrante[i]);
        }
        if(prim==true)
        {
            mayorPunt=puntos;
            strcpy(mayorNom,nombre);
            prim=false;
        }
        if(puntos>mayorPunt)
        {
            mayorPunt=puntos;
            strcpy(mayorNom,nombre);
        }
        cout<<"Participante: "<<nombre<<"\nPuntaje: "<<puntos;
        cout<<"\nHay mas participantes?\n";
        cin>>flag;
        puntos=0;
    }
    cout<<"Se realizaron "<<cont_centro<<" disparos en el centro\n";
    cout<<"El participante ganador fue "<<mayorNom<<" con "<<mayorPunt<<" puntos\n";
    cout<<"Se realizaron "<<cantEjex<<" disparos sobre el eje x y "<<cantEjey<<" disparos sobre el eje y\n";
    getch();
}

int cuadrante(int x,int y)
{
    if(x==0 && y==0) return 0;
    if(x>0)
    {
        if(y>0) return 1;
        else return 4;
    }
    else 
    if(y>0) return 2;
    if(y<0) return 3;
}

int puntaje(int cuad)
{
    int puntos=0;
    switch (cuad)
    {
    case 0:
        puntos+=100;
        break;
    case 1:
    case 2:
        puntos+=50;
        break;
    
    case 3:
    case 4:
        puntos+=40;
        break;
    }
    return puntos;
}