/*Se tiene el archivo “Medicamentos.dat” con un registro por cada medicamento existente
en una farmacia. Cada registro tiene código, nombre, stock y precio unitario. Hacer un
programa que informe los medicamentos con stock menor a 5 y el stock valorizado.*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct medicamentos
{
    string nombre;
    int codigo;
    int stock;
    int precio;
};

int main()
{
    FILE *f;
    f=fopen("Medicamentos.dat","rb");
    if(f==NULL) cout<<"Error"<<endl;
    else
    {
        medicamentos med;
        fread(&med,sizeof(medicamentos),1,f);
        while(!feof(f))
        {
            if(med.stock<5)
            {
                cout<<med.nombre<<endl;
                cout<<med.stock<<endl;
                cout<<med.precio<<endl;
                cout<<med.codigo<<endl;
                fread(&med,sizeof(medicamentos),1,f);
            }
            else
            {
                fread(&med,sizeof(medicamentos),1,f);
            }
        }
        fclose(f);
    }
    return 0;
}