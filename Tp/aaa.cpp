#include<iostream>
#include<stdio.h>
using namespace std;
struct repartidores{
    int dni;
    char nombreYapellido[34]; 
    char patente[34]; 
    int codZona; 
    int transporte; 
}; 

int main()
{
    repartidores rep;
    FILE *f;
    f=fopen("rep_motos.dat","rb");
    if(f==NULL) cout<<"ERROR"<<endl;
    fread(&rep,sizeof(repartidores),1,f);
    cout<<rep.codZona<<" "<<rep.dni<<" ";
    cout<<fgets(rep.nombreYapellido,34,f);
    cout<<" "<<rep.patente<<" "<<rep.transporte<<endl;
    fclose(f);
    return 0;
}