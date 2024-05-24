/*“Consultas.dat”, con un registro por cada consulta realizada en consultorios externos
el año pasado, ordenado por número de historia clínica. Cada registro tiene:
día
mes
número de historia clínica del paciente (entero)
número de matrícula del médico que realizó la consulta (entero)
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct consultas
{
    int dia,mes,nrohistpac,nromatmed;
};

int main()
{
    FILE *arch2;
    arch2=fopen("Consultas.dat","wb");

    consultas con;

    cout<<"Ingrese dia de la consulta(0 para finalizar): ";
    cin>>con.dia;

    while(con.dia != 0)
    {
        cout<<"Mes de la consulta: ";
        cin>>con.mes;
        cout<<"Numero de historia clinica del paciente: ";
        cin>>con.nrohistpac;
        cout<<"Ingrese numero de matricula del medio que realizo la consulta: ";
        cin>>con.nromatmed;

        fwrite (&con,sizeof(consultas),1,arch2);

        cout<<"Ingrese dia de la consulta(0 para finalizar): ";
        cin>>con.dia;

    }
    fclose(arch2);
}