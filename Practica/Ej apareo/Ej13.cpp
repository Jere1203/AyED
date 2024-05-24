/*/*Se tiene un vector de notas (cada elemento tiene nombre del alumnos y nota obtenida)
correspondientes al primer parcial y otro vector del mismo tipo del anterior con las notas
correspondientes al segundo parcial, ambos vectores están ordenados alfabéticamente por nombre.
Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno en la
materia, según lo siguiente:
- Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
- Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
- Primer o segundo parcial con nota menor a 6: RECURSA*/
#include<iostream>
using namespace std;
#define MAX 2
struct parcial
{
    string nombre;
    int nota;
};
void ingresoDatos(parcial[]);
parcial ingresoNotas();
void apareo(parcial[],parcial[]);
int main()
{
    parcial primer[MAX];
    parcial segundo[MAX];
    ingresoDatos(primer);
    ingresoDatos(segundo);
    apareo(primer,segundo);
    return 0;
}

void ingresoDatos(parcial prim[])
{
    for(int i=0;i<MAX;i++)
    {
        prim[i]=ingresoNotas();
    }
}

parcial ingresoNotas()
{
    parcial p1;
    cout<<"Ingrese nombre"<<endl;
    cin>>p1.nombre;
    cout<<"Ingrese nota"<<endl;
    cin>>p1.nota;
    return p1;
}

void apareo(parcial p1[],parcial p2[])
{
    int i,j,k;
    while(i<MAX && j<MAX)
    {
        if(p1[i].nombre==p2[i].nombre)
        {
            if(p1[i].nota>=8 && p2[j].nota>=8) cout<<"Condicion: PROMOCION"<<endl;
            else
            {
                if(p1[i].nota>=6&&p2[j].nota>=6) cout<<"Condicion: RINDE FINAL"<<endl;
                if(p1[i].nota<6&&p2[j].nota<6) cout<<"Condicion: RECURSA"<<endl;
            }
            i++;
            j++;
        }
        else
        if(p1[i].nombre<p2[j].nombre)
        {
            cout<<"Condicion: RECURSA"<<endl;
            i++;
        } 
        else 
        cout<<"Condicion: RECURSA"<<endl;
    }
    for(k=i;k<MAX;k++)
    {
        cout<<"Alumno "<<p1[k].nombre<<" RECURSA"<<endl;
    }
    for(k=j;k<MAX;k++)
    {
        cout<<"Alumno "<<p2[k].nombre<<" RECURSA"<<endl;
    }
}