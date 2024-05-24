//número de matrícula del médico (entero)
//nombre (30 caracteres)
//código de especialidad (1001 a 1010)*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct medico
{
    int nromatricula,codespacialidad;
    char nombre [30];
};

int main()
{

    FILE *arch;
    arch=fopen("Medicos.dat","wb");

    medico med;

    int cont=0;

    cout<<"Ingrese numero de matricula";
    cin>>med.nromatricula;

    while(med.nromatricula != 0 && cont!= 100)
    {
        cout<<"Ingrese nombre y apellido del medico";
        cin.ignore();
        cin.getline(med.nombre,30);

        cout<<"Ingrese codigo de especialidad";
        cin>>med.codespacialidad;

        fwrite(&med,sizeof(medico),1,arch);

        cont++;

        cout<<"Ingrese numero de matricula";
        cin>>med.nromatricula;
    }

    fclose(arch);

    return 0;
}