/*“Especialidades.dat”, ordenado con cada una de las 10 especialidades que en la
clínica se atiende en consultorios externos. Cada registro tiene:
código de especialidad (1001 a 1010)
nombre de la especialidad (30 caracteres)
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct especialidad
{
    int codesp;
    char nomesp [30];
};


int main()
{
    FILE *arch1;
    arch1=fopen("Especialidades.dat","wb");

    especialidad esp;

   cout<<"Ingrese codigo de especialidad(0 para terminar)";
   cin>>esp.codesp;

   while (esp.codesp != 0)
   {

    cout<<"Ingrese nombre de la especialidad";
    cin>>esp.nomesp;

    fwrite(&esp,sizeof(especialidad),1,arch1);

    cout<<"Ingrese codigo de especialidad(0 para terminar)";
    cin>>esp.codesp;
   }

    fclose(arch1);

    return 0;
}