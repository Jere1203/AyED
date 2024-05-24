/*La ciudad de Buenos Aires requiere un estudio estadístico de infracciones
realizadas por los vehículos en sus calles. Para ello cuenta con un archivo de
infracciones “Infracciones.dat”, ordenado por fecha de la infracción creciente, con
el siguiente diseño:
Patente (7 caracteres)
Fecha de Infracción (int, aammdd)
Código de infracción (int, 1 a 100)*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct infracciones
{
    char patente[7];
    int fecha,codInfra;
};

int main()
{
    FILE *archInfra;
    infracciones inf;
    archInfra=fopen("Infracciones.dat","wb");
    cout<<"CODIGO: "<<endl;
    cin>>inf.codInfra;
    while(inf.codInfra!=0)
    {
        cout<<"PATENTE: "<<endl;
        cin>>inf.patente;
        cout<<"FECHA (DD/MM/AA): "<<endl;
        cin>>inf.fecha;
        fwrite(&inf,sizeof(infracciones),1,archInfra);
        cout<<"CODIGO: "<<endl;
        cin>>inf.codInfra;
    }
    fclose(archInfra);
}