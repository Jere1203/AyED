/*Una fábrica de calzados elabora 7 modelos en 5 colores diferentes. Se ingresan los datos de las
ventas, para finalizar se ingresa nro. de modelo 0
Nro. modelo (1..7) Color (1..5) Cantidad vendida
Se pide emitir un listado que informe:
a) Totales de cada uno de los modelos y por cada uno de los colores
b) Totales por cada modelo
c) Totales por cada color
d) Total general*/
#include<iostream>
#include<conio.h>
using namespace std;
void cargarMat(int [7][5],int,int);
void mostrarMat(int [7][5],int maxF,int maxC);
int sumCalz(int calz[7][5],int maxF,int maxC);
int main()
{
    int calzado[7][5] {0,0,0,0,0,
                       0,0,0,0,0,
                       0,0,0,0,0,
                       0,0,0,0,0,
                       0,0,0,0,0,
                       0,0,0,0,0,
                       0,0,0,0,0};
    cargarMat(calzado,7,5);
    mostrarMat(calzado,7,5);
    cout<<"En total se vendieron: "<<sumCalz(calzado,7,5)<<" calzados"<<endl;
    getch();
}

void cargarMat(int calzado[7][5],int maxF,int maxC)
{
    int i,j;
    cout<<"Ingrese modelo (1 al 7)"<<endl;
    cin>>i;
    while(i!=0&&i<=maxF)
    {
        cout<<"Ingrese color (1 al 5)"<<endl;
        cin>>j;
        while(j>maxC)
        {
            cout<<"Fuera de rango"<<endl;
            cin>>j;
        }
        calzado[i-1][j-1]++;
        cout<<"Ingrese modelo (1 al 7)"<<endl;
        cin>>i;
    }
}

void mostrarMat(int calzado[7][5],int maxF,int maxC)
{
    int sumFil[7]{0,0,0,0,0,0,0},i,j,sumCol[5]{0,0,0,0,0};
    for(i=0;i<maxF;i++)
    {
        cout<<"Modelo "<<i+1<<" ";
        for(j=0;j<maxC;j++)
        {
            cout<<"Color "<<j+1<<": "<<calzado[i][j]<<" ";
            if(calzado[i][j]!=0)sumFil[i]+=calzado[i][j];
            if(calzado[i][j]!=0)sumCol[j]+=calzado[i][j];
        }
        cout<<endl;
    }
    for(i=0;i<maxF;i++)
    {
        cout<<"Modelo "<<i+1<<": "<<sumFil[i]<<" unidades vendidas"<<endl;
    }
    for(i=0;i<maxC;i++)
    {
        cout<<"Color "<<i+1<<": "<<sumCol[i]<<" unidades vendidas"<<endl;
    }
}

int sumCalz(int calz[7][5],int maxF,int maxC)
{
    int sum=0;
    for(int i=0;i<maxF;i++)
    {
        for(int j=0;j<maxC;j++)
        {
            sum+=calz[i][j];
        }
    }
    return sum;
}