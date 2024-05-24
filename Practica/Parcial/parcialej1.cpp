#include<iostream>
using namespace std;
#define MAX 3
void ingresoDatos(int[]);
int mayor(int[]);
int menor(int[]);
float prom(int[]);

int main()
{
    int notas[MAX];
    ingresoDatos(notas);
    cout<<"La mayor nota es: "<<mayor(notas)<<endl<<"La menor nota es: "<<menor(notas)<<endl<<"El promedio de todas las notas es: "<<prom(notas);
    return 0;
}

void ingresoDatos(int notas[])
{
    cout<<"Ingrese notas"<<endl;
    for(int i=0;i<MAX;i++)
    {
        cin>>notas[i];
    }
}

int mayor(int notas[])
{
    bool prim=true;
    int mayor=0;
    for(int i=0;i<MAX;i++)
    {
        if(prim==true)
        {
            prim=!prim;
            mayor=notas[i];
        } 
        if(notas[i]>mayor) mayor=notas[i];
    }
    return mayor;
}

int menor(int notas[])
{
    bool prim=true;
    int men=0;
    for(int i=0;i<MAX;i++)
    {
        if(prim==true)
        {
            prim=!prim;
            men=notas[i];
        } 
        if(notas[i]<men) men=notas[i];
    }
    return men;
}

float prom(int notas[])
{
    float promedio=0;
    for(int i=0;i<MAX;i++)
    {
        promedio+=notas[i];
    }
    promedio/=MAX;
    return promedio;
}