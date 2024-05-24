/*Se tiene el archivo “Medicamentos.dat” con un registro por cada medicamento existente
en una farmacia. Cada registro tiene código, nombre, stock y precio unitario. Hacer un
programa que informe los medicamentos con stock menor a 5 y el stock valorizado.*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct medicamento
{
    string nombre;
    int codigo;
    int stock;
    int precio;
};

int main()
{
    medicamento med;
    med.nombre="Ibuprofeno";
    med.codigo=123456;
    med.stock=4;
    med.precio=2000;
    FILE *f;
    f=fopen("Medicamentos.dat","wb");
    if(f==NULL) cout<<"No se pudo abrir el archivo"<<endl;
    else
    {
        fwrite(&med,sizeof(medicamento),1,f);
        fclose(f);
    }
    return 0;
}